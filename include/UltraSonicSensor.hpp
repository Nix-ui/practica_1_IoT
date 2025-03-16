#pragma once

class UltraSonicSensor
{
private:
    byte triggerPin;
    byte echoPin;

public:
    UltraSonicSensor(byte triggerPin, byte echoPin)
    {
        this->triggerPin = triggerPin;
        this->echoPin = echoPin;
    }

    long getDistance()
    {
        pinMode(this->triggerPin, OUTPUT);
        digitalWrite(this->triggerPin, LOW);
        delayMicroseconds(2);
        digitalWrite(this->triggerPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(this->triggerPin, LOW);
        pinMode(this->echoPin, INPUT);
        return pulseIn(echoPin, HIGH);
    }

    float getDistanceCm()
    {
        return getDistance() * 0.01723;
    }
};