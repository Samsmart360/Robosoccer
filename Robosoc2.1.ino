// for Bluetooth Rc controller app 

#include <Servo.h>

int incomingByte;

int I1 = 49;
int I2 = 48;
int J1 = 24;
int J2 = 25;
int C1 = 53;
int C2 = 52;
int D1 = 26;
int D2 = 27;
int E1 = 50;
int E2 = 23;

Servo kickerR;
Servo kickerL;

int R1 = 36;
int R2 = 37;
int Enable = 35;

int L1 = 32;
int L2 = 33;

int pos1 = 0;
/*Servo kicker1;
Servo kicker2;
int pos1= 0;
int pos2 = 0;*/

void hit()
{
  
  digitalWrite(R2,HIGH);
  digitalWrite(L2,HIGH);
  
  for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    kickerR.write(pos1); 
    kickerL.write(180-pos1);// tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
  }
  for (pos1 = 180; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    kickerR.write(pos1); 
    kickerL.write(180-pos1);// tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
  }
}



// bluetooth 0,1,GND,+5V
void setup() {
  Serial.begin(9600);
  pinMode(I1,OUTPUT);
  pinMode(I2,OUTPUT);
  pinMode(J1,OUTPUT);
  pinMode(J2,OUTPUT);
  pinMode(C1,OUTPUT);
  pinMode(C2,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);

  pinMode(E1,OUTPUT);
  pinMode(E2,OUTPUT);

  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(Enable,OUTPUT);

  kickerR.attach(2);
  kickerL.attach(3);
  
  //kicker1.attach(12);
  //kicker2.attach(13);

  digitalWrite(I1,LOW);
  digitalWrite(I2,LOW);
  digitalWrite(J1,LOW);
  digitalWrite(J2,LOW);
  digitalWrite(C1,LOW);
  digitalWrite(C2,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);

  digitalWrite(E1,LOW);
  digitalWrite(E2,LOW);

  digitalWrite(R1,LOW);
digitalWrite(R2,HIGH);
digitalWrite(L1,LOW);
digitalWrite(L2,HIGH);
digitalWrite(Enable,HIGH);

kickerR.write(0); 
kickerL.write(180);
delay(3000);

digitalWrite(R2,LOW);
digitalWrite(L2,LOW);
}

void loop() {
if (Serial.available() > 0) 
{
// read the incoming byte:
incomingByte = Serial.read();

if(incomingByte==70) // forward
{
  digitalWrite(I1,LOW);
  digitalWrite(I2,HIGH);
  digitalWrite(J1,LOW);
  digitalWrite(J2,HIGH);
  digitalWrite(C1,LOW);
  digitalWrite(C2,HIGH);
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);

  digitalWrite(E1,HIGH);
  digitalWrite(E2,HIGH);
}

if(incomingByte == 71) // forward left 
{
  digitalWrite(I1,LOW);
  digitalWrite(I2,HIGH);
  digitalWrite(J1,LOW);
  digitalWrite(J2,LOW);
  digitalWrite(C1,LOW);
  digitalWrite(C2,HIGH);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);

  digitalWrite(E1,HIGH);
  digitalWrite(E2,HIGH);
  
}

if(incomingByte == 76) // left 
{
  digitalWrite(I1,LOW);
  digitalWrite(I2,HIGH);
  digitalWrite(J1,HIGH);
  digitalWrite(J2,LOW);
  digitalWrite(C1,LOW);
  digitalWrite(C2,HIGH);
  digitalWrite(D1,HIGH);
  digitalWrite(D2,LOW);

  digitalWrite(E1,HIGH);
  digitalWrite(E2,HIGH);
  
}

if (incomingByte == 83) // stop 
{
  digitalWrite(I1,LOW);
  digitalWrite(I2,LOW);
  digitalWrite(J1,LOW);
  digitalWrite(J2,LOW);
  digitalWrite(C1,LOW);
  digitalWrite(C2,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);

  digitalWrite(E1,LOW);
  digitalWrite(E2,LOW);


  
  
}

if (incomingByte==120||incomingByte==88) // shoot
{ 
  hit();

}

if (incomingByte==73) // forward right
{
  digitalWrite(I1,LOW);
  digitalWrite(I2,LOW);
  digitalWrite(J1,LOW);
  digitalWrite(J2,HIGH);
  digitalWrite(C1,LOW);
  digitalWrite(C2,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);

  digitalWrite(E1,HIGH);
  digitalWrite(E2,HIGH);

}

if (incomingByte==82) //  right
{
  digitalWrite(I1,HIGH);
  digitalWrite(I2,LOW);
  digitalWrite(J1,LOW);
  digitalWrite(J2,HIGH);
  digitalWrite(C1,HIGH);
  digitalWrite(C2,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);

  digitalWrite(E1,HIGH);
  digitalWrite(E2,HIGH);

}

if (incomingByte==66) // Reverse
{
  digitalWrite(I2,LOW);
  digitalWrite(I1,HIGH);
  digitalWrite(J2,LOW);
  digitalWrite(J1,HIGH);
  digitalWrite(C2,LOW);
  digitalWrite(C1,HIGH);
  digitalWrite(D2,LOW);
  digitalWrite(D1,HIGH);

  digitalWrite(E1,HIGH);
  digitalWrite(E2,HIGH);

} 

if (incomingByte==74) // reverse right
{
  digitalWrite(I1,LOW);
  digitalWrite(I2,LOW);
  digitalWrite(J1,HIGH);
  digitalWrite(J2,LOW);
  digitalWrite(C1,LOW);
  digitalWrite(C2,LOW);
  digitalWrite(D1,HIGH);
  digitalWrite(D2,LOW);

  digitalWrite(E1,HIGH);
  digitalWrite(E2,HIGH);

}

if(incomingByte == 72) // reverse left 
{
  digitalWrite(I1,HIGH);
  digitalWrite(I2,LOW);
  digitalWrite(J1,LOW);
  digitalWrite(J2,LOW);
  digitalWrite(C1,HIGH);
  digitalWrite(C2,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);

  digitalWrite(E1,HIGH);
  digitalWrite(E2,HIGH);
  
}

} // end of available

} // end of loop

