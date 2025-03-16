#pragma once
#include "Controller.hpp"
#include "Led.hpp"
class LedController:public Controller{
    private:
        Led* leds;
        byte numLeds;
    public:
        LedController(Led* leds, byte numLeds):Controller()
        {
            this->numLeds = numLeds;
          	this->leds = leds;
        }
        void setAllState(byte state) {
            for (int i=0;i<numLeds;i++) {
                leds[i].setState(state);
            }
    	}
};