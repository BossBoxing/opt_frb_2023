// โค้ดวิ่ง แบบเช็คกระป๋อง

void can1_R_checkCan() { // โค้ดวิ่ง Can1 คือสีแดง
  LL(4, 1);
  PlaceCan("R");

  B_LL(4, 1);
  SM(2);

  // ต่อโค้ด ไปกระป๋อง 2
}
void can1_Y_checkCan() { // โค้ดวิ่ง Can1 คือสีเหลือง
  TR90();
  Stop(30);

  SM_Pure(3);
  PlaceCan("Y");

  LL_SM();
  RR_SM_Caribate();

  // ต่อโค้ด ไปกระป๋อง 2

  // SM(2);
}
void can1_G_checkCan() { // โค้ดวิ่ง Can1 คือสีเขียว
  TR90();
  Stop(30);

  SM(2);
  RR(4, 1);
  PlaceCan("G");

  B_RR(4, 1);
  SM(3);
  LL(4, 1); // หันหน้าไปหากระป๋อง 3 เพราะ 2 โดนชนไปแล้ว
  can_check[2] = 1; // มันจะชนกระป๋อง 2 ทิ้ง
}

void can2_R_checkCan() { // โค้ดวิ่ง Can2 คือสีแดง
  // InCan(1);
  TL90();
  Stop(30);

  SM(2);
  LL(4, 1);
  PlaceCan("R");

  B_LL(4, 1);
  SM(1);
}
void can2_Y_checkCan() { // โค้ดวิ่ง Can2 คือสีเหลือง
  // InCan(1);
  TL90();
  Stop(30);

  SM_Pure(1);
  PlaceCan("Y");//
  LL_SM();
  FF_SM(2);
  LL_SM();
  RR_SM_Caribate();

  // SM(2);
}
void can2_G_checkCan() { // โค้ดวิ่ง Can2 คือสีเขียว
  // InCan(3);
  RR(4, 1);
  PlaceCan("G");

  B_RR(4, 1);
  SM(3);
}

// Start Direction = R
void can1_G_checkCan_R() { // โค้ดวิ่ง Can1_R คือสีเขียว
  RR(4, 1);
  PlaceCan("G");

  B_RR(4, 1);
  SM(2);

  // ต่อโค้ด ไปกระป๋อง 2
}
void can1_Y_checkCan_R() { // โค้ดวิ่ง Can1_R คือสีเหลือง
  TL90();
  Stop(30);

  SM(1);
  PlaceCan("Y");

  RR_SM();
  LL_SM_Caribate();

  // ต่อโค้ด ไปกระป๋อง 2

  // SM(2);
}
void can1_R_checkCan_R() { // โค้ดวิ่ง Can1 คือสีเขียว
  TL90();
  Stop(30);

  SM(2);
  LL(4, 1);
  PlaceCan("R");

  B_LL(4, 1);
  SM(1);
  LL(4, 1); // หันหน้าไปหากระป๋อง 3 เพราะ 2 โดนชนไปแล้ว
  can_check[2] = 1; // มันจะชนกระป๋อง 2 ทิ้ง
}

void can2_G_checkCan_R() { // โค้ดวิ่ง Can2 คือสีแดง
  // InCan(1);
  TR90();
  Stop(30);

  SM(2);
  RR(4, 1);
  PlaceCan("G");

  B_RR(4, 1);
  SM(3);
}
void can2_Y_checkCan_R() { // โค้ดวิ่ง Can2 คือสีเหลือง
  // InCan(1);
  TR90();
  Stop(30);

  SM(3);
  PlaceCan("Y");//
  LL_SM();
  FF_SM(2);
  LL_SM();
  RR_SM_Caribate();

  // SM(2);
}
void can2_R_checkCan_R() { // โค้ดวิ่ง Can2 คือสีเขียว
  // InCan(3);
  LL(4, 1);
  PlaceCan("R");

  B_LL(4, 1);
  SM(1);
}

