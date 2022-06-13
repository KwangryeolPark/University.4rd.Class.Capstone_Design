/*
  Copyright 2022 Kwangryeol Park. All rights reserved.
  
  Owner: Kwangryeol Park.
  Email: pkr7098@gmail.com
  
  2022-06-13
*/

#ifndef _MOTOR_H
#define _MOTOR_H

#define POWER_MOTOR

class Motor {
  public:
    Motor(uint8_t A, uint8_t B);
    void wheel(int16_t spd);

  private:
    uint8_t _A, _B;
};

Motor::Motor(uint8_t A, uint8_t B) {
  pinMode(_A = A, OUTPUT);
  pinMode(_B = B, OUTPUT);
};

void Motor::wheel(int16_t spd) {
#ifdef  POWER_MOTOR
  if (spd >= 0) {
    analogWrite(_A, 255);
    analogWrite(_B, 255 - spd);
  } else {
    analogWrite(_A, 255 + spd);
    analogWrite(_B, 255);
  }
#else
  if (spd >= 0) {
    analogWrite(_A, spd);
    analogWrite(_B, 0);
  } else {
    analogWrite(_A, 0);
    analogWrite(_B, spd);
  }
#endif
};

#endif
