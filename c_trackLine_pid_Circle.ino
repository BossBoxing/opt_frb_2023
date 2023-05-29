int error_value_circle_L, error_value_circle_R;

///////////////////////// Left Side

void getErrorCircle_L(){

  // 1 0 0 0 0
  
  if (S_LL > Ref_LL && 
      S_L < Ref_L &&
      S_C > Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_L = -2;
  }
  else if (S_LL > Ref_LL && 
      S_L < Ref_L &&
      S_C < Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_L = -1;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C < Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_L = 0;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C < Ref_C &&
      S_R < Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_L = 1;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C > Ref_C &&
      S_R < Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_L = 2;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C > Ref_C &&
      S_R < Ref_R &&
      S_RR < Ref_RR )
  {
    error_value_circle_L = 3;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C > Ref_C &&
      S_R > Ref_R &&
      S_RR < Ref_RR )
  {
    error_value_circle_L = 4;
  }

  else if (S_LL < Ref_LL && 
      S_L < Ref_L &&
      S_C < Ref_C &&
      S_R < Ref_R &&
      S_RR < Ref_RR )
  {
    error_value_circle_L = 0;
  }
}

void calculate_pid_circle_L(int power) {
  getErrorCircle_L();
  error = error_value_circle_L;
  P = error;
  I = I + previous_I;
  D = error - previous_error;
  
  PID_value = (50.0 * P) + (0.0 * I) + (65.0 * D);
  
  previous_I = I;
  previous_error = error;
}
void Pid_Circle_L(int power) {
  calculate_pid_circle_L(power);
  motor_control(power);
}

//////////////////////////////////

///////////////////////// Right Side

void getErrorCircle_R(){
  // 1 0 0 0 0
  if (S_LL < Ref_LL && 
      S_L > Ref_L &&
      S_C > Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_R = -4;
  }
  else if (S_LL < Ref_LL && 
      S_L < Ref_L &&
      S_C > Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_R = -3;
  }
  else if (S_LL > Ref_LL && 
      S_L < Ref_L &&
      S_C > Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_R = -2;
  }
  else if (S_LL > Ref_LL && 
      S_L < Ref_L &&
      S_C < Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_R = -1;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C < Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_R = 0;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C < Ref_C &&
      S_R < Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_R = 1;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C > Ref_C &&
      S_R < Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_circle_R = 2;
  }

  else if (S_LL < Ref_LL && 
      S_L < Ref_L &&
      S_C < Ref_C &&
      S_R < Ref_R &&
      S_RR < Ref_RR )
  {
    error_value_circle_R = 0;
  }
}

void calculate_pid_circle_R(int power) {
  getErrorCircle_R();
  error = error_value_circle_R;
  P = error;
  I = I + previous_I;
  D = error - previous_error;
  
  PID_value = (50.0 * P) + (0.0 * I) + (65.0 * D);
  
  previous_I = I;
  previous_error = error;
}
void Pid_Circle_R(int power) {
  calculate_pid_circle_R(power);
  motor_control(power);
}

//////////////////////////////////////


void PidCircle_L_Time(int power, unsigned int Time) {
  currentTime = millis();
  while (millis() - currentTime < Time) {
    Pid_Circle_L(power);
  }
}

void PidCircle_R_Time(int power, unsigned int Time) {
  currentTime = millis();
  while (millis() - currentTime < Time) {
    Pid_Circle_R(power);
  }
}