void can1() {
  InCan_checkCan(3, 1,false); // can_check[1] == 1 แปลว่า ไม่มีกระป๋อง เข้า can2

  if (can_check[1] == 0) {
    if (readCan() == 1) {
      can1_R_checkCan();
    } else if (readCan() == 2) {
      can1_Y_checkCan();
    } else {
      can1_G_checkCan();
    }
  }

}
void can2() {
  if (can_check[2] == 0)
  {
    InCan_checkCan(3, 2,false);
  }
  if (can_check[2] == 0) {
    if (readCan() == 1) {
      can2_R_checkCan();
    } else if (readCan() == 2) {
      can2_Y_checkCan();
    } else {
      can2_G_checkCan();
    }
  }
}
void can1_Right() {
  InCan_checkCan(3, 1,false); // can_check[1] == 1 แปลว่า ไม่มีกระป๋อง เข้า can2

  if (can_check[1] == 0) {
    if (readCan() == 1) {
      can1_R_checkCan_R();
    } else if (readCan() == 2) {
      can1_Y_checkCan_R();
    } else {
      can1_G_checkCan_R();
    }
  }

}
void can2_Right() {
  if (can_check[2] == 0)
  {
    InCan_checkCan(3, 2,false);
  }
  if (can_check[2] == 0) {
    if (readCan() == 1) {
      can2_R_checkCan_R();
    } else if (readCan() == 2) {
      can2_Y_checkCan_R();
    } else {
      can2_G_checkCan_R();
    }
  }
}
void can3() {
  if (can_check[2] == 0) {
    LL(4, 1);
  }

  InCan_checkCan(3, 3,true);

  if (can_check[3] == 0) {
    B_LL(4, 1);

    GoTarget(readCan());
  }
}
void can4() { // โค้ดวิ่ง Can4
  if (can_check[3] == 0) {
    RR(4, 1);
  }
  // Wait();
  InCan_checkCan(3, 4,true);

  if (can_check[4] == 0)
  {
    B_RR(4, 1);

    GoTarget(readCan()); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}
void can5() { // โค้ดวิ่ง Can5
  if (can_check[4] == 0) {
    FF(4);
    LL(1, 2);
  }

  InCan_checkCan(3, 5,false);

  if (can_check[5] == 0)
  {
    B_LL(3, 2);
    FF(4);

    GoTarget(readCan()); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}
void can6() { // โค้ดวิ่ง Can6
  if (can_check[5] == 0)
  {
    FF(4);
    RR(1, 2);
  }

  InCan_checkCan(3, 6,false);

  if (can_check[6] == 0)
  {
    B_RR(3, 2);
    FF(4);

    GoTarget(readCan()); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}
void can7() {
  if (can_check[6] == 0)
  {
    FF(4);
    LL(1, 1);
  }

  InCan_checkCan(1, 7,false);

  if (can_check[7] == 0)
  {
    RR(2, 1);
    FF(4);

    GoTarget(readCan()); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}
void can8() {
  if (can_check[7] == 0)
  {
    FF(4);
    RR(1, 1);
  }

  InCan_checkCan(2, 8,false);

  if (can_check[8] == 0)
  {
    LL(2, 1);
    FF(4);

    GoTarget(readCan()); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}
void can9() {
  if (can_check[8] == 0)
  {
    FF(4);
    FF(1); // FF(1);
    CC(1, 4);
  }

  InCan_checkCan(1, 9,false);

  if (can_check[9] == 0)
  {
    CC(3, 6);
    FF(1); // FF(1);
    FF(4);

    GoTarget(readCan()); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}
void can10() {
  if (can_check[9] == 0)
  {
    FF(4);
    FF(1); // FF(1);
    CC(1, 5);
  }

  InCan_checkCan(2, 10,false);

  if (can_check[10] == 0)
  {
    CC(2, 6);
    FF(1); // FF(1);
    FF(4);

    GoTarget(readCan()); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}
void can11() {
  if (can_check[10] == 0) {
    FF(4);
    FF(1); // FF(1);
    CC(1, 6);
    LL(1, 2);
  }

  InCan_checkCan(3, 11,false);

  if (can_check[11] == 0)
  {
    B_LL(3, 2);
    CC(1, 6);
    FF(1); // FF(1);
    FF(4);

    GoTarget(readCan()); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}
void can12() {
  if (can_check[11] == 0)
  {
    FF(4);
    FF(1); // FF(1);
    CC(1, 6);
    RR(1, 2); // Wait();
  }

  InCan_checkCan(3, 12,false);

  if (can_check[12] == 0)
  {
    B_RR(3, 2);
    CC(1, 6);
    FF(1); // FF(1);
    FF(4);

    GoTarget(readCan()); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}
void can13() {
  if (can_check[12] == 0)
  {
    FF(4);
    FF(1); // FF(1);
    CC(1, 6);
    LL(1, 1);
  }

  InCan_checkCan(1, 13,false);

  if (can_check[13] == 0)
  {
    RR(2, 1);
    CC(1, 6);
    FF(1); // FF(1);
    FF(4);

    GoTarget(readCan()); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}
void can14() {
  if (can_check[13] == 0) {
    FF(4);
    FF(1); // FF(1);
    CC(1, 6);
    RR(1, 1);
  }

  InCan_checkCan(2, 14,false);

  if (can_check[14] == 0)
  {
    LL(2, 1);
    CC(1, 6);
    FF(1); // FF(1);
    FF(4);

    GoTarget(readCan()); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}
void can15() {
  if (can_check[14] == 0)
  {
    FF(4);
    FF(1); // FF(1);
    CC(1, 6);
    FF(1); // FF(1);
  }

  InCan_checkCan(3, 15,false);

  if (can_check[15] == 0)
  {
    TL90();
    Stop(30);
    FF(1); // FF(1);
    CC(1, 6);
    FF(1); // FF(1);
    FF(4);

    GoTarget(readCan(), "Finish"); // กำหนดสีอะไร จะวิ่งไปวางสีนั้นนๆ
  }
}

void no_can1_to_can2() {
  TR90();
  TrackSlowTime(500);
  SM(2);
}
void no_can2_to_can3() {
  TL90();
  TrackSlowTime(500);
  SM(3);
  LL(4, 1);
}
void no_can3_to_can4() {
  TL90();
  TrackSlowTime(500);
  FF(4);// Wait();
}
void no_can4_to_can5() {
  TL90();
  TrackSlowTime(500);
  LL(2, 1);
}
void no_can5_to_can6() {
  TL90();
  TrackSlowTime(500);
  FF(3);
}
void no_can6_to_can7() {
  TR90();
  TrackSlowTime(500);
  RR(3, 1);
}
void no_can7_to_can8() {
  TL90();
  TrackSlowTime(500);
  LL(2, 2);
}
void no_can8_to_can9() {
  TL90();
  TrackSlowTime(500);
  CC(3, 4);
}
void no_can9_to_can10() {
  TL90();
  TrackSlowTime(500);
  CC(2, 3);
}
void no_can10_to_can11() {
  TL90();
  TrackSlowTime(500);
  LL(2, 1);
}
void no_can11_to_can12() {
  TL90();
  TrackSlowTime(500);
  FF(3);
}
void no_can12_to_can13() {
  TR90();
  TrackSlowTime(500);
  RR(3, 1);
}
void no_can13_to_can14() {
  TL90();
  TrackSlowTime(500);
  LL(2, 2);
}
void no_can14_to_can15() {
  TR90();
  TrackSlowTime(500);
  RR(2, 3);
}
void no_can15_to_finish() {
  TL90();
  Pause(30);
  FF(1); // FF(1);
  CC(1, 6);
  FF(1); // FF(1);
  FF(4);
  Finish();
}

void GoTarget(int target) {
  if (target == 1) {
    rr(); // left box
  }
  else if (target == 2) {
    yy(); // center box
  }
  else if (target == 3) {
    gg(); // right box
  }
  else {}
}
void GoTarget(int target, String finish) {
  if (target == 1) {
    rr_finish();
  }
  else if (target == 2) {
    yy_finish();
  }
  else if (target == 3) {
    gg_finish();
  }
  else {}
}

void yy() { // วิ่งไปวางสีเหลือง
  // SM(2); //
  while (S_LL > Ref_LL || S_RR > Ref_RR) {
    TrackSlow();
  }
  RR_SM();
  LL_SM();
  FF_SM(2);
  LL_SM();
  RR_SM();
  ///////////

  PlaceCan("Y"); // Wait();
  LL_SM();
  FF_SM(2); // Wait();
  LL_SM();
  RR_SM_Caribate();
  // SM(2);
}
void rr() { // วิ่งไปวางสีแแดง
  SM(3);
  LL(4, 1);
  PlaceCan("R");
  B_LL(4, 1);
  SM(1);
}
void gg() { // วิ่งไปวางสีเขียว
  SM(1);
  RR(4, 1);
  PlaceCan("G");
  B_RR(4, 1);
  SM(3);
}

void yy_finish() { // วิ่งไปวางสีเหลือง กระป๋องสุดท้าย
  // SM(2); //

  while (S_LL > Ref_LL || S_RR > Ref_RR) {
    TrackSlow();
  }
  RR_SM();
  LL_SM();
  FF_SM(2);
  LL_SM();
  RR_SM_Caribate();

  /////////
  PlaceCan("Y_Finish");
  // Finish();
}
void rr_finish() { // วิ่งไปวางสีเแดง กระป๋องสุดท้าย
  SM(3);
  LL(4, 1);
  PlaceCan("R");
  B_LL(4, 1);
  Finish();
}
void gg_finish() { // วิ่งไปวางสีเเขียว กระป๋องสุดท้าย
  SM(1);
  RR(4, 1);
  PlaceCan("G");
  B_RR(4, 1);
  Finish();
}
