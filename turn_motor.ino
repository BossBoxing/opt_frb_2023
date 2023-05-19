
void TR90() { // คำสั่งเลี้ยวขวา 90 องศา
  Pause(30);
  //motor(1, Slow_L); motor(2, -(Slow_R + 8)); delay(110);
  motor(1, Slow_L); motor(2, -(Slow_R + 8)); delay(20);
  while (S_R <= Ref_R) {
    motor(1, Slow_L);
    motor(2, -(Slow_R + 8));
    delay(10);
  }
  while (S_R >= Ref_R) {
    motor(1, Slow_L);
    motor(2, -(Slow_R + 15));
    delay(10);
  }

  // break
  motor(1, -(Slow_L + 15));
  motor(2, Slow_R);
  delay(30);
  Pause(30);
}
void TL90() { // คำสั่งเลี้ยวซ้าย 90 องศา
  Pause(30);
  // motor(1, -(Slow_L + 8)); motor(2, Slow_R); delay(110);
  motor(1, -(Slow_L + 8)); motor(2, Slow_R); delay(20);
  while (S_L <= Ref_L) {
    motor(1, -(Slow_L + 8));
    motor(2, Slow_R);
    delay(10);
  }
  while (S_L >= Ref_L) {
    motor(1, -(Slow_L + 15));
    motor(2, Slow_R);
    delay(10);
  }

  // break
  motor(1, Slow_L);
  motor(2, -(Slow_R + 15));
  delay(30);
  Pause(30);
}
void TR90_Pre() { // คำสั่งเลี้ยวขวา 90 องศา โดยให้เลี้ยวออกไปก่อนจะจัเซนเซอร
  Pause(30);
  //motor(1, Slow_L); motor(2, -(Slow_R + 8)); delay(110);
  motor(1, Slow_L); motor(2, -(Slow_R + 8)); delay(100);
  while (S_R <= Ref_R) {
    motor(1, Slow_L);
    motor(2, -(Slow_R + 8));
    delay(10);
  }
  while (S_R >= Ref_R) {
    motor(1, Slow_L);
    motor(2, -(Slow_R + 15));
    delay(10);
  }
  
  // break
  motor(1, -(Slow_L + 15));
  motor(2, Slow_R);
  delay(30);
  Pause(30);
}
void TL90_Pre() { // คำสั่งเลี้ยวซ้าย 90 องศา โดยให้เลี้ยวออกไปก่อนจะจัเซนเซอร์
  Pause(30);
  // motor(1, -(Slow_L + 8)); motor(2, Slow_R); delay(110);
  motor(1, -(Slow_L + 8)); motor(2, Slow_R); delay(100);
  while (S_L <= Ref_L) {
    motor(1, -(Slow_L + 8));
    motor(2, Slow_R);
    delay(10);
  }
  while (S_L >= Ref_L) {
    motor(1, -(Slow_L + 15));
    motor(2, Slow_R);
    delay(10);
  }

  // break
  motor(1, Slow_L);
  motor(2, -(Slow_R + 15));
  delay(30);
  Pause(30);
}
