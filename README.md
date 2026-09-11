Screenshots from MQTT Explorer
<img width="1904" height="885" alt="Screenshot From 2026-09-11 20-17-57" src="https://github.com/user-attachments/assets/90c6531b-fc7b-4a91-a77f-98027139c74c" />
<img width="1904" height="885" alt="Screenshot From 2026-09-11 20-18-06" src="https://github.com/user-attachments/assets/d18d589e-0810-49c1-b132-53aa80e86bf1" />


**Serial output**:

**A board**
Старт
Connecting to Wifi
.. OK
WiFi IP: 10.13.37.2
[MQTT] Підключаємось до broker.hivemq.com...OK

Button was pressed
[MQTT] OK[MQTT] Публікуємо: {"temperature": 24.0, "humidity": 40.0}
[MQTT] OK[MQTT] Публікуємо: {"temperature": 60.2, "humidity": 7.0}
[MQTT] OK[MQTT] Публікуємо: {"temperature": 20.1, "humidity": 7.0}
[MQTT] OK[MQTT] Публікуємо: {"temperature": 8.3, "humidity": 7.0}
[MQTT] OK[MQTT] Публікуємо: {"temperature": 8.3, "humidity": 7.0}
[MQTT] OK[MQTT] Публікуємо: {"temperature": 8.3, "humidity": 7.0}
[MQTT] OK[MQTT] Публікуємо: {"temperature": 8.3, "humidity": 7.0}
[MQTT] OK[MQTT] Публікуємо: {"temperature": 8.3, "humidity": 7.0}
[MQTT] OK[MQTT] Публікуємо: {"temperature": 8.3, "humidity": 7.0}
[MQTT] OK[MQTT] Публікуємо: {"temperature": 8.3, "humidity": 7.0}
[MQTT] OK[MQTT] Публікуємо: {"temperature": 8.3, "humidity": 7.0}
[MQTT] OK
         Button was pressed
[MQTT] OK
         Button was pressed
[MQTT] OK

**B board**
Старт
Connecting to Wifi
. OK
WiFi IP: 10.13.37.2
[MQTT] Підключаємось до broker.hivemq.com...OK
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/sensors
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/commands
[MQTT] Топік: iot_course/Ruslan_Chernyi/commands
[MQTT] Payload: "manual_read"
Manual trigger received[MQTT] Топік: iot_course/Ruslan_Chernyi/sensors
[MQTT] Payload: {"temperature": 24.0, "humidity": 40.0}
[MQTT] Температура: 24.00
[MQTT] Вологість: 40.00
[LED] Без змін - Температура в нормі
[MQTT] З'єднання втрачено - перепідключаємось...
[MQTT] Підключаємось до broker.hivemq.com...OK
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/sensors
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/commands
[MQTT] Топік: iot_course/Ruslan_Chernyi/sensors
[MQTT] Payload: {"temperature": 60.2, "humidity": 7.0}
[MQTT] Температура: 60.20
[MQTT] Вологість: 7.00
[LED] ON - Температура вище 26°C
[MQTT] З'єднання втрачено - перепідключаємось...
[MQTT] Підключаємось до broker.hivemq.com...OK
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/sensors
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/commands
[MQTT] Топік: iot_course/Ruslan_Chernyi/sensors
[MQTT] Payload: {"temperature": 20.1, "humidity": 7.0}
[MQTT] Температура: 20.10
[MQTT] Вологість: 7.00
[LED] Без змін - Температура в нормі
[MQTT] Топік: iot_course/Ruslan_Chernyi/sensors
[MQTT] Payload: {"temperature": 8.3, "humidity": 7.0}
[MQTT] Температура: 8.30
[MQTT] Вологість: 7.00
[LED] OFF - Температура нижче 20°C
[MQTT] З'єднання втрачено - перепідключаємось...
[MQTT] Підключаємось до broker.hivemq.com...OK
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/sensors
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/commands
[MQTT] Топік: iot_course/Ruslan_Chernyi/sensors
[MQTT] Payload: {"temperature": 8.3, "humidity": 7.0}
[MQTT] Температура: 8.30
[MQTT] Вологість: 7.00
[LED] OFF - Температура нижче 20°C
[MQTT] З'єднання втрачено - перепідключаємось...
[MQTT] Підключаємось до broker.hivemq.com...OK
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/sensors
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/commands
[MQTT] Топік: iot_course/Ruslan_Chernyi/sensors
[MQTT] Payload: {"temperature": 8.3, "humidity": 7.0}
[MQTT] Температура: 8.30
[MQTT] Вологість: 7.00
[LED] OFF - Температура нижче 20°C
[MQTT] З'єднання втрачено - перепідключаємось...
[MQTT] Підключаємось до broker.hivemq.com...OK
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/sensors
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/commands
[MQTT] Топік: iot_course/Ruslan_Chernyi/sensors
[MQTT] Payload: {"temperature": 8.3, "humidity": 7.0}
[MQTT] Температура: 8.30
[MQTT] Вологість: 7.00
[LED] OFF - Температура нижче 20°C
[MQTT] Топік: iot_course/Ruslan_Chernyi/sensors
[MQTT] Payload: {"temperature": 8.3, "humidity": 7.0}
[MQTT] Температура: 8.30
[MQTT] Вологість: 7.00
[LED] OFF - Температура нижче 20°C
[MQTT] З'єднання втрачено - перепідключаємось...
[MQTT] Підключаємось до broker.hivemq.com...OK
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/sensors
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/commands
[MQTT] Топік: iot_course/Ruslan_Chernyi/sensors
[MQTT] Payload: {"temperature": 8.3, "humidity": 7.0}
[MQTT] Температура: 8.30
[MQTT] Вологість: 7.00
[LED] OFF - Температура нижче 20°C
[MQTT] З'єднання втрачено - перепідключаємось...
[MQTT] Підключаємось до broker.hivemq.com...OK
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/sensors
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/commands
[MQTT] Топік: iot_course/Ruslan_Chernyi/sensors
[MQTT] Payload: {"temperature": 8.3, "humidity": 7.0}
[MQTT] Температура: 8.30
[MQTT] Вологість: 7.00
[LED] OFF - Температура нижче 20°C
[MQTT] З'єднання втрачено - перепідключаємось...
[MQTT] Підключаємось до broker.hivemq.com...OK
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/sensors
[MQTT] Підписатись на: iot_course/Ruslan_Chernyi/commands
[MQTT] Топік: iot_course/Ruslan_Chernyi/sensors
[MQTT] Payload: {"temperature": 8.3, "humidity": 7.0}
[MQTT] Температура: 8.30
[MQTT] Вологість: 7.00
[LED] OFF - Температура нижче 20°C
[MQTT] Топік: iot_course/Ruslan_Chernyi/commands
[MQTT] Payload: "manual_read"
Manual trigger received[MQTT] Топік: iot_course/Ruslan_Chernyi/commands
[MQTT] Payload: "manual_read"
Manual trigger received
