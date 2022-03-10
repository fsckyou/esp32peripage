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
#include <ArduinoWebsockets.h>
#include "fragments.h"

#define HOST "littleprinter.nordprojects.co"
#define URL "/api/v1/connection"
#define DEVICE_ADDR "f10f72c61eb3130a"

websockets::WebsocketsClient client;

void setup();
void loop();
void onMessageCallback(websockets::WebsocketsMessage);
void onEventsCallback(websockets::WebsocketsEvent, String);
#endif