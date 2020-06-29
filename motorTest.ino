void setup() {
  // put your setup code here, to run once:
 pinMode(4,OUTPUT); //Left Motor Pin 1
 pinMode(5,OUTPUT); //Left Motor Pin 2
 pinMode(6,OUTPUT); //Right Motor Pin 1
 pinMode(7,OUTPUT);  //Right Motor Pin 2
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
     digitalWrite(6,LOW);//left
    digitalWrite(7,HIGH);
    delay(500);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
     digitalWrite(6,LOW);//left
    digitalWrite(7,LOW);
    delay(8000);
   digitalWrite(4,LOW);
   digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);//left
    digitalWrite(7,LOW);
    delay(8000);
  
}
