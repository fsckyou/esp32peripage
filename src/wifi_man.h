#ifndef __WIFI_MAN_H__
#define __WIFI_MAN_H__

#ifdef ARDUINO_M5Stack_Core_ESP32
#define Sprint(a) (M5.Lcd.print(a))
#define Sprintln(a) (M5.Lcd.println(a))
#else
#define Sprint(a) (Serial.print(a))
#define Sprintln(a) (Serial.println(a))
#endif

void connect_or_config();
#endif