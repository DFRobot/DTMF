/*
 * DTMF.h - Library for flashing dtmf code.
 * Created by Jose Galvez <juans455@gmail.com>, January 18, 2013.
 * Version 0.1
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 * 
 * This class creates a handle to the MT8870 DTMF decoder. It creates the 
 * necessary methods to to read its input from a connected sound wave to
 * the chip. Using DTMF DFRobot shield with a microphone connected and a speaker 
 * 
 * This code expects 5 dedicated pins to interface the DTMF decoder and
 * 2 dedicated pins for the speakers to generate DTMF through arduino.
 */
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "dtmf.h"

DTMF::DTMF(byte Q1, byte Q2, byte Q3, byte Q4, byte StD, byte SPK1, byte SPK2)
{
  this->_Q1	= Q1;
  this->_Q2	= Q2;
  this->_Q3	= Q3;
  this->_Q4	= Q4;
  this->_StD	= StD;
  this->_SPK1	= SPK1;
  this->_SPK2	= SPK2;

  pinMode(Q1, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q4, INPUT);
  pinMode(StD, INPUT);
  pinMode(SPK1, OUTPUT);
  pinMode(SPK2, OUTPUT);
}

/**
 * public DTMF::getDTMF()
 * 
 * Reads the binary ports of the 8870, and calculate its value.
 * Set to output automatically to serial for debugging purposes
 */
int DTMF::getDTMF()
{
  if (digitalRead(_StD) == HIGH) 
  {

    if (digitalRead(_Q1) == HIGH) _reg = 1;  
    else _reg = 0;

    if (digitalRead(_Q2) == HIGH) _reg = _reg + 2;
    if (digitalRead(_Q3) == HIGH) _reg = _reg + 4; 
    if (digitalRead(_Q4) == HIGH) _reg = _reg + 8;

    if (_reg == 10) return '0';  
    else if (_reg == 11) return '*';  
    else if (_reg == 12) return '#'; 
    else return _reg;

    while(1)
    {
      if(digitalRead(_StD) == LOW)
        break;
    }
  }
  else return -1;
}

/**
 * public DTMF::playDTMF()
 * 
 * Stores the frequencies for the DTMF tones and
 * Automatically plays them depending on the input of the function.
 */
 void DTMF::playDTMF()
{
  const int _freq1[] = {
  1336, 1209, 1336, 1477,
  1209, 1336, 1477, 1209,
  1336, 1477, 1209, 1477,
  1633, 1633, 1633, 1633
  };
  const int _freq2[] = {
  941, 697, 697, 697,
  770, 770, 770, 852,
  852, 852, 941, 941,
  697, 770, 852, 941
  };
  
  int phone_number[] = { 
    1, 2, 3, 4, 
    5, 6, 7, 8,
    9, 0, 10, 11, 
    12, 13, 14, 15
    };

  int i;
  for(i = 0; i < (sizeof(phone_number)/sizeof(int)); i ++) {
    Serial.print(phone_number[i], 10);
    Serial.print(' ');
    tone(2, _freq1[phone_number[i]], 500);
    tone(3, _freq2[phone_number[i]], 500);
    delay(550);
  }

  Serial.println();
}


