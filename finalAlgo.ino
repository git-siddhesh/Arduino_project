int endPoint =0;
int count=0;
int sensor[8]={0, 0, 0, 0, 0,0,0,0};
int strt,j=0,i;
//structure defining for a node
 struct a
{
    int l=0,r=0,u=0,s=0;
    int node;
    a *next,*prev;
}*nd,*start,*cur,*ptr,*p,*z;
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
  void Straight(){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    Serial.println(" | ");
}
void create_node(int x)
{   
       nd=(struct a*)malloc(sizeof(struct a));//creat node
  nd->node=j++;
  switch(x)
  {
      case 2:{
        nd->u=1;
        break;
      }
      case 4:{
        nd->r=1;
        break;
      }
      case 5:{
        nd->r=1;
        nd->s=1;
        break;
      }
      case 8:{
        nd->l=1;
        break;
      }
      case 9:{
        nd->l=1;
        nd->s=1;
        break;
      }
      case 12:{
        nd->l=1;
        nd->r=1;
        break;
      }
      case 13:{
        nd->l=1;
        nd->r=1;
        nd->s=1;
        break;
      }
  }
        
    nd->next=nd->prev=NULL;
    if(start==NULL)
    { start=nd;
    }
    else
    { p=start;
     while(p->next!=NULL)
        p=p->next;
     p->next=nd;
     nd->next=NULL;
     nd->prev=p;
    }
//   printNode();
  
}
int movedx()
{   int local=1;
   digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
     digitalWrite(6,LOW);//left
    digitalWrite(7,HIGH);
    delay(500);
  sensor[1] = analogRead(A1);
  sensor[2] = analogRead(A2);
  sensor[3] = analogRead(A3);
  sensor[4] = analogRead(A4);
  sensor[5] = analogRead(A5);
  sensor[6] = analogRead(A6);
   for(i=0;i<8;i++){
    if(sensor[i]<=400)
        sensor[i] = 0;
    else  sensor[i]= 1;
  }
     if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1)&&(sensor[6]==1)&&(sensor[7]==1))
           local=0;
   digitalWrite(4,LOW);
   digitalWrite(5,HIGH);
      digitalWrite(6,HIGH);//left
    digitalWrite(7,LOW);
    delay(500);
   return local;
}
void unode()
{
  create_node(2);
  HardLeft();
}
void lnode()
{ 
 strt = movedx();
 create_node(strt+8);
   HardLeft();

}
void rnode()
{
  strt = movedx();
  create_node(strt+4);
  if(strt==1)
     Straight();
  else
     HardRight();
}
void lrnode()
{
  strt = movedx();
  create_node(12+strt);
  HardLeft();
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
  if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==1)&&(sensor[5]==1)&&(sensor[6]==1)&&(sensor[7]==1))
            unode();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=0)&&(sensor[7]!=0))
            Straight();
  if((sensor[0]!=0)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=0)&&(sensor[6]!=0)&&(sensor[7]!=0))
            Straight();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=0)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=0))
            Straight();
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=0)&&(sensor[6]!=0)&&(sensor[7]!=0))
            lnode();
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=0)&&(sensor[7]!=0))
            lnode();
  if((sensor[0]!=1)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=0))
            lnode();
  if((sensor[0]!=0)&&(sensor[1]!=1)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
            rnode();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=1)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
            rnode();
  if((sensor[0]!=0)&&(sensor[1]!=0)&&(sensor[2]!=0)&&(sensor[3]!=1)&&(sensor[4]!=1)&&(sensor[5]!=1)&&(sensor[6]!=1)&&(sensor[7]!=1))
            rnode();
  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0)&&(sensor[5]==0)&&(sensor[6]==0)&&(sensor[7]==0))
            lrnode();
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

/* 
 * if(s[0]==0 && 8times &irsensor==1)
 *  endPoint =1;
 *  stop();
 */

//code for dry run that will change the value of endPoint to 1 when it reach at end
