//  Author:Frankie.Chu
//  Date:9 April,2012
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
//  Modified record:
//  ASCII table added by Mihail Vasilev, 2017
//
/*******************************************************************************/
#include "TM1637.h"
#include <Arduino.h>

//   ---a---
//   f     b
//   ---g---
//   e     c
//   ---d---
//           p
//
//
static int8_t TubeTab[] = { // ASCII FROM 32'nd symbol

                      // ' ': 0000000  32
                           0x00,
                      // '!': 0001010  33
                           0x0A,
                      //  " : 0100010  34
                           0x22,
                      //  # : 1010100  35  (as 'n')
                           0x54,
                      //  $ : 1101100  36
                           0x6C,
                      //  % : 0100100  37  (as ', )
                           0x24,
                      //  & : 1000110  38  (as like + )
                           0x46,
                      //  ' : 0000010  39
                           0x02,
                      //  ( : 0110001  40  (as Г )
                           0x31,
                      //  ) : 0001110  41  (opposite)
                           0x0E,
                      //  * : 1100011  42  (^o)
                           0x63,
                      //  + : 1000110  43  (as like + )
                           0x46,
                      //  , : 0010000  44  
                           0x10,
                      //  - : 1000000  45
                           0x40,
                      //  . : 0000100  46
                           0x04,
                      //  / : 1010010  47
                           0x52,
                      //  0 : 0111111  48
                           0x3f,
                      //  1 : 0000110 
                           0x06,
                      //  2 : 
                          0x5b,
                      //  3 : 
                          0x4f,
                      //  4 : 
                          0x66,
                      //  5 : 
                          0x6d,
                      //  6 :
                          0x7d,
                      //  7 :
                          0x07,
                      //  8 :
                          0x7f,
                      //  9 : 
                          0x6f,
                      // ':':10000000  58 (works only in certain position!)
                          0x80,
                      // ';': 0010000  59 (as ,)
                          0x10,
                      // '<': 1100001  60 (as ^c)
                          0x61,
                      // '=': 1001000  61 
                          0x48,
                      // '>': 1000011  62
                          0x43,
                      //  ? : 1010011  63
                          0x53,
                      //  @ : 1101011  64 
                          0x6B,
                      //  A : 
                          0x77,
                      //  b :
                          0x7c,
                      //  c : 1011000
                          0x58,
                      //  d :
                          0x5e,
                      //  E :
                          0x79,
                      //  F :
                          0x71,
                      //     ?gfedcba 
                      //  G:  0111101  71
                           0x3d,
                      //  h:  1110100  72
                           0x74,
                      //  I:  0110000  73
                           0x30,
                      //  J:  0011110  74
                           0x1E, 
                      //  K:  1110101  75
                           0x75,
                      //  L:  0111000  76
                           0x38,
                      //  M:  1010101  77
                           0x55,  
                      //  N:  1010100  78
                           0x54,
                      //  o:  1011100  79
                           0x5C,
                      //  p:  1110011  80
                           0x73,
                      //  q:  1100111  81
                           0x67,
                      //  r:  1010000  82
                           0x50,
                      //     ?gfedcba 
                      //  S:  1101101  83
                           0x6d,
                      //  t:  1111000  84
                           0x78,
                      //  U:  0111110  85
                           0x3E,
                      //  v:  0011100  86
                           0x1C,
                      //  w:  1111110  87
                           0x7e,
                      //  x:  1110110  88
                           0x76, 
                      //  y:  1101110  89
                           0x6E,
                      //  Z:  0011011  90
                           0x1b,
                      // '[': 0111001  91
                           0x39,
                      // '\': 1100100  92
                           0x64,
                      // ']': 0001111  93
                           0x0f,
                      // '^': 0100011  94
                           0x23,
                      // '_': 0001000  95
                           0x08,
                      // '`': 0000010  96
                           0x02,
                      //  A : 
                          0x77,
                      //  b :
                          0x7c,
                      //  c : 1011000
                          0x58,
                      //  d : 1011110
                          0x5e,
                      //  E :
                          0x79,
                      //  F :
                          0x71,
                      //     ?gfedcba 
                      //  g:  1101111  103
                           0x6f,
                      //  h:  1110100  72
                           0x74,
                      //  I:  0110000  73
                           0x30,
                      //  J:  0011110  74
                           0x1E, 
                      //  K:  1110101  75
                           0x75,
                      //  L:  0111000  76
                           0x38,
                      //  M:  1010101  77
                           0x55,  
                      //  N:  1010100  78
                           0x54,
                      //  o:  1011100  79
                           0x5C,
                      //  p:  1110011  80
                           0x73,
                      //  q:  1100111  81
                           0x67,
                      //  r:  1010000  82
                           0x50,
                      //     ?gfedcba 
                      //  S:  1101101  83
                           0x6d,
                      //  t:  1111000  84
                           0x78,
                      //  U:  0111110  85
                           0x3E,
                      //  v:  0011100  86
                           0x1C,
                      //  w:  1111110  87
                           0x7e,
                      //  x:  1110110  88
                           0x76, 
                      //  y:  1101110  89
                           0x6E,
                      //  Z:  0011011  90
                           0x1b,
                      //'{':  0111001  123
                           0x39,
                      //'|':  0110000  124
                           0x30,
                      //'}':  0001111  125
                           0x0f,
                      // ~ :  1000001  126  (as ^=)
                           0x81,
                      //   :  0000000  127  (delete - as ' ')
                           0x00
                          };//0~9,A,b,C,d,E,F,G
