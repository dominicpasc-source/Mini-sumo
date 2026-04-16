


byte readSensors() {  //creates byte for easy sensor to motor code
    byte pattern = 0;

    pattern |= digitalRead(LeftSensor)          << 4;
    pattern |= digitalRead(LeftDiagonalSensor)  << 3;
    pattern |= digitalRead(MiddleSensor)        << 2;
    pattern |= digitalRead(RightSensor)         << 1;
    pattern |= digitalRead(RightDiagonalSensor) << 0;

    return pattern;
}

void normal() { 
   
  byte sensors = readSensors();
  switch (sensors) {
    case 0b00000:  //no sensor see
      xmotion.MotorControl(170, 170);
      break;
    case 0b00100:  //center see
      xmotion.MotorControl(255, 255);
      break;
  
    case 0b01100:  //centre and left diagonal
      xmotion.MotorControl(-255, 255);
      break;
  
    case 0b00110:  //centre and right diagonal
      xmotion.MotorControl(255, -255);
      break;

    case 0b00001:  //right
      xmotion.MotorControl(255, -255);
      break;

    case 0b10000:  //left
      xmotion.MotorControl(-255, 255);
      break;

    case 0b00011:  //right and right diagonal
      xmotion.MotorControl(255, -255);
      break;

    case 0b11000:  //left and left diagonal
      xmotion.MotorControl(-255, 255);
      break;

    case 0b00111:  //center, right diagonal and right
      xmotion.MotorControl(255, -255);
      break;

    case 0b11100:  //left, left diagonal and centre
      xmotion.MotorControl(-255, 255);
      break;

    case 0b11111:  //every sensor on
      xmotion.MotorControl(100, 100);
      break;

    case 0b01110:  //full charge oponnent ahead
      xmotion.MotorControl(255, 255);
      break;

    case 0b01000:  //left diagonal
      xmotion.MotorControl(-255, 255);
      break;

    case 0b00010:  //right diagonal
      xmotion.MotorControl(255, -255);
      break;

    default: //if something else
      xmotion.MotorControl(170, 170);
      break;
      



  }
  
}

unsigned long t = 0;
bool dir = 0;

void zigzag() { //zig zag for no flag
  byte sensors = readSensors();

  switch (sensors) {

    case 0b00000:  // no sensor = zig-zag (FAST)
      if (millis() - t > 200) {
        dir = !dir;
        t = millis();
      }

      if (dir)
        xmotion.MotorControl(255, -255);  // fast right spin
      else
        xmotion.MotorControl(-255, 255);  // fast left spin
      break;

    case 0b00100:  // center → full push
      xmotion.MotorControl(255, 255);
      break;

    case 0b01100:  
      xmotion.MotorControl(-255, 255);  // left FAST
      break;

    case 0b00110:  
      xmotion.MotorControl(255, -255);  // right FAST
      break;

    case 0b00001:  
      xmotion.MotorControl(255, -255);
      break;

    case 0b10000:  
      xmotion.MotorControl(-255, 255);
      break;

    case 0b00011:  
      xmotion.MotorControl(255, -255);
      break;

    case 0b11000:  
      xmotion.MotorControl(-255, 255);
      break;

    case 0b00111:  
      xmotion.MotorControl(255, -255);
      break;

    case 0b11100:  
      xmotion.MotorControl(-255, 255);
      break;

    case 0b11111:  
      xmotion.MotorControl(255, 255);
      break;

    case 0b01110:  
      xmotion.MotorControl(255, 255);
      break;

    case 0b01000:  
      xmotion.MotorControl(-255, 255);
      break;

    case 0b00010:  
      xmotion.MotorControl(255, -255);
      break;

    default:
      xmotion.MotorControl(200, 200);
      break;
  }
}


void full() {
  byte sensors = readSensors();
  switch (sensors) {

    case 0b00000:                  
      xmotion.MotorControl(255, 255);
      break;

    case 0b00100:
    case 0b01110:
    case 0b11111:
      xmotion.MotorControl(255, 255);
      break;

    case 0b10000:
    case 0b11000:
    case 0b11100:
      xmotion.MotorControl(-255, 255);
      break;

    case 0b01000:
    case 0b01100:
      xmotion.MotorControl(-200, 255);
      break;

    case 0b00001:
    case 0b00011:
    case 0b00111:
      xmotion.MotorControl(255, -255);
      break;

    case 0b00010:
    case 0b00110:
      xmotion.MotorControl(255, -200);
      break;

    default:
      xmotion.MotorControl(255, 255);
      break;
  }
}
