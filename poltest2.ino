#include <QTRSensors.h>
 /*
  analogReadSerial

  Reads a analog input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/analogReadSerial
*/

// analog pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
int s[8] = {0,0,0,0,0,0,0,0};
int i;
  QTRSensorsRC qtr((char[]){A0,A1,A2,A3,A4,A5,A6,A7},8);
// the setup routine runs once when you press reset:
void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(A6,INPUT);
  pinMode(A7,INPUT);

  // initialize serial communication at 9600 bits per second:
    for(i=0;i<250;i++)
  {
    qtr.calibrate();
    delay(20);  
 }
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
//  int buttonState = analogRead(pushButton);
  // print out the state of the button:
  s[0] = analogRead(A0);
  s[1] = analogRead(A1);
  s[2] = analogRead(A2);
  s[3] = analogRead(A3);
  s[4] = analogRead(A4);
  s[5] = analogRead(A5);
  s[6] = analogRead(A6);
  s[7] = analogRead(A7);

  for(i=0;i<8;i++)
  {
    if(s[i]<600)  s[i]=0;
    if(s[i]>800)  s[i]=1;
  }
  for(i=0;i<8;i++)
  {   Serial.print(s[i]);
      Serial.print(" ");
  }
  Serial.println();
  delay(1000);        // delay in between reads for stability
}
