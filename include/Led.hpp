#pragma once

class Led
{
private:
    byte pin;
    bool actualState;
    byte finalState;
    unsigned long previousMillis;
    unsigned long interval;

public:
    static const byte STATE_OFF = 0;
    static const byte STATE_ON = 1;
    static const byte STATE_BLINK = 2;

    Led(byte pin)
    {
        this->pin = pin;
        pinMode(pin, OUTPUT);
        actualState = false;
        finalState = STATE_OFF;
        previousMillis = 0;
        interval = 0;
    }

    void setBlinksPerSecond(byte blinksPerSecond)
    {
        this->interval = 1000 / blinksPerSecond;
    }

    void turnOn()
    {
        digitalWrite(this->pin, HIGH);
        this->actualState = true;
    }

    void turnOff()
    {
        digitalWrite(this->pin, LOW);
        this->actualState = false;
    }

    void blink()
    {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval)
        {
            previousMillis = currentMillis;
            if (!actualState)
            {
                turnOn();
            }
            else
            {
                turnOff();
            }
        }
    }

    void setState(byte state)
    {
        this->finalState = state;
        switch (this->finalState)
        {
        case STATE_OFF:
            turnOff();
            break;
        case STATE_ON:
            turnOn();
            break;
        case STATE_BLINK:
            blink();
            break;
        }
    }
};