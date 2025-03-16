#include "include/LedController.hpp"
#include "include/UltraSonicSensor.hpp"



Led red(23);
Led yellow(22);
Led orange(21);
Led green(19);
Led blue(18);
Led leds[] = {blue,green,orange,yellow,red};
LedController ledWire(leds,5);
UltraSonicSensor mySensor(2,4);

void setup(){
  Serial.begin(9600);
  ledWire.setAllState(Led::STATE_OFF);
}
float cm;
void loop(){
  cm = mySensor.getDistanceCm();
  if(cm >=150){
    ledWire.setAllState(Led::STATE_OFF);
  }else if(cm>=120 && cm<150){
    ledWire.setAllState(Led::STATE_OFF);
    blue.setState(Led::STATE_BLINK);
  }else if(cm>=90 && cm<120){
    ledWire.setAllState(Led::STATE_OFF);
    green.setState(Led::STATE_BLINK);
  }else if(cm >=60 && cm<90){
    ledWire.setAllState(Led::STATE_OFF);
    orange.setState(Led::STATE_BLINK);
  }else if(cm>=30 && cm<60){
    ledWire.setAllState(Led::STATE_OFF);
    yellow.setState(Led::STATE_BLINK);
  }else if(cm>=20){
    ledWire.setAllState(Led::STATE_OFF);
    red.setState(Led::STATE_BLINK);
  }else if (cm>=10){
   ledWire.setAllState(Led::STATE_BLINK); 
  }else{
    ledWire.setAllState(Led::STATE_ON); 
  }
  Serial.print(cm);
  Serial.println("cm");
  delay(100);
}