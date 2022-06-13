#include <Wire.h>
#include <Kalman.h>
#include <CMPU6050.h>
#include "Motor.h"
#include "PID.h"

#define MOTORL_A  6
#define MOTORL_B  9
#define MOTORR_A  3
#define MOTORR_B  5

Motor L_Motor(MOTORL_A, MOTORL_B);
Motor R_Motor(MOTORR_A, MOTORR_B);

CMpu6050Manager g_Mpu6050;

void setup() {
  Serial.begin(19200);

  g_Mpu6050.Init(); //setup에서 반드시 한번 호출해 줍니다.
  pinMode(13, OUTPUT);
  digitalWrite(13, 1);


  pinMode(4, OUTPUT);   //  Motor standby
  digitalWrite(4, 1);
  motor(0, 0);
}

PID pid;

uint32_t timer = 0;
uint32_t previous = 0;
PID_TYPE gap = 0;
PID_TYPE target = -3.1;  //  -3.1

//#define GET_OFFSET_ANGLE

void loop() {

  g_Mpu6050.Update();
  float kalmanangley = g_Mpu6050.GetKalAngleY();
  float kalmananglex = g_Mpu6050.GetKalAngleX();
  timer = millis();
  if (abs(kalmanangley) > 30 || abs(kalmananglex) > 20) {
    motor(0, 0);
    digitalWrite(4, LOW);
    digitalWrite(13, 0);
    while (1);
  }
#ifndef GET_OFFSET_ANGLE
  PID_TYPE error = kalmanangley - target;
  PID_TYPE val;
  gap = PID_TYPE (timer - previous);
  if (gap == 0) {
    gap = 0.1;
  }
  gap *= 0.001;
  Serial.println(gap*100, 5);

  pid.PID_cal(error, &val, gap);

  val = constrain(val, -255, 255);
  motor(val, val);
  previous = timer;

  PID_TYPE p, i, d;
  pid.PID_vals(&p, &i, &d);
#else
  Serial.print(kalmanangley);
  Serial.print("\n");
#endif
}






void motor(int lspd, int rspd) {
  L_Motor.wheel(lspd);
  R_Motor.wheel(rspd);
}
