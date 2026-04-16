
#include <xmotionV3.h>        //Included XMotion Library
int RightSensor = 0;          //Right Opponent Sensor Pin
int RightDiagonalSensor = 1;  //Right Diagonal Opppnent Sensor Pin
int MiddleSensor = 2;         //Middle Oppoent Sensor Pin
int LeftDiagonalSensor = 4;   //Left Diagonal Opponent Sensor Pin
int LeftSensor = A5;          //Left Opponent Sensor Pin

int LeftLine = A1;    //Left Line Sensor Pin
int RightLine = A2;   //Right Line Sensor Pin
int MicroStart = A4;  //MicroStart Signal Pin

int Led1 = 8;

int LastValue = 0;

void setup() {

  xmotion.StopMotors(100);  
  xmotion.ToggleLeds(100);  
  pinMode(Led1, OUTPUT);
  pinMode(RightSensor, INPUT); 
  pinMode(RightDiagonalSensor, INPUT);
  pinMode(MiddleSensor, INPUT);
  pinMode(LeftDiagonalSensor, INPUT);
  pinMode(LeftSensor, INPUT);
  pinMode(MicroStart, INPUT); 
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(MicroStart) == HIGH) {  // Start

    // Line sensor
    if (analogRead(LeftLine) < 300 && analogRead(RightLine) > 300)  //Left Line Sensor Saw the Line
    {
      xmotion.Backward(100, 100);                                          //Backward %100 speed, 100 ms retreat.
      xmotion.Left0(100, 250);                                             //Right Turning %100 speed, 200ms duration.
    } else if (analogRead(LeftLine) > 300 && analogRead(RightLine) < 300)  //Right Line Sensor Saw the Line
    {
      xmotion.Backward(100, 100);                                          //Backward %100 speed, 100 ms retreat.
      xmotion.Right0(100, 250);                                            //Left Turning %100 speed, 200ms duration.
    } else if (analogRead(LeftLine) < 300 && analogRead(RightLine) < 300)  //Both Sensor Saw the Line
    {
      xmotion.Backward(100, 500);                                            //Backward %100 speed, 500 ms retreat.
      xmotion.Right0(100, 250);                                              //Left Turning %100 speed, 200ms duration.
    } else if (analogRead(LeftLine) > 300 && analogRead(RightLine) > 300) {  //no line
      // xmotion.MotorControl(170, 170);  //normal mode

      normal();
      //zigzag();
      //full();
    }
  } else {
    xmotion.MotorControl(0, 0); 
    xmotion.UserLed2(0); 
  }
}