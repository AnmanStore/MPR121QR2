#include <Arduino.h>
#include "MPR121QR2.h"

MPR121QR2 touchSensor(2);
uint8_t touchState[12];
uint16_t touchData[12];

void setup()
{
    // put your setup code here, to run once:
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    Serial.println("Hello My name is Liews");
    touchSensor.set_init();
    // Serial.println("Init");
}

void loop()
{
    Wire.beginTransmission(0x5A);
    Wire.write(0x1E);
    Wire.endTransmission(false);
    Wire.requestFrom(0x5A, 1);
    
    // uint8_t LSB = Wire.read();
    // uint8_t MSB = Wire.read();
    // uint16_t touched = ((MSB << 8) | LSB);
    // Wire.read();
    // Wire.read();
    // LSB = Wire.read();
    // MSB = Wire.read();
    // uint16_t touchedx = ((MSB << 8) | LSB);
    
    // for(uint8_t i = 0x06; i < 0x1E; i++)
    // {
    //     Wire.read();
    // }
    uint8_t LSB = Wire.read();
    uint16_t touchedd = (LSB << 2);
    Wire.endTransmission();

    Serial.print("Pin => ");
    // Serial.println(touched & 0x01);
    // Serial.print(touchedx);
    // Serial.print(", ");
    Serial.println(touchedd);
    delay(1000);

    // put your main code here, to run repeatedly:
    // digitalWrite(13,1);
    // delay(1000);
    // digitalWrite(13,0);
    // delay(1000);
    // touchSensor.update();

    // touchSensor.getTouchState(touchState);

    // for(uint8_t i = 0; i < 12; i++)
    // {
    //     Serial.print("-");
    //     Serial.print(touchState[i]);
    // }

    // Serial.println("");
    // delay(100);
}