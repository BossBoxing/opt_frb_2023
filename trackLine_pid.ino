////////////////// PID //////////////////

void calculate_pid(int power) {
  error = ( ((S_LL - diff_S_LL) + (S_L - diff_S_L)) - ((S_R - diff_S_R) + (S_RR - diff_S_RR)) );
  P = error;
  I = I + previous_I;
  D = error - previous_error;
  
  if (keepingCan == true){ // ค่า pid ตอนยกกระป๋อง
    PID_value = (0.7 * P) + (0.5 * I) + (5 * D); // 0.25 0.5 0.42
  }
  else{ // ค่า pid ตอนไม่ได้หนีบหรือยกกระป๋อง
    PID_value = (1.5 * P) + (0.5 * I) + (10 * D); // 0.25 0.5 0.42
  }
  
  previous_I = I;
  previous_error = error;
}
void motor_control(int power) {
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
void Pid(int power) {
  calculate_pid(power);
  motor_control(power);
}

void Pid_Circle(int power) {

  error = ((((S_LL * 2) + S_L) ) - (S_R + (S_RR * 2)));
  P = error;
  I = I + previous_I;
  D = error - previous_error;
  PID_value = (0.7 * P) + (0.8 * I) + (1 * D); // 0.25 0.5 0.42
  previous_I = I;
  previous_error = error;

  motor_control(power);
}
void PidTime(int power, unsigned int Time) {
  currentTime = millis();
  while (millis() - currentTime < Time) {
    Pid(power);
  }
}
void calculate_pid_B(int power) {
  error = ((S_B_LL + S_B_L) - (S_B_R + S_B_RR));
  P = error;
  I = I + previous_I;
  D = error - previous_error;
  PID_value = (0.4 * P) + (0.5 * I) + (2 * D); // 0.25 0.5 0.42
  previous_I = I;
  previous_error = error;
}
void motor_control_B(int power) {
  int left_motor_speed = power - PID_value;
  int right_motor_speed = power + PID_value;

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

  motor_speed(1, -left_motor_speed);
  motor_speed(2, -right_motor_speed);
}
void Pid_B(int power) {
  calculate_pid_B(power);
  motor_control_B(power);
}
void PidTime_B(int power, unsigned int Time) {
  currentTime = millis();
  while (millis() - currentTime < Time) {
    Pid_B(power);
  }
}
void Track() { // คำสั่งเดินตามเส้นไปข้างหน้า
  Pid(180);
}
void TrackSlow() { // คำสั่งเดินตามเส้นไปข้างหน้าแบบช้า
  Pid(150);
}
void TrackCan() { // คำสั่งเดินตามเส้นไปข้างหน้าแบบช้า
  Pid(70);
}
void Track_B() { // คำสั่งเดินตามเส้นไปข้างหน้า
  Pid_B(180);
}
void TrackSlow_B() { // คำสั่งเดินตามเส้นไปข้างหน้าแบบช้า
  Pid_B(150);
}
void TrackSlower() { // คำสั่งเดินตามเส้นไปข้างหน้าเดินวงกลม
  Pid(70);
}
void TrackCircle() { // คำสั่งเดินตามเส้นไปข้างหน้าเดินวงกลม

  Pid_Circle(70);
}
void TrackCircle_R() {
  if (S_R <= Ref_R) {
    motor(1, 60);
    motor(2, 40);
    delay(10);
  }
  else if (S_RR <= Ref_RR) {
    motor(1, 60);
    motor(2, 20);
    delay(10);
  }
  else {
    motor(1, 5);
    motor(2, 60);
    delay(10);
  }
}
void TrackCircle_L() {
  if (S_L <= Ref_L) {
    motor(1, 40);
    motor(2, 60);
    delay(10);
  }
  else if (S_LL <= Ref_LL) {
    motor(1, 20);
    motor(2, 60);
    delay(10);
  }
  else {
    motor(1, 60);
    motor(2, 5);
    delay(10);
  }
}
void TrackTime(int Time) { // คำสั่งเดินตามเส้นไปข้างหน้าแบบกำหนดเวลา
  currentTime = millis();
  while (millis() - currentTime < Time) {
    Track();
    delay(1);
    // looptime++;
  }
}
void TrackSlowTime(int Time) { // คำสั่งเดินตามเส้นไปข้างหน้าแบบช้าแบบกำหนดเวลา
  currentTime = millis();
  while (millis() - currentTime < Time) {
    TrackSlow();
    delay(1);
    //looptime++;
  }
}
void TrackCircleTime(int Time) { // คำสั่งเดินตามเส้นไปข้างหน้าเดินวงกลมแบบกำหนดเวลา
  currentTime = millis();
  while (millis() - currentTime < Time) {
    TrackCircle();
    delay(1);
    //looptime++;
  }
}
void TrackSlowerTime(int Time) { // คำสั่งเดินตามเส้นไปข้างหน้าเดินวงกลมแบบกำหนดเวลา
  currentTime = millis();
  while (millis() - currentTime < Time) {
    TrackSlower();
    delay(1);
    //looptime++;
  }
}
void TrackCircle_L_Time(int Time) { // คำสั่งเดินตามเส้นไปข้างหน้าเดินวงกลมแบบกำหนดเวลา
  currentTime = millis();
  while (millis() - currentTime < Time) {
    TrackCircle_L();
    delay(1);
    //looptime++;
  }
}
void TrackCircle_R_Time(int Time) { // คำสั่งเดินตามเส้นไปข้างหน้าเดินวงกลมแบบกำหนดเวลา
  currentTime = millis();
  while (millis() - currentTime < Time) {
    TrackCircle_R();
    delay(1);
    //looptime++;
  }
}
