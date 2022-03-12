#ifndef __FRAGMENTS_H__
#define __FRAGMENTS_H__
#include <Arduino.h>

class Fragments
{
public:
   String connect(String bridgeAddr);
   String heartbeat(String bridgeAddr, String deviceAddr);
};

#endif