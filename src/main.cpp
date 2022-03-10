#include "main.h"

// holds a random bridge address... the value doesn't seem to matter much.
uint64_t bridge_addr;
// holds the encryption key... but we don't use it?
String enc_key;

void setup()
{
#ifdef ARDUINO_M5Stack_Core_ESP32
    // This is M5 specific and important.
    M5.begin();
    M5.Power.begin();
#endif

    // Use Serial if not using an M5 Core.
    Serial.begin(9600);
    delay(200);

    connect_or_config();

    ///////////////////////////////////////////////////////////
    // Connected to wifi now
    ///////////////////////////////////////////////////////////

    // scan for a printer
    // connect the printer
    // set the power off timeout

    // run callback when messages are received
    client.onMessage(onMessageCallback);

    // run callback when events are occuring
    client.onEvent(onEventsCallback);

    // connect the websocket
    // server address, port and URL
    client.connect(HOST, 80, URL);

    // generate the 64 bit bridge address
    uint64_t upper_addr = esp_random();
    uint64_t lower_addr = esp_random();
    bridge_addr = upper_addr << 32 | lower_addr;
}

void loop()
{
    client.poll();
    delay(500);
}

void onMessageCallback(websockets::WebsocketsMessage message)
{
    Serial.print("Got Message: ");
    Serial.println(message.data());
}

void onEventsCallback(websockets::WebsocketsEvent event, String data)
{
    if (event == websockets::WebsocketsEvent::ConnectionOpened)
    {
        // Schedule heartbeat
    }
    else if (event == websockets::WebsocketsEvent::ConnectionClosed)
    {
        Serial.println("Connnection Closed");
    }
    else if (event == websockets::WebsocketsEvent::GotPing)
    {
        Serial.println("Got a Ping!");
    }
    else if (event == websockets::WebsocketsEvent::GotPong)
    {
        Serial.println("Got a Pong!");
    }
}

void sendHeartbeat()
{
    // if an encryption key isn't set, request one
    // otherwise, send a heartbeat
}