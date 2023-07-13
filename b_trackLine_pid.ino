////////////////// PID //////////////////

int error_value_front,error_value_back;

void getErrorFront(){

  // 1 0 0 0 0
  if (S_LL < Ref_LL && 
      S_L > Ref_L &&
      S_C > Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_front = -4;
  }
  else if (S_LL < Ref_LL && 
      S_L < Ref_L &&
      S_C > Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_front = -3;
  }
  else if (S_LL > Ref_LL && 
      S_L < Ref_L &&
      S_C > Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_front = -2;
  }
  else if (S_LL > Ref_LL && 
      S_L < Ref_L &&
      S_C < Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_front = -1;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C < Ref_C &&
      S_R > Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_front = 0;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C < Ref_C &&
      S_R < Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_front = 1;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C > Ref_C &&
      S_R < Ref_R &&
      S_RR > Ref_RR )
  {
    error_value_front = 2;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C > Ref_C &&
      S_R < Ref_R &&
      S_RR < Ref_RR )
  {
    error_value_front = 3;
  }
  else if (S_LL > Ref_LL && 
      S_L > Ref_L &&
      S_C > Ref_C &&
      S_R > Ref_R &&
      S_RR < Ref_RR )
  {
    error_value_front = 4;
  }

  else if (S_LL < Ref_LL && 
      S_L < Ref_L &&
      S_C < Ref_C &&
      S_R < Ref_R &&
      S_RR < Ref_RR )
  {
    error_value_front = 0;
  }
}

void getErrorBack(){
  if (S_B_L < Ref_B_L &&
      S_B_C > Ref_B_C &&
      S_B_R > Ref_B_R )
  {
    error_value_back = -2;
  }
  else if (S_B_L < Ref_B_L &&
      S_B_C < Ref_B_C &&
      S_B_R > Ref_B_R )
  {
    error_value_back = -1;
  }
  else if (S_B_L > Ref_B_L &&
      S_B_C < Ref_B_C &&
      S_B_R > Ref_B_R )
  {
    error_value_back = 0;
  }
  else if (S_B_L > Ref_B_L &&
      S_B_C < Ref_B_C &&
      S_B_R < Ref_B_R )
  {
    error_value_back = 1;
  }
  else if (S_B_L > Ref_B_L &&
      S_B_C > Ref_B_C &&
      S_B_R < Ref_B_R )
  {
    error_value_back = 2;
  }
  else if (S_B_L < Ref_B_L &&
      S_B_C < Ref_B_C &&
      S_B_R < Ref_B_R )
  {
    error_value_back = 0;
  }
}

void calculate_pid(int power) {
  getErrorFront();
  error = error_value_front;
  P = error;
  I = I + previous_I;
  D = error - previous_error;
  
  PID_value = (Kp_normal * P) + (Ki_normal * I) + (Kd_normal * D);
  
  previous_I = I;
  previous_error = error;
}
void motor_control(int power) {
  int left_motor_speed = power + PID_value;
  int right_motor_speed = power - PID_value;

  constrain(left_motor_speed,-255,255);
  constrain(right_motor_speed,-255,255);

  motor_speed(1, left_motor_speed);
  motor_speed(2, right_motor_speed);
}
void Pid(int power) {
  calculate_pid(power);
  motor_control(power);
}
void PidTime(int power, unsigned int Time) {
  currentTime = millis();
  while (millis() - currentTime < Time) {
    Pid(power);
  }
}
void calculate_pid_B(int power) {
  getErrorBack();
  error = error_value_back;
  P = error;
  I = I + previous_I;
  D = error - previous_error;
  
  PID_value = (30.0 * P) + (0.0 * I) + (35.0 * D);
  
  previous_I = I;
  previous_error = error;
}
void motor_control_B(int power) {
  int left_motor_speed = power - PID_value;
  int right_motor_speed = power + PID_value;

  constrain(left_motor_speed,-255,255);
  constrain(right_motor_speed,-255,255);

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
  Pid(200);
}
void TrackSlow() { // คำสั่งเดินตามเส้นไปข้างหน้าแบบช้า
  Pid(160);
}
void TrackCan() { // คำสั่งเดินตามเส้นไปข้างหน้าแบบช้า
  Pid(70);
}
void TrackCanYellow() { // คำสั่งเดินตามเส้นไปข้างหน้าแบบช้า เข้าและออก พื้นที่สีเหลือง
  Pid(50);
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
