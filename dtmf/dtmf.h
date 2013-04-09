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
 * necessary methods to to read its input from a connected sound wave into
 * the chip. Using DTMF DFRobot shield with a microphone connected and a speaker 
 * 
 * This code expects 5 dedicated pins to interface the DTMF decoder and
 * 2 dedicated pins for the speakers to generate DTMF through arduino.
 */
#ifndef dtmf_h
#define dtmf_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class DTMF
{
  public:
    DTMF(byte = 12, byte = 11, byte = 10, byte = 9, byte = 8, byte = 2, byte = 3);
    int getDTMF();
    void playDTMF();
  private:
    byte _reg;
    byte _Q1;
    byte _Q2;
    byte _Q3;
    byte _Q4;
    byte _StD;
    byte _SPK1;
    byte _SPK2;
    int *_freq1[];
    int *_freq2[];
};



#endif
