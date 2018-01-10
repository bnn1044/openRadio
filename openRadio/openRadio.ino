#include <PulsePosition.h>

// Simple loopback test: create 1 output to transmit
// test pulses, and 1 input to receive the pulses
PulsePositionOutput PPmOut;
//PulsePositionInput myIn;
#define ChannelMaxus  2000.00
#define ChannelMinus  0  

// define some hardware connection
#define PPMoutPin     9
/*#define THR  A0
#define YAW  A1
#define ELE  A2
#define ROL  A3
*/
// define global variable
float  Chs_us[6];
int max_analog_Chs = 6;    //16 channels

void setup() {
  PPmOut.begin(PPMoutPin);  // connect pins 9 and 10 together...
}
//Write CH, TIME in us
void UpdateCHS(float *Chs ){
  for(int i = 0; i < max_analog_Chs;i++){
    PPmOut.write(i,Chs[i]);
  }
}
float  ReadStick(int CH){
  int ADC_INT = analogRead(CH);
  return float(ADC_INT) * (ChannelMaxus/1023.00);
}
void loop() {
  long PreviewTime = micros();
  for( int i=0; i < max_analog_Chs ;i++ ){
    Chs_us[i] = ReadStick(i);
    delayMicroseconds(1);
  }
  Serial.println(micros()-PreviewTime);
}

