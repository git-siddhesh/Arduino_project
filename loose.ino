int Extra=11;
void speeds(int a, int b){
  analogWrite(9, a);
  analogWrite(10, b);
}
void motor(int x)
{   digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH); 
    if(x==1) //speeds(255,255);
   { digitalWrite(4,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,1);
   }/**/
    if(x==2) //speeds(0,150);
    {
    digitalWrite(4,0);
    digitalWrite(5,1);
    digitalWrite(6,0);
    digitalWrite(7,1);
    }
    if(x==3)// speeds(150,0);
    {
      digitalWrite(4,1);
    digitalWrite(5,0);
    digitalWrite(6,1);
    digitalWrite(7,0);
    }
    if(x==4) //speeds(0,0);
    {
      digitalWrite(4,0);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
    }
}

void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
//pinMode(A1, INPUT);
//pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(A4, INPUT);
pinMode(Extra,INPUT);
//pinMode(A5, INPUT);
//inMode(A6, INPUT);
pinMode(A7, INPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedl
  int SVL = analogRead(A0);
  int SVS1 = analogRead(A3);
  int SVS2 = analogRead(A4);
  int SVR = analogRead(A7);
  int front = digitalRead(Extra);
  
if(SVL<500)  SVL = 0;
if(SVS1<500)  SVS1 = 0;
if(SVS2<500)  SVS2 = 0;
if(SVR<500)  SVR = 0;
if(SVL>800)  SVL = 1;
if(SVS1>800)  SVS1 = 1;
if(SVS2>800)  SVS2 = 1;
if(SVR>800)  SVR = 1;
if(front==0) front = 1;
if(front==1) front = 0;

  Serial.print(SVL);
    Serial.print(SVS1);
      Serial.print(SVS2);
        Serial.print(SVR);
          Serial.print(front);
            Serial.println();

if((SVL==1)&&(SVS1==0)&&(SVS2==0)&&(SVR==1)&&front==0)   //straight
     motor(1);
if((SVL==0)&&(SVS1==0)&&(SVS2==0)&&(SVR==1)&&front==1)    //pure left
     motor(2);
if((SVL==1)&&(SVS1==0)&&(SVS2==0)&&(SVR==0)&&front==1)   //pure right
     motor(3);
if((SVL==0)&&(SVS1==0)&&(SVS2==0)&&(SVR==0)&&front==1)   //T
     motor(2);
if((SVL==0)&&(SVS1==0)&&(SVS2==0)&&(SVR==0)&&front==0)   //plus
{
     motor(2);
     delay(200);
     if((SVL==0)&&(SVS1==0)&&(SVS2==0)&&(SVR==0)&&front==0)
     motor(4);
}
if((SVL==1)&&(SVS1==1)&&(SVS2==1)&&(SVR==1)&&front==1)   //uturn
     motor(2);
       
}
