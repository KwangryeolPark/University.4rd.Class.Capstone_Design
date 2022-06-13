/*
  Copyright 2022 Kwangryeol Park. All rights reserved.
  
  Owner: Kwangryeol Park.
  Email: pkr7098@gmail.com
  
  2022-06-13
*/

#ifndef _PID_H
#define _PID_H

typedef double PID_TYPE;

#define Kc  90.0
#define Tc  0.45
/*
const PID_TYPE P_gain = 90 * 0.6;
const PID_TYPE I_gain = P_gain * 2 / Tc;//0.9;
const PID_TYPE D_gain = P_gain * Tc * 0.125;//43;
*/

const PID_TYPE P_gain = 75;
const PID_TYPE I_gain = 260;//0.9;
const PID_TYPE D_gain = 0.7;//43;

class PID {
  public:
    PID();
    void PID_cal(PID_TYPE error, PID_TYPE* pid, PID_TYPE gap);
    void PID_vals(PID_TYPE* p, PID_TYPE* i, PID_TYPE* d);

  private:
    PID_TYPE  previous_error;
    PID_TYPE  I_temp;
    PID_TYPE  P_control, I_control, D_control;
};

PID::PID() {
  previous_error = 0;
  I_temp = 0;
};

void PID::PID_cal(PID_TYPE error, PID_TYPE* pid, PID_TYPE gap) {
  I_temp += (error * gap);
  *pid = (P_control = P_gain * error) + (I_control = I_gain * (I_temp)) + (D_control = D_gain * ((error - previous_error) / gap));
  previous_error = error;
};

void PID::PID_vals(PID_TYPE* p, PID_TYPE* i, PID_TYPE* d) {
  *p = P_control;
  *i = I_control;
  *d = D_control;
}



#endif
