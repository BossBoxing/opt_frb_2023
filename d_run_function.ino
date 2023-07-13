void FF(int i) {
  currentTime = millis();
  while (1) {
    if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR)) {
      if (i == 1) {
        Fw(T1 + 10);
      }
      if (i == 2) {
        Fw(T2 + 10);
      }
      else if (i == 3) {
        Fw(T3 + 10);
      }
      else {
        while (S_LLL < Ref_LLL || S_RRR < Ref_RRR) {
          Track();
        }
        TrackSlowTime(100);
      }
      break;
    }
    TrackSlow();
  }
}
void FF_Slow() {
  while (S_RRR <= Ref_RRR) {
    Pid(70);
  }
  // int Time=900;
  while (1) {
    if (S_RRR <= Ref_RRR) {
      // currentTime = millis();

      while (S_LL <= Ref_LL || S_RR <= Ref_RR) {
        Pid(70);
      }
      TrackSlowTime(240);
      // while(S_LL >= Ref_LL || S_RR >= Ref_RR){TrackSlow();}
      // TrackSlowTime(100);
      break;
    }
    Pid(70);
  }
}
void LL(int i, int j) { //left
  if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR)) {
    TrackSlowTime(60);
  }
  if (i == 1) { //มุมฉาก
    while (1) {
      if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR))
      {
        Fw(T1);
//        while (S_LL > Ref_LL || S_RR > Ref_RR) {
//          TrackCan();
//        }
        Stop(100);
        if (j == 1) {
          TL90();
        }
        else if (j == 2) {
          TL90();
          TL90();
        }
        else {
          TL90();
          TL90();
          TL90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track();
    }
  }
  else if (i == 2) { //มุมแหลม
    while (1) {
      if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR))
      {
        Fw(T2);
        Stop(100);
        if (j == 1) {
          TL90_Pre();
        }
        else if (j == 2) {
          TL90_Pre();
          TL90();
        }
        else {
          TL90_Pre();
          TL90();
          TL90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track();
    }
  }
  else if (i == 3) { //มุมแหลมแบบคู่
    while (1) {
      if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR))
      {
        FwSlow(T3);
        Stop(100);
        if (j == 1) {
          TL90();
        }
        else if (j == 2) {
          TL90();
          TL90();
        }
        else {
          TL90();
          TL90();
          TL90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track();
    }
  }
  else {
    while (1) {
      if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR)) {
        //FwSlow(20);// TrackSlowTime(50);
        Stop(100);
        TL90();
        TrackSlowTime(100);
        // Stop(20);
        break;
      }
      TrackSlow();
    }
  }
}
void RR(int i, int j) { //right
  if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR)) {
    TrackSlowTime(60);
  }
  if (i == 1) { //มุมฉาก
    while (1) {
      if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR))
      {
         Fw(T1);
//        while (S_LL > Ref_LL || S_RR > Ref_RR) {
//          TrackCan();
//        }
        Stop(100);
        if (j == 1) {
          TR90();
        }
        else if (j == 2) {
          TR90();
          TR90();
        }
        else {
          TR90();
          TR90();
          TR90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track();
    }
  }
  else if (i == 2) { //มุมแหลม
    while (1) {
      if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR))
      {
        Fw(T2);
        Stop(100);
        if (j == 1) {
          TR90_Pre();
        }
        else if (j == 2) {
          TR90_Pre();
          TR90();
        }
        else {
          TR90_Pre();
          TR90();
          TR90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track();
    }
  }
  else if (i == 3) { //มุมแหลมแบบคู่
    while (1) {
      if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR))
      {
        // Pre_Turn 90 Degree
        FwSlow(T3);
        Stop(100);

        if (j == 1) {
          TR90();
        }
        else if (j == 2) {
          TR90();
          TR90();
        }
        else {
          TR90();
          TR90();
          TR90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track();
    }
  }
  else {
    while (1) {
      if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR)) {
        Stop(100);
        TR90();
        TrackSlowTime(100);
        break;
      }
      TrackSlow();
    }
  }
}

