#include <Arduino.h>
#include "wifi_man.h"
#ifdef ARDUINO_M5Stack_Core_ESP32
#include <M5Stack.h>
#endif
#include <ESPAsync_WiFiManager.h> //https://github.com/khoih-prog/ESPAsync_WiFiManager

#if !(USING_ESP32_S2 || USING_ESP32_C3)
DNSServer dnsServer;
#endif

AsyncWebServer webServer(80);

void connect_or_config()
{
#if (USING_ESP32_S2 || USING_ESP32_C3)
    ESPAsync_WiFiManager ESPAsync_wifiManager(&webServer, NULL, "Async_AutoConnect");
#else
    ESPAsync_WiFiManager ESPAsync_wifiManager(&webServer, &dnsServer, "Async_AutoConnect");
#endif
    // ESPAsync_wifiManager.resetSettings();   //reset saved settings
    ESPAsync_wifiManager.setAPStaticIPConfig(IPAddress(192, 168, 132, 1), IPAddress(192, 168, 132, 1), IPAddress(255, 255, 255, 0));
    ESPAsync_wifiManager.autoConnect("Peripage-SetMeUp");
    if (WiFi.status() == WL_CONNECTED)
    {
        Sprint(F("Connected. Local IP: "));
        Sprintln(WiFi.localIP());
    }
    else
    {
        Sprintln(ESPAsync_wifiManager.getStatus(WiFi.status()));
    }
};