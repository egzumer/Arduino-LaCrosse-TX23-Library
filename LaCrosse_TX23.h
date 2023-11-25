/*************************************************************************************************
  LaCrosse_TX23.h - Library for reading LaCrosse TX23 anemometer data.
  
  LaCrosse TX23 is a wind speed and direction sensor. It uses 3 wires for communication and power:
  Pin1	Brown(Black)	DATA
  Pin2	Red				Vcc
  Pin3	Green			N/C
  Pin4	Yellow			GND
  
  DATA pin is to be connected directly to one of Arduino ports.
  
  
  
  Created by Krzysztof Egzmont, 06.11.2016.
  Based on https://www.john.geek.nz/2012/08/la-crosse-tx23u-anemometer-communication-protocol/
  Big thanks for John.

*************************************************************************************************/

#ifndef LaCrosse_TX23_h
#define LaCrosse_TX23_h

#include "Arduino.h"

class LaCrosse_TX23
{
	public:
    typedef void(*DelayFunc)(uint32_t ms);

		//init pin number with DATA wire connected
		LaCrosse_TX23(int pin, DelayFunc delayFunc = [](uint32_t ms){delay(ms);} );

		// reads sensor data, returns true if successfull
    // wind speed in m/s
    // wind direction in degrees 0-359
    bool read(float &speed, uint16_t &direction);
    
    // reads raw sensor data, returns true if successfull
    // wind speed in 0.1 m/s
    // wind direction 0-15
		bool readRaw(uint16_t &speed, uint8_t &direction);

    struct Data {
      bool valid; // true if read successful
      float speed; // wind speed in m/s
      uint16_t direction; // wind direction in degrees 0-359
    };

    Data read();

    struct RawData {
      bool valid; // true if read successful
      uint16_t speed; // wind speed in 0.1 m/s
      uint8_t direction; // wind direction 0-15
    };

    RawData readRaw();
    
    // sets delay function that takes ms
    // conversion trigger signal length is 300ms, by default standard Arduino delay is used,
    // this can be changed to e.g. deep sleep to aptimise battery consumption
    void setDelayFunc(DelayFunc func) { _delay = func;};
    
	private:
		int _pin;
    DelayFunc _delay;
		static void pullBits(void *dst, bool *src, int count);

};

#endif