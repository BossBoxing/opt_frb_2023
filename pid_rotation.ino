int power_rotation = 70; // ความเร็วในการเลี้ยว
int diff_rotation = 6; // ค่าความต่าง เพื่อให้เซนเซอร์รู้ว่า ตรงเส้น

int cal_error_for_turn() {
  if (S_L < Ref_L) {
    return -S_L;
  }
  else if (S_LL < Ref_LL) {
    return -(S_LL + Max_LL);
  }
  else if (S_R < Ref_R) {
    return (S_R);
  }
  else if (S_RR < Ref_RR) {
    return (S_RR + Max_RR);
  }
  else {
      return (S_L - S_R);
  }
}

void pidRotateL() {

  int power = power_rotation;
  int diff = diff_rotation;

  boolean rotated = true;
  boolean flag_rotated_L = false;
  boolean flag_rotated_LL = false;

  int val_error = 0;
  while ( S_L < Ref_L){
    motor(1, -power);
    motor(2, power);
  }

  while (rotated) {

    if (S_LL > Ref_LL && flag_rotated_LL == false) {
      val_error = S_LL + S_L;
    }
    if (S_LL < Ref_LL && flag_rotated_LL == false) {
      flag_rotated_LL = true;
    }

    if (S_L > Ref_L && flag_rotated_L == false) {
      val_error = S_L;
    }
    if (S_L < Ref_L && flag_rotated_L == false) {
      flag_rotated_L = true;
    }

    if ( flag_rotated_L == true && flag_rotated_LL == true) {
      rotated = false;
    }


    // Calculate
    error = val_error;
    P = error;
    // kI = kI + previous_I;
    D = error - previous_error;
    // PID_value = (Kp * kP) + (Ki * kI) + (Kd * kD);
    PID_value = (P * 0.5) + (D * 0.05);
    // previous_I = kI;
    previous_error = error;

    int left_motor_speed = power + PID_value;
    int right_motor_speed = power + PID_value;

    if (left_motor_speed > 100) {
      left_motor_speed = 100;
    }
    if (right_motor_speed > 100) {
      right_motor_speed = 100;
    }

    motor(1, -left_motor_speed);
    motor(2, right_motor_speed);
  }

  while ( (S_L - S_R) < -(diff) || (S_L - S_R) > (diff) ) {
    
    // Calculate
    error = cal_error_for_turn();
    P = error;
    I = I + previous_I;
    D = error - previous_error;
    // PID_value = (Kp * kP) + (Ki * kI) + (Kd * kD);
    PID_value = (P * 0.5) + (I * 0.01)  + (D * 0.05);
    previous_I = I;
    previous_error = error;

    int left_motor_speed = power + PID_value;
    int right_motor_speed = power - PID_value;

    if (left_motor_speed > 100) {
      left_motor_speed = 100;
    }
    if (right_motor_speed > 100) {
      right_motor_speed = 100;
    }
    if (left_motor_speed < -100) {
      left_motor_speed = -100;
    }
    if (right_motor_speed < -100) {
      right_motor_speed = -100;
    }

    if (cal_error_for_turn() > 0) {
      left_motor_speed = left_motor_speed;
      right_motor_speed = -right_motor_speed;
    }
    if (cal_error_for_turn() < 0) {
      left_motor_speed = -left_motor_speed;
      right_motor_speed = right_motor_speed;
    }

    motor(1, left_motor_speed);
    motor(2, right_motor_speed);
  }
}

void pidRotateR() {
  
  int power = power_rotation;
  int diff = diff_rotation;

  boolean rotated = true;
  boolean flag_rotated_R = false;
  boolean flag_rotated_RR = false;

  int val_error = 0;
  while ( S_R < Ref_R){
    motor(1, power);
    motor(2, -power);
  }

  while (rotated) {

    if (S_RR > Ref_RR && flag_rotated_RR == false) {
      val_error = S_RR + S_R;
    }
    if (S_RR < Ref_RR && flag_rotated_RR == false) {
      flag_rotated_RR = true;
    }

    if (S_R > Ref_R && flag_rotated_R == false) {
      val_error = S_R;
    }
    if (S_R < Ref_R && flag_rotated_R == false) {
      flag_rotated_R = true;
    }

    if ( flag_rotated_R == true && flag_rotated_RR == true) {
      rotated = false;
    }


    // Calculate
    error = val_error;
    P = error;
    // kI = kI + previous_I;
    // kD = error - previous_error;
    // PID_value = (Kp * kP) + (Ki * kI) + (Kd * kD);
    PID_value = (P * 1);
    // previous_I = kI;
    // previous_error = error;

    int left_motor_speed = power + PID_value;
    int right_motor_speed = power + PID_value;

    if (left_motor_speed > 100) {
      left_motor_speed = 100;
    }
    if (right_motor_speed > 100) {
      right_motor_speed = 100;
    }

    motor(1, left_motor_speed);
    motor(2, -right_motor_speed);
  }

  while ( (S_L - S_R) < -(diff) || (S_L - S_R) > (diff) ) {
    
    // Calculate
    error = S_L - S_R;
    P = error;
    // kI = kI + previous_I;
    // kD = error - previous_error;
    // PID_value = (Kp * kP) + (Ki * kI) + (Kd * kD);
    PID_value = (P * 0.9);
    // previous_I = kI;
    // previous_error = error;

    int left_motor_speed = power + PID_value;
    int right_motor_speed = power + PID_value;

    if (left_motor_speed > 100) {
      left_motor_speed = 100;
    }
    if (right_motor_speed > 100) {
      right_motor_speed = 100;
    }

    motor(1, -left_motor_speed);
    motor(2, right_motor_speed);
  }
}
