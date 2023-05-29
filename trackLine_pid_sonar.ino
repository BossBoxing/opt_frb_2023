void calculate_pid_Sonar(int power) {
  getErrorFront();
  error = error_value_front;
  P = error;
  I = I + previous_I;
  D = error - previous_error;
  
  PID_value = (10.0 * P) + (0.0 * I) + (0.0 * D);
  
  previous_I = I;
  previous_error = error;
}
void motor_control_Sonar(int power) {
  int left_motor_speed = power + PID_value;
  int right_motor_speed = power - PID_value;

  motor_speed(1, constrain(left_motor_speed,-255,255));
  motor_speed(2, constrain(right_motor_speed,-255,255));
}
void Pid_Sonar(int power) {
  calculate_pid_Sonar(power);
  motor_control_Sonar(power);
}
