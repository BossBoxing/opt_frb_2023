void Pid_twoSensor(int power) {
  error = ((S_L - diff_S_L) - (S_R - diff_S_R));
  P = error;
  I = I + previous_I;
  D = error - previous_error;

  if (keepingCan == true){ // ค่า pid ตอนยกกระป๋อง
    PID_value = (0.5 * P) + (0.5 * I) + (4 * D); // 0.25 0.5 0.42
  }
  else{ // ค่า pid ตอนไม่ได้หนีบหรือยกกระป๋อง
    PID_value = (0.2 * P) + (0.5 * I) + (4 * D); // 0.25 0.5 0.42
  }
  
  previous_I = I;
  previous_error = error;
  
  int left_motor_speed = power + PID_value;
  int right_motor_speed = power - PID_value;

  if (left_motor_speed > 255) {
    left_motor_speed = 255;
  }
  if (right_motor_speed > 255) {
    right_motor_speed = 255;
  }
  if (left_motor_speed < -255) {
    left_motor_speed = -255;
  }
  if (right_motor_speed < -255) {
    right_motor_speed = -255;
  }

  motor_speed(1, left_motor_speed);
  motor_speed(2, right_motor_speed);
}

void TrackTwoSensorTime(int Time) { // คำสั่งเดินตามเส้นไปข้างหน้าแบบช้าแบบกำหนดเวลา
  currentTime = millis();
  while (millis() - currentTime < Time) {
    Pid_twoSensor(200);
    delay(1);
    //looptime++;
  }
}
