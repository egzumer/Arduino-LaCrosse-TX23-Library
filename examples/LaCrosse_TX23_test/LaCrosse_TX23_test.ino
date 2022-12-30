#include <Arduino.h>
#include <LaCrosse_TX23.h>

//DATA wire connected to arduino port 10
LaCrosse_TX23 anemometer = LaCrosse_TX23(10);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  String dirTable[]= {"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};
	float speed;
	uint16_t direction;
  
	if(anemometer.read(speed, direction))
  {
    Serial.println("Speed = " + String(speed,1) + " m/s");
    Serial.println("Dir = " + String(direction) + "° " + dirTable[int(direction/22.5)]);    
  }
  else
  {
    Serial.println("Read error");
  }

	
	//delay between succesive read requests must be at least 2sec, otherwise wind speed will read 0.
	delay(2000);
}