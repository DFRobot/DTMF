/*
  DTMF.cpp - TEST code for DTMF library
*/



#include "dtmf.h"

DTMF dtmf; // default set to DFRobot DTMF board pins, Speaker pins

void setup()
{
 Serial.begin(9600);
}

void loop()
{
  // Play a default number with all possibilities
  //dtmf.playDTMF();
  
  // Read DTMF codes one by one and print it on Serial
  int myDtmf;
  myDtmf = dtmf.getDTMF();
  Serial.println(myDtmf);
}