void B_LL(int i, int j) { //left
  // if ((S_B_LLL < Ref_B_LLL) || (S_B_RRR < Ref_B_RRR)) {
  //   TrackSlowTime(100);
  // }
  if (i == 1) { //มุมฉาก
    while (1) {
      if ((S_B_LLL < Ref_B_LLL) || (S_B_RRR < Ref_B_RRR))
      {
        BkSlow(T1);
        B_Stop(30);
        if (j == 1) {
          TL90();
        }
        else if (j == 2) {
          TL90();
          TL90();
        }
        else {
          TL90();
          TL90();
          TL90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track_B();
    }
  }
  else if (i == 2) { //มุมแหลม
    while (1) {
      if ((S_B_LLL < Ref_B_LLL) || (S_B_RRR < Ref_B_RRR))
      {
        BkSlow(T2);
        B_Stop(30);
        if (j == 1) {
          TL90();
        }
        else if (j == 2) {
          TL90();
          TL90();
        }
        else {
          TL90();
          TL90();
          TL90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track_B();
    }
  }
  else if (i == 3) { //มุมแหลมแบบคู่
    while (1) {
      if ((S_B_LLL < Ref_B_LLL) || (S_B_RRR < Ref_B_RRR))
      {
        BkSlow(T3);
        B_Stop(30);
        if (j == 1) {
          TL90();
        }
        else if (j == 2) {
          TL90();
          TL90();
        }
        else {
          TL90();
          TL90();
          TL90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track_B();
    }
  }
  else {
    while (1) {
      if ((S_B_LLL < Ref_B_LLL) || (S_B_RRR < Ref_B_RRR)) {
        // BkSlow(20);// TrackSlowTime(50);
        B_Stop(30);
        TL90_Pre();
        TrackSlowTime(100);
        // Stop(20);
        break;
      }
      Track_B();
    }
  }
}
void B_RR(int i, int j) { //right
  // if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR)) {
  //   TrackSlowTime(100);
  // }
  if (i == 1) { //มุมฉาก
    while (1) {
      if ((S_B_LLL < Ref_B_LLL) || (S_B_RRR < Ref_B_RRR))
      {
        BkSlow(T1);
        B_Stop(30);
        if (j == 1) {
          TR90_Pre();
        }
        else if (j == 2) {
          TR90_Pre();
          TR90();
        }
        else {
          TR90_Pre();
          TR90();
          TR90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track_B();
    }
  }
  else if (i == 2) { //มุมแหลม
    while (1) {
      if ((S_B_LLL < Ref_B_LLL) || (S_B_RRR < Ref_B_RRR))
      {
        BkSlow(T2);
        B_Stop(30);
        if (j == 1) {
          TR90();
        }
        else if (j == 2) {
          TR90();
          TR90();
        }
        else {
          TR90();
          TR90();
          TR90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track_B();
    }
  }
  else if (i == 3) { //มุมแหลมแบบคู่
    while (1) {
      if ((S_B_LLL < Ref_B_LLL) || (S_B_RRR < Ref_B_RRR))
      {
        BkSlow(T3);
        B_Stop(30);
        if (j == 1) {
          TR90();
        }
        else if (j == 2) {
          TR90();
          TR90();
        }
        else {
          TR90();
          TR90();
          TR90();
        }
        //Stop(20);
        TrackSlowTime(200);
        break;
      }
      Track_B();
    }
  }
  else {
    while (1) {
      if ((S_B_LLL < Ref_B_LLL) || (S_B_RRR < Ref_B_RRR)) {
        // BkSlow(20);// TrackSlowTime(50);
        B_Stop(30);
        TR90_Pre();
        TrackSlowTime(100);
        // Stop(20);
        break;
      }
      TrackSlow_B();
    }
  }
}

void LL_SM() { // คำสั่งเลี้ยวซ้าย สี่เหลี่ยมเล็ก
  while (S_LL > Ref_LL || S_L > Ref_L) {
    TrackSlow();
  }
  FwSlow(T_SM);// TrackSlowTime(50);
  Stop(10);
  TL90_SM();
  while (S_LLL <= Ref_LLL) {
    TrackSlow();
  }
  TrackSlowTime(60);
}
void RR_SM() { // คำสั่งเลี้ยวขวา สี่เหลี่ยมเล็ก
  while (S_RR > Ref_RR || S_R > Ref_R) {
    TrackSlow();
  }
  FwSlow(T_SM);// TrackSlowTime(50);
  Stop(10);
  TR90_SM();
  while (S_RRR <= Ref_RRR) {
    TrackSlow();
  }
  TrackSlowTime(60);
}
void LL_SM(int Time) { // คำสั่งเลี้ยวซ้าย สี่เเหลี่ยมเล็ก กำหนดเวลาเดินหน้าก่อนเลี้ยว
  while (S_LL > Ref_LL || S_L > Ref_L) {
    TrackSlow();
  }
  FwSlow(T_SM);// TrackSlowTime(50);
  Stop(10);
  TL90_SM();
  while (S_LLL <= Ref_LLL) {
    TrackSlow();
  }
}
void RR_SM(int Time) { // คำสั่งเลี้ยวขวา สี่เเหลี่ยมเล็ก กำหนดเวลาเดินหน้าก่อนเลี้ยว
  while (S_RR > Ref_RR || S_R > Ref_R) {
    TrackSlow();
  }
  FwSlow(T_SM);// TrackSlowTime(50);
  Stop(10);
  TR90_SM();
  while (S_RRR <= Ref_RRR) {
    TrackSlow();
  }
}
void FF_SM(int x) { // คำสั่งเดินหน้า สี่เหลี่ยมเล็ก ใส่ 1 เพื่อใช้เซนเซอร์ซ้ายจับเส้น อื่นๆ เพื่อใช้ขวาจับเส้น
  if (x == 1) {
    while (S_LL > Ref_LL || S_L > Ref_L) {
      TrackSlow();
    }
    while (S_LLL >= Ref_LLL) {
      TrackSlow();
    }
    while (S_LLL <= Ref_LLL) {
      TrackSlow();
    }
  }
  else {
    while (S_RR > Ref_RR || S_R > Ref_R) {
      TrackSlower();
    }
    while (S_RRR >= Ref_RRR) {
      TrackSlower();
    }
    while (S_RRR <= Ref_RRR) {
      TrackSlower();
    }
  }
  // TrackSlowTime(20);
}
void LL_SM_Caribate() { // เลี้ยวซ้าย สี่เหลี่ยมเล็ก และมีการ Caribate ตอนสุดท้าย
  LL_SM();
  while (S_RRR <= Ref_RRR) {
    TrackSlow();
  }
  TrackSlowTime(100);
}
void RR_SM_Caribate() { // เลี้ยวขวา สี่เหลี่ยมเล็ก และมีการ Caribate ตอนสุดท้าย
  RR_SM();
  while (S_LLL <= Ref_LLL) {
    TrackSlow();
  }
  TrackSlowTime(100);
}
void SM(int i) { //square small
  while (S_LL > Ref_LL || S_RR > Ref_RR) {
    TrackSlow();
  }
  if (i == 1) {
    LL_SM();
    RR_SM();
    LL_SM_Caribate();
  }
  else if (i == 2) {
    RR_SM();
    LL_SM();
    FF_SM(2);
    LL_SM();
    RR_SM_Caribate();
  }
  else {
    RR_SM();
    LL_SM();
    RR_SM_Caribate();
  }
}

void SM_Pure(int i) { //square small
  while (S_LL > Ref_LL || S_RR > Ref_RR) {
    TrackSlow();
  }
  if (i == 1) {
    LL_SM();
    RR_SM();
    LL_SM();
  }
  else if (i == 2) {
    RR_SM();
    LL_SM();
    FF_SM(2);
    LL_SM();
    RR_SM();
  }
  else {
    RR_SM();
    LL_SM();
    RR_SM();
  }
}

void CC(int x, int y) { //circle
  // TrackSlowTime(60);
  if (S_LLL < Ref_LLL) {
    while (S_LLL <= Ref_LLL) {
      TrackSlow();
    }
  }
  else if (S_RRR < Ref_RRR) {
    while (S_RRR <= Ref_RRR) {
      TrackSlow();
    }
  }
  ///////////////1////////////////
  if ((x == 1) && (y == 4)) { //1 > 4
    LL(4, 1);

    while (S_LLL >= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LLL <= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LLL >= Ref_LLL)
    {
      Pid_Circle_L(120);
    }

    TL90_Pre();
    PidCircle_L_Time(180, 100);

    while (S_LLL <= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LL >= Ref_LL || S_L >= Ref_L)
    {
      Pid_Circle_L(150);
    }
    // Stop(50);
    FwSlow(T_CC);
    TL90_Pre();
  }
  else if ((x == 1) && (y == 5)) { //1 > 5
    RR(4, 1);

    while (S_RRR >= Ref_RRR)
    {
      Pid_Circle_R(180);
    }
    while (S_RRR <= Ref_RRR)
    {
      Pid_Circle_R(180);
    }
    while (S_RRR >= Ref_RRR)
    {
      Pid_Circle_R(120);
    }

    TR90_Pre();
    PidCircle_R_Time(180, 100);

    while (S_RRR <= Ref_RRR)
    {
      Pid_Circle_R(180);
    }
    while (S_RR >= Ref_RR || S_R >= Ref_R)
    {
      Pid_Circle_R(150);
    }
    // Stop(50);
    FwSlow(T_CC);
    TR90_Pre();
  }
  else if ((x == 1) && (y == 6)) { //1 > 6
    LL(4, 1);

    while (S_LLL >= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LLL <= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LLL >= Ref_LLL)
    {
      Pid_Circle_L(120);
    }

    TL90_Pre();
    PidCircle_L_Time(180, 100);

    while (S_LLL <= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LLL >= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LLL <= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LL >= Ref_LL || S_L >= Ref_L)
    {
      Pid_Circle_L(150);
    }
    // Stop(50);
    FwSlow(T_CC);
    TL90_Pre();

    while (S_LL >= Ref_LL || S_RR >= Ref_RR) {
      TrackSlow();
    }
  }
  ///////////////2/////////////////
  else if ((x == 2) && (y == 3)) { //2 > 3
    // no_can10_to_can11 usefully
    LL(4, 1);
    while (S_L >= Ref_L || S_LL >= Ref_LL) {
      TrackCircle_L();
    }

    while (S_LL <= Ref_LL) {
      Fw(10);
    }
    // TrackCircle_L_Time(180, 200);
    while (S_L >= Ref_L || S_LL >= Ref_LL) {
      TrackCircle_L();
    }

    while (S_LLL >= Ref_LLL) {
      TrackCircle_L();
    }

    Stop(30);
    TL90();
    Stop(30);

    while (S_LLL <= Ref_LLL || S_RRR <= Ref_RRR) {
      TrackSlow();
    }
    TrackSlowTime(200);
  }
  else if ((x == 2) && (y == 4)) { //2 > 4
    // No Use
  }
  else if ((x == 2) && (y == 5)) { //2 > 5
    // No Use
  }
  else if ((x == 2) && (y == 6)) { //2 > 6
    // go to placecan [10]
    LL(4, 1);

    while (S_LLL <= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LLL >= Ref_LLL)
    {
      Pid_Circle_L(120);
    }

    TL90_Pre();
    PidCircle_L_Time(180, 100);

    while (S_LLL <= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LLL >= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LLL <= Ref_LLL)
    {
      Pid_Circle_L(180);
    }
    while (S_LL >= Ref_LL || S_L >= Ref_L)
    {
      Pid_Circle_L(150);
    }
    // Stop(50);
    FwSlow(T_CC);
    TL90_Pre();

    while (S_LL >= Ref_LL || S_RR >= Ref_RR) {
      TrackSlow();
    }
  }
  ////////////////3///////////////
  else if ((x == 3) && (y == 4)) { //3 > 4
    // no_can8_to_can9 usefully
    RR(4, 1);
    while (S_R >= Ref_R || S_RR >= Ref_RR) {
      TrackCircle_R();
    }

    while (S_RR <= Ref_RR) {
      Fw(10);
    }
    TrackCircle_R_Time(200);
    // while(S_R >= Ref_R || S_RR >= Ref_RR){TrackCircle_R();}

    while (S_LLL >= Ref_LLL) {
      TrackCircle_R();
    }
    while (S_LLL <= Ref_LLL) {
      Fw(10);
    }

    // TrackCircle_L_Time(180, 200);
    while (S_L >= Ref_L || S_LL >= Ref_LL) {
      TrackCircle_L();
    }
    while (S_LLL >= Ref_LLL) {
      TrackCircle_L();
    }

    Stop(30);
    TL90();
    Stop(30);

    while (S_LLL <= Ref_LLL || S_RRR <= Ref_RRR) {
      TrackSlow();
    }
    TrackSlowTime(200);
  }
  else if ((x == 3) && (y == 5)) { //3 > 5
    // No Use
  }
  else { //3 > 6
    RR(4, 1);

    while (S_RRR <= Ref_RRR)
    {
      Pid_Circle_R(180);
    }
    while (S_RRR >= Ref_RRR)
    {
      Pid_Circle_R(120);
    }

    TR90_Pre();
    PidCircle_R_Time(180, 100);

    while (S_RRR <= Ref_RRR)
    {
      Pid_Circle_R(180);
    }
    while (S_RRR >= Ref_RRR)
    {
      Pid_Circle_R(180);
    }
    while (S_RRR <= Ref_RRR)
    {
      Pid_Circle_R(180);
    }
    while (S_RR >= Ref_RR || S_R >= Ref_R)
    {
      Pid_Circle_R(150);
    }
    // Stop(50);
    FwSlow(T_CC);
    TR90_Pre();

    while (S_LL >= Ref_LL || S_RR >= Ref_RR) {
      TrackSlow();
    }
  }
}
void InCan(int i) {
  /*if ((i != 5) || (i != 6)) {
    TrackTime(100);
    }*/
  // Stop(50);
  sDown();

  while (S_Can >= SS_Can + 8) { // 5
    TrackSlow();
  }
  while (1) {
    if (S_Can < SS_Can)
    {
      Stop(50);
      if (i == 1) {
        Stop(20);
        Keep();
        Stop(20);
        TL90_Pre();
        TrackSlowTime(100);
        // Stop(20);
      }
      else if (i == 2) {
        Stop(20);
        Keep();
        Stop(20);
        TR90_Pre();
        TrackSlowTime(100);
        // Stop(20);
      }
      else {
        Stop(20);
        Keep();
        Stop(20);
      }
      break;
    }
    Pid(70);
  }
}
void InCan_checkCan(int i, int can, boolean tracked) { // checkCan
  int time = 0;
  boolean flagCan = true;

  sDown();

  //  while (S_Can >= SS_Can + 4)
  //  {
  //    TrackSlow(); delay(1);
  //
  //    if (S_LL > Ref_LL && S_L > Ref_L && S_R > Ref_R && S_RR > Ref_RR)
  //    {
  //      // time++;
  //    }
  //    else
  //    {
  //      time = 0;
  //    }
  //
  //    if (time > 35) // 15
  //    { // no can
  //      noCan(can);
  //      can_check[can] = 1;
  //      flagCan = false;
  //      break;
  //    }
  //  }
  while (flagCan == true)
  {
    int POWER = constrain(map(S_Can, 0, 16, 10, 180), 0, 180);
    Pid(POWER);

    if (S_Can <= SS_Can)
    {
      Pause(50);
      if (i == 1)
      {
        Pause(20);
        if (tracked) {
          Keep_Track();
        }
        else {
          Keep();
        }
        Stop(20);
        TL90_Pre();
        TrackSlowTime(100);
      }
      else if (i == 2)
      {
        Pause(20);
        if (tracked) {
          Keep_Track();
        }
        else {
          Keep();
        }
        Stop(20);
        TR90_Pre();
        TrackSlowTime(100);
      }
      else
      {
        Pause(20);
        if (tracked) {
          Keep_Track();
        }
        else {
          Keep();
        }
        Stop(20);
      }
      break;
    }
  }
}

void PlaceYellow(boolean isFinish) {
  Pause(30);

  if (y_count == 0 || y_count == 3 || y_count == 7)
  {
    Place();

    motor(1, 0); motor(2, 40);
    delay(100);
    Pause(30);

    motor(1, 40); motor(2, 40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, -40);
    delay(60);
    Pause(30);

    motor(1, 0); motor(2, -40);
    delay(100);
    Pause(30);
  }
  else if (y_count == 1 || y_count == 4 || y_count == 8)
  {
    Place();

    motor(1, 40); motor(2, 0);
    delay(100);
    Pause(30);

    motor(1, 40); motor(2, 40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, -40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, 0);
    delay(100);
    Pause(30);
  }
  else
  {
    Place();

    motor(1, 40); motor(2, 40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, -40);
    delay(60);
    Pause(30);
  }

  while (S_B_LLL >= Ref_B_LLL) {
    BkSlow(10); // motor(1, -80);  motor(2, -80); delay(150);
  }
  Pause(30);

  if (isFinish == false)
  {
    TL90();
    Pause(10);
  }
  sUp();
  sSet();

  y_count++;
}

void PlaceRed() {
  Pause(30);

  if (r_count == 0 || r_count == 3 || r_count == 7)
  {
    Place();

    motor(1, 0); motor(2, 40);
    delay(100);
    Pause(30);

    motor(1, 40); motor(2, 40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, -40);
    delay(60);
    Pause(30);

    motor(1, 0); motor(2, -40);
    delay(100);
    Pause(30);
  }
  else if (r_count == 1 || r_count == 4 || r_count == 8)
  {
    Place();

    motor(1, 40); motor(2, 0);
    delay(100);
    Pause(30);

    motor(1, 40); motor(2, 40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, -40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, 0);
    delay(100);
    Pause(30);
  }
  else
  {
    Place();

    motor(1, 40); motor(2, 40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, -40);
    delay(60);
    Pause(30);
  }
  Pause(30);
  // sUp();
  // sSet();

  r_count++;
}

void PlaceGreen() {
  Pause(30);

  if (g_count == 0 || g_count == 3 || g_count == 7)
  {
    Place();

    motor(1, 0); motor(2, 40);
    delay(100);
    Pause(30);

    motor(1, 40); motor(2, 40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, -40);
    delay(60);
    Pause(30);

    motor(1, 0); motor(2, -40);
    delay(100);
    Pause(30);
  }
  else if (g_count == 1 || g_count == 4 || g_count == 8)
  {
    Place();

    motor(1, 40); motor(2, 0);
    delay(100);
    Pause(30);

    motor(1, 40); motor(2, 40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, -40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, 0);
    delay(100);
    Pause(30);
  }
  else
  {
    Place();

    motor(1, 40); motor(2, 40);
    delay(60);
    Pause(30);

    motor(1, -40); motor(2, -40);
    delay(60);
    Pause(30);
  }

  Pause(30);
  // sUp();
  // sSet();

  g_count++;
}


void PlaceCan(String s) {
  //  if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR)) {
  //    TrackSlowTime(30);
  //  }
  Pause(10);

  if (s == "Y" || s == "Y_Finish") {
    sDown_Yellow();
  }
  else {
    sDown();
  }

  while (1) {

    if (s == "Y" || s == "Y_Finish") {
      TrackCanYellow();
    }
    else {
      TrackCan();
    }

    if ((S_LL < Ref_LL) && (S_RR < Ref_RR) && (s != "Y") && (s != "Y_Finish"))
    {
      Stop(100);

      if (s == "R")
      {
        PlaceRed();
      }
      else
      {
        PlaceGreen();
      }

      sSet();
      sUp_Back();
      break;
    }
    else if ((S_LL < Ref_LL) && (S_RR < Ref_RR) && (s == "Y")) {
      PlaceYellow(false);
      break;
    }
    else if ((S_LL < Ref_LL) && (S_RR < Ref_RR) && (s == "Y_Finish")) {
      PlaceYellow(true);

      Finish("Y");

      break;
    }
  }
}
void Start() { // คำสั่ง ออกจากจุดสตาร์ท
  motor(1, 55); motor(2, 55);
  delay(300);
}
void Finish(String Color) {
  if (Color == "Y")
  {
    motor(1, -spd_Finish);  motor(2, -spd_Finish); delay(160);
    Pause(20);
  }
  else
  {
    if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR)) {
      TrackTime(100);
    }
    while (1) {
      if ((S_LLL < Ref_LLL) || (S_RRR < Ref_RRR))
      {
        motor(1, spd_Finish);  motor(2, spd_Finish); delay(120);
        Stop(20);
        break;
      }
      Track();
    }
  }
}