TM1637::TM1637(uint8_t Clk, uint8_t Data)
{
  Clkpin = Clk;
  Datapin = Data;
  pinMode(Clkpin,OUTPUT);
  pinMode(Datapin,OUTPUT);
}

void TM1637::init(void)
{
  clearDisplay();
}

void TM1637::writeByte(int8_t wr_data)
{
  uint8_t i,count1;   
  for(i=0;i<8;i++)        //sent 8bit data
  {
    digitalWrite(Clkpin,LOW);      
    if(wr_data & 0x01)digitalWrite(Datapin,HIGH);//LSB first
    else digitalWrite(Datapin,LOW);
    wr_data >>= 1;      
    digitalWrite(Clkpin,HIGH);
      
  }  
  digitalWrite(Clkpin,LOW); //wait for the ACK
  digitalWrite(Datapin,HIGH);
  digitalWrite(Clkpin,HIGH);     
  pinMode(Datapin,INPUT);
  while(digitalRead(Datapin))    
  { 
    count1 +=1;
    if(count1 == 200)//
    {
     pinMode(Datapin,OUTPUT);
     digitalWrite(Datapin,LOW);
     count1 =0;
    }
    pinMode(Datapin,INPUT);
  }
  pinMode(Datapin,OUTPUT);
  
}
//send start signal to TM1637
void TM1637::start(void)
{
  digitalWrite(Clkpin,HIGH);//send start signal to TM1637
  digitalWrite(Datapin,HIGH); 
  digitalWrite(Datapin,LOW); 
  digitalWrite(Clkpin,LOW); 
} 
//End of transmission
void TM1637::stop(void)
{
  digitalWrite(Clkpin,LOW);
  digitalWrite(Datapin,LOW);
  digitalWrite(Clkpin,HIGH);
  digitalWrite(Datapin,HIGH); 
}
//display function.Write to full-screen.
void TM1637::display(int8_t DispData[])
{
  int8_t SegData[4];
  uint8_t i;
  for(i = 0;i < 4;i ++)
  {
    SegData[i] = DispData[i];
  }
  coding(SegData);
  start();          //start signal sent to TM1637 from MCU
  writeByte(ADDR_AUTO);//
  stop();           //
  start();          //
  writeByte(Cmd_SetAddr);//
  for(i=0;i < 4;i ++)
  {
    writeByte(SegData[i]);        //
  }
  stop();           //
  start();          //
  writeByte(Cmd_DispCtrl);//
  stop();           //
}
//******************************************
void TM1637::display(uint8_t BitAddr,int8_t DispData)
{
  int8_t SegData;
  SegData = coding(DispData);
  start();          //start signal sent to TM1637 from MCU
  writeByte(ADDR_FIXED);//
  stop();           //
  start();          //
  writeByte(BitAddr|0xc0);//
  writeByte(SegData);//
  stop();            //
  start();          //
  writeByte(Cmd_DispCtrl);//
  stop();           //
}

void TM1637::clearDisplay(void)
{
  display(0x00,0x7f);
  display(0x01,0x7f);
  display(0x02,0x7f);
  display(0x03,0x7f);  
}
//To take effect the next time it displays.
void TM1637::set(uint8_t brightness,uint8_t SetData,uint8_t SetAddr)
{
  Cmd_SetData = SetData;
  Cmd_SetAddr = SetAddr;
  Cmd_DispCtrl = 0x88 + brightness;//Set the brightness and it takes effect the next time it displays.
}

//Whether to light the clock point ":".
//To take effect the next time it displays.
void TM1637::point(boolean PointFlag)
{
  _PointFlag = PointFlag;
}
void TM1637::coding(int8_t DispData[])
{
  uint8_t PointData;
  if(_PointFlag == POINT_ON)PointData = 0x80;
  else PointData = 0; 
  for(uint8_t i = 0;i < 4;i ++)
  {
//    if(DispData[i] == 0x7f)DispData[i] = 0x00;
//    else 
//     { 
       if(DispData[i]<32) { 
          DispData[i]=0;
       } else {
          DispData[i] = TubeTab[DispData[i]-32] + PointData;
       };
//     };
  }
}
int8_t TM1637::coding(int8_t DispData)
{
  uint8_t PointData;
  if(_PointFlag == POINT_ON)PointData = 0x80;
  else PointData = 0; 
  if(DispData<32) {
       DispData = 0;
  } else {
       DispData = TubeTab[DispData-32];
  };
//  if(DispData == 0x7f) DispData = 0x00 + PointData;//The bit digital tube off
//  else DispData = TubeTab[DispData-32] + PointData;
  return DispData;
}
