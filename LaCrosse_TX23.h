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
  
  Donations: 
  Bitcoin - 1JrHQwJWt1JNZepT1EXqPSioXcwD227nnU
  Ethereum - 0xFC9713013e78f6F14bA5064E36f875dbbB32B94a
  
  BSD license, all text above must be included in any redistribution
*************************************************************************************************/

#ifndef LaCrosse_TX23_h
#define LaCrosse_TX23_h

#include "Arduino.h"

class LaCrosse_TX23
{
	public:
		//init pin number with DATA wire connected
		LaCrosse_TX23(int pin);
		//reads sensor data, returns true if success
		bool read(float &speed, int &direction);
	private:
		int _pin;
		static void pullBits(void *dst, bool *src, int count);

};

#endif