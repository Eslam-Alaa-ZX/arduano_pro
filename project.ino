#include <Buzzer.h>
#include <Servo.h>
#include <Ultrasonic.h>

#define pin A5

Servo serv;
Ultrasonic sensor(4,5);

int redLed = 6; // setting the value of redLed as 2.
int blueLed = 7; // setting the value of blueLed as 3.
int greenLed = 8;// setting the value of greenLed as 4.

int distance ;
int pos = 0;

void buzz(){
  
  tone(pin, 330, 250);
    delay(300);
    tone(pin, 311, 250);
    delay(300);
}

void setup() {
  // put your setup code here, to run once:
  pinMode (redLed,OUTPUT);// Defined redLed as output.
  pinMode (blueLed,OUTPUT);// Defined blueLed as output.
  pinMode (greenLed,OUTPUT);// Defined greenLed as output.
  pinMode(pin,OUTPUT);
  
  serv.attach(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*digitalWrite (redLed,HIGH);// Sending a signal to Pin redLed to Light Up.
  delay (3000);// Giving a Gap of 3000 Milliseconds, 1 second =  1000 milliseconds.
  digitalWrite (redLed,LOW);
  digitalWrite (blueLed,HIGH);
  delay(1000);
  digitalWrite(blueLed,LOW);
  digitalWrite(greenLed,HIGH);
  delay(3000);
  digitalWrite(greenLed,LOW);*/


  /*for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    serv.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    serv.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }*/

  serv.write(0); 
  digitalWrite(greenLed,HIGH);
  
    //delay(3000);
  
  distance = sensor.read(CM);
  if (distance < 10 )
    {
      digitalWrite(greenLed,LOW);
      
     digitalWrite (blueLed,HIGH);
     buzz();
    //delay(1000);
    //digitalWrite(blueLed,LOW);
    //digitalWrite (redLed,HIGH);// Sending a signal to Pin redLed to Light Up.
    //delay (3000);// Giving a Gap of 3000 Milliseconds, 1 second =  1000 milliseconds.
    
    
    /*digitalWrite(greenLed,HIGH);
    delay(3000);*/
    
    //serv.write(100); 
    //buzz();
    int w=1;
    int t=1;
    for (pos = 0,w=15; pos <= 85; pos += 1,w++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    if(w%15==0){
      if(t==1){
        tone(pin, 330, 250);
        t=2;
      }
      else if(t==2){
        tone(pin, 311, 250);
        t=1;
      }
      
    }
      serv.write(pos);              // tell servo to go to position in variable 'pos'
      //buzz();
      delay(20);                       // waits 15ms for the servo to reach the position
    }
    digitalWrite(blueLed,LOW);
    
    //delay(2000);
    digitalWrite (redLed,HIGH);
    
    //buzz();
    //delay(2000);
    for(int i=0;i<7;i++){
      buzz();
    }
    
    digitalWrite (redLed,LOW);
    digitalWrite (blueLed,HIGH);
    //buzz();
    for (pos = 85,w=15; pos >= 0; pos -= 1,w++) { // goes from 180 degrees to 0 degrees
      if(w%15==0){
      if(t==1){
        tone(pin, 330, 250);
        t=2;
      }
      else if(t==2){
        tone(pin, 311, 250);
        t=1;
      }
      
    }
      serv.write(pos);    
      //buzz();// tell servo to go to position in variable 'pos'
      delay(20);                       // waits 15ms for the servo to reach the position
    }
    
    //delay(1500);
    
    //myservo.write(0);
    //digitalWrite (blueLed,HIGH);
    //delay(1000);
    //buzz();
    digitalWrite(blueLed,LOW);

    }
}
