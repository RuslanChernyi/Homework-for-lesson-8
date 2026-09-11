#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>

/***    Defines   ***/

#define BUTTON_LOGIC_HIGH 0
#define BUTTON_LOGIC_LOW 1

// WIFI settings
#define WIFI_SSID     "Wokwi-GUEST"  // мережа Wokwi симулятора
#define WIFI_PASSWORD ""              // без пароля
#define WIFI_TIMEOUT  10000           // максимум 10 секунд на підключення

// MQTT settings
#define MQTT_BROKER "broker.hivemq.com"
#define MQTT_PORT 1883
#define MQTT_CLIENT_ID "esp32_B-Ruslan_Chernyi"
#define TOPIC_SENSORS "iot_course/Ruslan_Chernyi/sensors"
#define TOPIC_BUTTON "iot_course/Ruslan_Chernyi/commands"

// Timer intervals
#define PUBLISH_INTERVAL 10000
#define RECONNECT_INTERVAL 5000
#define DEBOUNCE_DELAY 30
#define MANUAL_PUBLISH_DELAY 200
#define BLINK_INTERVAL 500
#define BLINK_AMOUNT 3

//  Pin defines
#define LED_PIN 2

/***    Structs           ***/
typedef struct {
  float humidity;
  float temperature;
  uint8_t status;
} s_dhtData;

/***    Global variables    ***/
uint32_t lastReconectionAttempt = 0;
uint8_t reconectionAttempts = 0;
uint32_t lastPublish = 0;
uint8_t g_enableBlink = 0;

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

// put function declarations here:
bool connectWifi(void);
bool connectMqtt(void);
bool isWifiConnected(void);
void onMessage(char *topic, byte *payload, unsigned int length);
void toggleLed(uint32_t blink_interval);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.println("Старт");

  connectWifi();
  if (!isWifiConnected()) {
    Serial.print("Could not connect to WiFi");
    Serial.println("Reconnecting...");
    connectWifi();
  }

  mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
  mqttClient.setCallback(onMessage);
  mqttClient.setKeepAlive(60);
  mqttClient.setSocketTimeout(30);
  connectMqtt();
}

void loop() {

  if (mqttClient.connected()) {
    mqttClient.loop();

    uint32_t now = millis();
    reconectionAttempts = 0;
    if ((now - lastPublish) > PUBLISH_INTERVAL) {
      lastPublish = now;
    }
  } else {
    uint32_t now = millis();
    if ((now - lastReconectionAttempt) > RECONNECT_INTERVAL) {
      lastReconectionAttempt = now;
      reconectionAttempts++;
      if (reconectionAttempts >= 3) {
        Serial.println("[MQTT] Неможливо підключитись.");
      } else {
        Serial.println("[MQTT] З'єднання втрачено - перепідключаємось...");
        connectMqtt();
      }
    }
  }
  if(g_enableBlink){
    static uint8_t blink_count = BLINK_AMOUNT * 2;
    if (blink_count) {
      static uint32_t lastBlink = 0;
      uint32_t now = millis();
      if ((now - lastBlink) > BLINK_INTERVAL) {
        uint8_t pinState = digitalRead(LED_PIN);
        digitalWrite(LED_PIN, !pinState);
        lastBlink = now;
        blink_count--;
        if (blink_count <= 0) {
          g_enableBlink = 0;
          blink_count = BLINK_AMOUNT * 2;
        }
      }
    }
  }
}

bool connectWifi() {
  Serial.println("Connecting to Wifi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, 6);

  uint32_t start = millis();
  while (WiFi.status() != WL_CONNECTED) {
    if (millis() - start > WIFI_TIMEOUT) {
      Serial.println("timeout");
      return false;
    }
    delay(500);
    Serial.print(".");
  }

  Serial.println(" OK");
  Serial.print("WiFi IP: ");
  Serial.println(WiFi.localIP());
  return true;
}

bool connectMqtt() {
  Serial.print("[MQTT] Підключаємось до ");
  Serial.print(MQTT_BROKER);
  Serial.print("...");

  if (mqttClient.connect(MQTT_CLIENT_ID)) {
    Serial.println("OK");
    mqttClient.subscribe(TOPIC_SENSORS, 1);
    mqttClient.subscribe(TOPIC_BUTTON, 1);
    Serial.print("[MQTT] Підписатись на: ");
    Serial.println(TOPIC_SENSORS);
    Serial.print("[MQTT] Підписатись на: ");
    Serial.println(TOPIC_BUTTON);
    return true;
  }

  Serial.print("Помилка: ");
  Serial.println(mqttClient.state());
  return false;
}

void onMessage(char *topic, byte *payload, unsigned int length) {
  char message[length + 1];
  memcpy(message, payload, length);
  message[length] = '\0';

  Serial.print("[MQTT] Топік: ");
  Serial.println(topic);
  Serial.print("[MQTT] Payload: ");
  Serial.println(message);

  if (strncmp(topic, TOPIC_BUTTON, strlen((const char *)TOPIC_BUTTON)) == 0) {
    char *manButtonPtr = strstr(message, "\"manual_read\"");
    if (manButtonPtr == NULL) {
      Serial.println("[MQTT] Не можу розпізнати топік");
      return;
    }
    Serial.print("Manual trigger received");
    g_enableBlink = 1;
} else if (strncmp(topic, TOPIC_SENSORS, strlen((const char *)TOPIC_SENSORS)) == 0) {
    char *tempPtr = strstr(message, "\"temperature\":");
    if (tempPtr == NULL) {
      Serial.println("[MQTT] Температура не знайдена");
      return;
    }
    float temperature = atof(tempPtr + strlen("\"temperature\":"));
    Serial.print("[MQTT] Температура: ");
    Serial.println(temperature);

    char *humPtr = strstr(message, "\"humidity\":");
    if (humPtr == NULL){
      Serial.println("[MQTT] Вологість не знайдена");
      return;
    }
    float humidity = atof(humPtr + strlen("\"humidity\":"));
    Serial.print("[MQTT] Вологість: ");
    Serial.println(humidity);


    if (temperature > 26.0) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("[LED] ON - Температура вище 26°C");
    } else if (temperature < 20.0) {
      digitalWrite(LED_PIN, LOW);
      Serial.println("[LED] OFF - Температура нижче 20°C");
    } else {
      Serial.println("[LED] Без змін - Температура в нормі");
    }
  }
}

void toggleLed(uint32_t blink_interval)
{
  static uint32_t lastBlink = 0;
  uint32_t now = millis();
  if ((now - lastBlink) > blink_interval) {
    uint8_t pinState = digitalRead(LED_PIN);
    digitalWrite(LED_PIN, !pinState);
    lastBlink = now;
  }
}

bool isWifiConnected() { return WiFi.status() == WL_CONNECTED; }