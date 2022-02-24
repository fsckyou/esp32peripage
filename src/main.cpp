#include "main.h"

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
  
  // connect the websocket
 // server address, port and URL
    socketIO.begin(HOST,80,URL);

    // event handler
    socketIO.onEvent(socketIOEvent);

void loop()
{
  webSocket.loop();
}

void socketIOEvent(socketIOmessageType_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case sIOtype_DISCONNECT:
            USE_SERIAL.printf("[IOc] Disconnected!\n");
            break;
        case sIOtype_CONNECT:
            USE_SERIAL.printf("[IOc] Connected to url: %s\n", payload);

            // join default namespace (no auto join in Socket.IO V3)
            socketIO.send(sIOtype_CONNECT, "/");
            break;
        case sIOtype_EVENT:
            USE_SERIAL.printf("[IOc] get event: %s\n", payload);
            break;
        case sIOtype_ACK:
            USE_SERIAL.printf("[IOc] get ack: %u\n", length);
            hexdump(payload, length);
            break;
        case sIOtype_ERROR:
            USE_SERIAL.printf("[IOc] get error: %u\n", length);
            hexdump(payload, length);
            break;
        case sIOtype_BINARY_EVENT:
            USE_SERIAL.printf("[IOc] get binary: %u\n", length);
            hexdump(payload, length);
            break;
        case sIOtype_BINARY_ACK:
            USE_SERIAL.printf("[IOc] get binary ack: %u\n", length);
            hexdump(payload, length);
            break;
    }
}