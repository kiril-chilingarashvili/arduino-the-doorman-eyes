/// The Doorman ///

////
    #include <Servo.h>
    
    const int servo1 = 2; // left x axis
    const int servo2 = 3; // left y axis
    const int servo3 = 4; // left bottom eyelid
    const int servo4 = 5; // left top eyelid
    const int servo5 = 6; // right x axis
    const int servo6 = 7; // right y axis
    const int servo7 = 8; // right bottom eyelid
    const int servo8 = 9; // right top eyelid
    
    int servoVal; 
    
    Servo myservo1;
    Servo myservo2;
    Servo myservo3;
    Servo myservo4;
    Servo myservo5;
    Servo myservo6;
    Servo myservo7;
    Servo myservo8;
    
////     
    int ledPin = 13;                // choose the pin for the LED
    int ledPin2 = 12;
    int inputPin = 1;               // choose the input pin (for PIR sensor)
    int pirState = LOW;             // we start, assuming no motion detected
    int val = 0;                    // variable for reading the pin status
////     
    void setup() {
      
      myservo1.attach(servo1); 
      myservo2.attach(servo2);
      myservo3.attach(servo3);
      myservo4.attach(servo4);
      myservo5.attach(servo5);
      myservo6.attach(servo6);
      myservo7.attach(servo7);
      myservo8.attach(servo8);
      
      pinMode(13, OUTPUT);
      pinMode(12, OUTPUT);
      pinMode(ledPin, OUTPUT);      // declare LED as output
      pinMode(inputPin, INPUT);     // declare sensor as input
     
      Serial.begin(9600);
    }
    void moveLeftLT(int percent) {
      int correction = 0;
      int min = 100;
      int max = 145;
      int position = max - (max - min) * percent / 100 + correction;
      myservo4.write(position);
    }
    void moveLeftLB(int percent) {
      int correction = 0;
      int min = 120;
      int max = 165;
      int position = min + (max - min) * percent / 100 + correction;
      myservo3.write(position);
    }
    void moveRightLB(int percent) {
      int correction = 0;
      int min = 30;
      int max = 110;
      int position = max - (max - min) * percent / 100 + correction;
      myservo7.write(position);
    }
    void moveRightLT(int percent) {
      int correction = 0;
      int min = 80;
      int max = 130;
      int position = max - (max - min) * percent / 100 + correction;
      myservo8.write(position);
    }
    void moveLeftX(int percent) {
      int correction = 0;
      int min = 80;
      int max = 160;
      int position = (max - min) * percent / 100 + min + correction;
      myservo1.write(position);
    }
    void moveRightX(int percent) {
      int correction = 0;
      int min = 40;
      int max = 130;
      int position = (max - min) * percent / 100 + min + correction;
      myservo5.write(position);
    }
    void moveLeftY(int percent) {
      int correction = 0;
      int min = 90;
      int max = 135;
      int position = (max - min) * percent / 100 + min + correction;
      myservo2.write(position);
    }
    void moveRightY(int percent) {
      int correction = 0;
      int min = 70;
      int max = 140;
      int position = max - (max - min) * percent / 100 + correction;
      myservo6.write(position);
    }
    void closeEyes() {
      moveLeftLT(100);
      moveRightLT(100);
      moveLeftLB(100);
      moveRightLB(100);
    }
    void openEyes() {
      moveLeftLT(0);
      moveRightLT(0);
      moveLeftLB(0);
      moveRightLB(0);
    }
    void blink() {
      closeEyes();
      delay(200);
      openEyes();
      delay(500);
      closeEyes();
      delay(200);
      openEyes();
    }
     
    void loop(){

/////// ALIGNMENT ///////

      
        openEyes();
        moveLeftX(50);
        moveRightX(50);
        moveLeftY(50);
        moveRightY(50);

         delay (1000);
      blink();
      delay(3000);
      
     moveLeftX(50);
     moveLeftY(50);
     moveRightLT(0);
     moveLeftLT(0);
     moveRightX(50);
     moveRightY(50);
     moveLeftLB(0);
     moveRightLB(0);
      
      delay(1000);blink();

      delay(1000);

      moveLeftX(0);
      moveRightX(0);
      delay(500);blink();

      moveLeftX(100);
      moveRightX(100);
      delay(500);blink();

      moveLeftX(0);
      moveRightX(0);blink();
      moveLeftY(0);
      moveRightY(0);
      delay(500);blink();

      moveLeftX(100);
      moveRightX(100);
      moveLeftY(100);blink();
      moveRightY(100);
      delay(500);

      moveLeftX(50);
      moveRightX(50);
      moveLeftY(50);blink();
      moveRightY(50);blink();
      moveLeftLT(50);
      moveRightLT(50);
      moveLeftLB(50);blink();
      moveRightLB(50);
      delay(500);
    }
