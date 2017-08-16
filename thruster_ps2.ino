#include <Servo.h>//Using servo library to control ESC
Servo esc1;
Servo esc2;
Servo esc3;
Servo esc4;
#include <Psx.h>   
#define dataPin 8   //brown
#define cmndPin 9   //orange
#define attPin 11   //yellow
#define clockPin 10
Psx Psx;  

unsigned int data = 0; 

void setup() {
Psx.setupPins(dataPin, cmndPin, attPin, clockPin, 10);

Serial.println("100%");
esc1.write(180);
delay(1000);
Serial.println("0%");
esc1.write(50);
delay(1000);
Serial.println("Intialized!");

esc1.attach(7); //Specify the esc signal pin,Here as D8
//esc1.writeMicroseconds(1000); //initialize the signal to 1000

esc2.attach(6); //Specify the esc signal pin,Here as D8
//esc2.writeMicroseconds(1000); //initialize the signal to 1000

esc3.attach(5); //Specify the esc signal pin,Here as D8
//esc3.writeMicroseconds(1000); //initialize the signal to 1000

esc4.attach(4); //Specify the esc signal pin,Here as D8
//esc4.writeMicroseconds(1000); //initialize the signal to 1000

Serial.begin(9600);

}

void loop() {
  //delay(500);
  int val;
  data = Psx.read();                                      // Psx.read() initiates the PSX controller and returns
  Serial.println(data); 
  if(data == 2048)
  {
    esc1.writeMicroseconds(1140);
  }
  else if(data == 18432)
  { 
    esc1.writeMicroseconds(1190);
  }
  else if(data == 1024)
  {
    esc2.writeMicroseconds(1140);
  }
  else if(data == 17408)
  { 
    esc2.writeMicroseconds(1190);
  }
  else if(data == 512)
  {
    esc3.writeMicroseconds(1140);
  }
  else if(data == 16896)
  { 
    esc3.writeMicroseconds(1190);
  }
  else if(data == 256)
  {
    esc4.writeMicroseconds(1140);
  }
  else if(data == 16640)
  { 
    esc4.writeMicroseconds(1190);
  }
  else
  {
    esc1.writeMicroseconds(0);
    esc2.writeMicroseconds(0);
    esc3.writeMicroseconds(0);
    esc4.writeMicroseconds(0);
  }
 
 
  // put your main code here, to run repeatedly:
 // delay(20);
}
