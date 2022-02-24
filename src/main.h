#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef ARDUINO_M5Stack_Core_ESP32
#define Sprint(a) (M5.Lcd.print(a))
#define Sprintln(a) (M5.Lcd.println(a))
#else
#define Sprint(a) (Serial.print(a))
#define Sprintln(a) (Serial.println(a))
#endif

#include <Arduino.h>
#include <wifi_man.h>
#include <Thermal_Printer.h>
#ifdef ARDUINO_M5Stack_Core_ESP32
#include <M5Stack.h>
#endif
#include <SocketIOclient.h>

#define HOST "littleprinter.nordprojects.co"
#define URL "/api/v1/connection"

SocketIOclient socketIO;

void setup();
void loop();
void webSocketEvent(WStype_t, uint8_t *, size_t);

#endif