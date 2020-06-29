int sensor[8]={0, 0, 0, 0, 0,0,0,0};
int i;
  void HardRight(){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);//RIGHT
    digitalWrite(7,HIGH); 
    Serial.println("HR ");
   }
  void HardLeft(){
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);//left
    digitalWrite(7,HIGH); 
        Serial.println("HL ");  
  }
  void SoftLeft(){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,100);//left
    digitalWrite(7,100); 
        Serial.println("SL ");
}
void SoftRight(){
    digitalWrite(4,100);
    digitalWrite(5,100);
    digitalWrite(6,LOW);//RIGHT
    digitalWrite(7,LOW); 
        Serial.println("SR ");

}
void Straight(){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
        Serial.println(" | ");

}
void read_sensor_values()
{
  delay(100);
  sensor[0]=analogRead(A0);
  sensor[1]=analogRead(A1);
  sensor[2]=analogRead(A2);
  sensor[3]=analogRead(A3);
  sensor[4]=analogRead(A4);
  sensor[5]=analogRead(A5);
  sensor[6]=analogRead(A6);
  sensor[7]=analogRead(A7);

  for(i=0;i<8;i++){
    if(sensor[i]<=400)
        sensor[i] = 0;
    else  sensor[i]= 1;
  }

Serial.print(sensor[0]);
Serial.print(sensor[1]);
Serial.print(sensor[2]);
Serial.print(sensor[3]);
 
Serial.print(sensor[4]);
Serial.print(sensor[5]);
Serial.print(sensor[6]);
Serial.println(sensor[7]);
  //UTURN
/* if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=0)&&(sensor[3]!=0)&&(sensor[4]!=0)&&(sensor[5]!=0)&&(sensor[6]!=0)&&(sensor[7]!=0))
            HardLeft();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=0)&&(sensor[7]!=0))
            Straight();
  if((sensor[0]!=0)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=0)&&(sensor[6]!=0)&&(sensor[7]!=0))
            Straight();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=0)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=0))
            Straight();
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=0)&&(sensor[6]!=0)&&(sensor[7]!=0))
            HardLeft();
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=0)&&(sensor[7]!=0))
            HardLeft();
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=0))
            HardLeft();
  if((sensor[0]!=0)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
            HardRight();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
            HardRight();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=0)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
            HardRight();
            */
            HardLeft();

}
void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT); //PWM Pin 1
 pinMode(10,OUTPUT); //PWM Pin 2
 pinMode(4,OUTPUT); //Left Motor Pin 1
 pinMode(5,OUTPUT); //Left Motor Pin 2
 pinMode(6,OUTPUT); //Right Motor Pin 1
 pinMode(7,OUTPUT);  //Right Motor Pin 2
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
read_sensor_values();
}
