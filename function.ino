float error = 0, P = 0, I = 0, D = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
long currentTime = 0;
int g, y, r = 0;
int i = 0;

int Slow_L = 55; // power ในการเลี้ยว
int Slow_R = 55;

void Stop(int t) { // คำสั่งหยุด
  int time = t / 2;
  motor(1, -70);
  motor(2, -70);
  delay(time);

  motor(1, 0);
  motor(2, 0);
  delay(time);
}
void B_Stop(int t) { // คำสั่งหยุด
  int time = t / 2;
  motor(1, 70);
  motor(2, 70);
  delay(time);

  motor(1, 0);
  motor(2, 0);
  delay(time);
}
void Pause(int t) { // คำสั่งหยุด
  motor(1, 0);
  motor(2, 0);
  delay(t);
}
void Fw(int t) { // คำสั่งเดินหน้า
  motor(1, 70); motor(2, 70);
  delay(t);
}
void FwSlow(int t) { // คำสั่งเดินหน้าแบบช้า
  motor(1, 60); motor(2, 60);
  delay(t);
}
void Bk(int t) { // คำสั่งถอยหลัง
  motor(1, -90); motor(2, -90);
  delay(t);
}
void BkSlow(int t) { // คำสั่งถอยหลังแบบช้า
  motor(1, -90); motor(2, -90);
  delay(t);
}

void readServo() { // คำสั่งอ่านค่าเซอร์โวมอเตอร์
  int p, d;
  delay(800);
  while (SW_OK() == 1) {
    p = knob(1, 3);
    oled(0, 0, "Port = %d ", p);
    oledClear();
  }
  delay(500);
  while (SW_OK() == 1) {
    d = knob(1, 180);
    servo(p, d);
    oled(0, 0, "Port = %d ", p);
    oled(0, 15, "results = %d ", d);
    oledClear();
    delay(20);
  }
}
void readSensor() {
  oled(1, 0, "%d ", S_LLL);
  oled(1, 10, "%d ", S_LL);
  oled(1, 20, "%d ", S_L);
  oled(1, 30, "%d ", S_R);
  oledClear();
}

void ok() {
  XIO();
  
  sUp();
  sKind();
  // servo(Clasp, Clasp_Set); delay(200);
  // servo(Raise, Raise_Up); delay(200);

  while (SW_OK() == 1) {
    function = knob(0, 11);
    if (function == 0) {
      setTextSize(4);
      oled(5, 15, "Run                                              ");
    }
    else if (function == 1) {
      setTextSize(2);
      oled(5, 15, "Calibrate  Sensor                                ");
    }
    else if (function == 2) {
      setTextSize(2);
      oled(5, 15, "Calibrate  Hand        Sensor                   ");
    }
    else if (function == 3) {
      setTextSize(2);
      oled(5, 15, "Set Servo                                          ");
    }
    else if (function == 4) {
      setTextSize(2);
      oled(5, 15, "Show All      Sensor                   ");
    }
    else if (function == 5) {
      setTextSize(2);
      oled(5, 15, "Set Diff      Sensor                   ");
    }
    else if (function == 6) {
      setTextSize(2);
      oled(5, 15, "Check        Hand       Sensor                   ");
    }
    else {
      setTextSize(5);
      oled(0, 15, " %d           ", function);
    }
    if (SW_OK() == 0)
    {
      setTextSize(1);
      beep();
      break;
    }
  }
  oledClear();
}
void setSensor() {
  delay(500);
  int Max[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int Min[9] = {100, 100, 100, 100, 100, 100, 100, 100, 100};

  int Max_Back[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int Min_Back[9] = {100, 100, 100, 100, 100, 100, 100, 100, 100};
  int i = 1;

  currentTime = millis();

  motor(1, -40);
  motor(2, 40);

  while (millis() - currentTime < 2500) {
    if (S_LLL > Max[0]) {
      Max[0] = S_LLL;
      i = 1;
    }
    if (S_LLL < Min[0]) {
      Min[0] = S_LLL;
      i = 1;
    }

    if (S_LL > Max[1]) {
      Max[1] = S_LL;
      i = 1;
    }
    if (S_LL < Min[1]) {
      Min[1] = S_LL;
      i = 1;
    }

    if (S_L > Max[2]) {
      Max[2] = S_L;
      i = 1;
    }
    if (S_L < Min[2]) {
      Min[2] = S_L;
      i = 1;
    }

    if (S_R > Max[4]) {
      Max[4] = S_R;
      i = 1;
    }
    if (S_R < Min[4]) {
      Min[4] = S_R;
      i = 1;
    }

    if (S_RR > Max[5]) {
      Max[5] = S_RR;
      i = 1;
    }
    if (S_RR < Min[5]) {
      Min[5] = S_RR;
      i = 1;
    }

    if (S_RRR > Max[6]) {
      Max[6] = S_RRR;
      i = 1;
    }
    if (S_RRR < Min[6]) {
      Min[6] = S_RRR;
      i = 1;
    }

    if (S_B_LLL > Max_Back[0]) {
      Max_Back[0] = S_B_LLL;
      i = 1;
    }
    if (S_B_LLL < Min_Back[0]) {
      Min_Back[0] = S_B_LLL;
      i = 1;
    }

    if (S_B_LL > Max_Back[1]) {
      Max_Back[1] = S_B_LL;
      i = 1;
    }
    if (S_B_LL < Min_Back[1]) {
      Min_Back[1] = S_B_LL;
      i = 1;
    }

    if (S_B_L > Max_Back[2]) {
      Max_Back[2] = S_B_L;
      i = 1;
    }
    if (S_B_L < Min_Back[2]) {
      Min_Back[2] = S_B_L;
      i = 1;
    }

    if (S_B_R > Max_Back[3]) {
      Max_Back[3] = S_B_R;
      i = 1;
    }
    if (S_B_R < Min_Back[3]) {
      Min_Back[3] = S_B_R;
      i = 1;
    }

    if (S_B_RR > Max_Back[4]) {
      Max_Back[4] = S_B_RR;
      i = 1;
    }
    if (S_B_RR < Min_Back[4]) {
      Min_Back[4] = S_B_RR;
      i = 1;
    }

    if (S_B_RRR > Max_Back[5]) {
      Max_Back[5] = S_B_RRR;
      i = 1;
    }
    if (S_B_RRR < Min_Back[5]) {
      Min_Back[5] = S_B_RRR;
      i = 1;
    }

  }

  motor(1, 0); motor(2, 0); delay(500);
  beep();

  // Front - side
  EEPROM.update(startReffAddress + 1, (Max[0] + Min[0]) / 2); // LLL
  EEPROM.update(startReffAddress + 2, (Max[1] + Min[1]) / 2); // LL
  EEPROM.update(startReffAddress + 3, (Max[2] + Min[2]) / 2); // L
  // EEPROM.update(startReffAddress + 13, (Max[3] + Min[3]) / 2); // C
  EEPROM.update(startReffAddress + 4, (Max[4] + Min[4]) / 2); // R
  EEPROM.update(startReffAddress + 5, (Max[5] + Min[5]) / 2); // RR
  EEPROM.update(startReffAddress + 6, (Max[6] + Min[6]) / 2); // RRR

  // Behind - side
  EEPROM.update(startReffAddress + 7, (Max_Back[0] + Min_Back[0]) / 2); // B_LLL
  EEPROM.update(startReffAddress + 8, (Max_Back[1] + Min_Back[1]) / 2); // B_LL
  EEPROM.update(startReffAddress + 9, (Max_Back[2] + Min_Back[2]) / 2); // B_L
  EEPROM.update(startReffAddress + 10, (Max_Back[3] + Min_Back[3]) / 2); // B_R
  EEPROM.update(startReffAddress + 11, (Max_Back[4] + Min_Back[4]) / 2); // B_RR
  EEPROM.update(startReffAddress + 12, (Max_Back[5] + Min_Back[5]) / 2); // B_RRR

  // for cal_error() - pid controller
  EEPROM.update(startReffAddress + 21, Max[1]); // LL
  EEPROM.update(startReffAddress + 22, Max[5]); // RR

  oledClear();
  oled(0, 0,  "Sensor Ref|Sensor Ref");
  oled(0, 7,  "---------------------");
  oled(0, 13, "LLL   %d |RR      %d", EEPROM.read(startReffAddress + 1), EEPROM.read(startReffAddress + 5));
  oled(0, 23, "LL    %d |RRR     %d", EEPROM.read(startReffAddress + 2), EEPROM.read(startReffAddress + 6));
  oled(0, 33, "L     %d", EEPROM.read(startReffAddress + 3));
  oled(0, 43, "C      %d", EEPROM.read(startReffAddress + 13));
  oled(0, 53, "R      %d", EEPROM.read(startReffAddress + 4));
  while (1) {}
}
void setServo() {

  int count = 1;
  int TimeOK = 0;

  while (true) {
    TimeOK = 0;
    if (count == 1) {
      servo(Clasp, knob(180));
      oled(0, 0, "1. Clasp_Keep: %d ", knob(180));
    }
    else if (count == 2) {
      servo(Clasp, knob(180));
      oled(0, 0, "2. Clasp_Place: %d ", knob(180));
    }
    else if (count == 3) {
      servo(Clasp, knob(180));
      oled(0, 0, "3. Clasp_Set: %d ", knob(180));
    }
    else if (count == 4) {
      servo(Raise, knob(180));
      oled(0, 0, "4. Raise_Up: %d ", knob(180));
    }
    else if (count == 5) {
      servo(Raise, knob(180));
      oled(0, 0, "5. Raise_Down: %d ", knob(180));
    }
    if (SW_OK() == false) {

      while (1) {

        if (SW_OK() == false) {
          TimeOK++;
        }
        else {
          beep();
          if (count < 5) {
            count++;
            break;
          } else {
            count = 1;
            break;
          }
        }

        if (TimeOK > 500) {
          beep();
          if (count == 1) {
            EEPROM.update(startServoSetAddress + 1 , knob(180) );
          }
          else if (count == 2) {
            EEPROM.update(startServoSetAddress + 2 , knob(180) );
          }
          else if (count == 3) {
            EEPROM.update(startServoSetAddress + 3 , knob(180) );
          }
          else if (count == 4) {
            EEPROM.update(startServoSetAddress + 4 , knob(180) );
          }
          else if (count == 5) {
            EEPROM.update(startServoSetAddress + 5 , knob(180) );
          }
          oledClear();
          oled(5, 10, "Save! ");
          while (SW_OK() == false) {}
          delay(500);
          beep();
          break;
        }
        delay(1);
        // Time++;
      }

    }

    oledClear(); delay(50);
  }

}
void Wait() {
  while (SW_OK() == true) {
    Pause(10);
  }
  while (SW_OK() == false) {

  }
  beep();
}
void setSensorHand() {
  setTextSize(2);
  delay(500);
  while (SW_OK() == 1) {
    oled(10, 0, "INPUT");
    oled(5, 20, "RED CAN");
    delay(20);
  }
  // while(SW_OK() == 0){}
  Keep();
  oledClear();
  beep();
  delay(500);
  ////
  EEPROM.update(startColorAddress + 1, S_CG);
  ////
  setTextSize(2);
  delay(500);
  while (SW_OK() == 1) {
    oled(10, 0, "SAVE!");
    oled(5, 20, "RED CAN");
    oled(5, 40, "-NEXT-");
    delay(20);
  }
  // while(SW_OK() == 0){}
  Place();
  oledClear();
  beep();
  delay(500);

  setTextSize(2);
  delay(500);
  while (SW_OK() == 1) {
    oled(10, 0, "INPUT");
    oled(5, 20, "YELLOW CAN");
    delay(20);
  }
  // while(SW_OK() == 0){}
  Keep();
  oledClear();
  beep();
  delay(500);
  ////
  EEPROM.update(startColorAddress + 2 , S_CG);
  EEPROM.update(startColorAddress + 4, S_CR);
  ////
  setTextSize(2);
  delay(500);
  while (SW_OK() == 1) {
    oled(10, 0, "SAVE!");
    oled(5, 20, "YELLOW CAN");
    oled(5, 40, "-NEXT-");
    delay(20);
  }
  // while(SW_OK() == 0){}
  Place();
  oledClear();
  beep();
  delay(500);

  setTextSize(2);
  delay(500);
  while (SW_OK() == 1) {
    oled(10, 0, "INPUT");
    oled(5, 20, "GREEN CAN");
    delay(20);
  }
  // while(SW_OK() == 0){}
  Keep();
  oledClear();
  beep();
  delay(500);
  ////
  EEPROM.update(startColorAddress + 3, S_CR);
  ////
  setTextSize(2);
  delay(500);
  while (SW_OK() == 1) {
    oled(10, 0, "SAVE!");
    oled(5, 20, "GREEN CAN");
    oled(5, 40, "-NEXT-");
    delay(20);
  }
  // while(SW_OK() == 0){}
  Place();
  oledClear();
  beep();
  delay(500);

  ////
  setTextSize(2);
  oled(10, 0, "ENJOY!");
  delay(20);
  beep();
  delay(500);
  Wait();
  oledClear();


}

void code_setcan() { // คำสั่งวิ่งทั้งสนาม
  Start();

  if (Startcan == 1) {

    if (can[1] == 1) {
      Start_can1_R();
    } else if (can[1] == 2) {
      Start_can1_Y();
    } else if (can[1] == 3) {
      // green impossible cause user choose
    }
    //
    if (can[2] == 1) {
      can2_R();
    } else if (can[2] == 2) {
      can2_Y();
    } else if (can[2] == 3) {
      can2_G();
    }
  }
  else {

    if (can[2] == 1) {
      // red impossible cause user choose
    } else if (can[2] == 2) {
      Start_can2_Y();
    } else if (can[2] == 3) {
      Start_can2_G();
    }
    //
    if (can[1] == 1) {
      can1_R();
    } else if (can[1] == 2) {
      can1_Y();
    } else if (can[1] == 3) {
      can1_G();
    }
  }
  //

  can3(can[3]); //
  can4(can[4]); //
  can5(can[5]); //
  can6(can[6]); //
  can7(can[7]); //
  can8(can[8]); //
  can9(can[9]); //
  can10(can[10]); //
  can11(can[11]); //
  can12(can[12]); //
  can13(can[13]); //
  can14(can[14]); //
  can15(can[15]); //
}
void code_checkcan() { // คำสั่งวิ่งทั้งสนาม
  Start();

  can1();
  can2();
  can3();
  can4();
  can5();
  can6();
  can7();
  can8();
  can9();
  can10();
  can11();
  can12();
  can13();
  can14();
  can15();
}
void code_checkcan_R() { // คำสั่งวิ่งทั้งสนาม
  Start();

  can1_Right();
  can2_Right();
  can3();
  can4();
  can5();
  can6();
  can7();
  can8();
  can9();
  can10();
  can11();
  can12();
  can13();
  can14();
  can15();
}
int readCan() { // คำสั่งอ่านค่ากระป๋องด้วยเซนเซอร์มือ ออกมาเป็นตัวเลข 1 แดง 2 เหลือง 3 เขียว

  // Read Can
  // Green G:38 R:18
  // Red G:21 R:28
  // Yellow G:46 R:40
  if (S_CG < ((Ref_CG_R + Ref_CG_Y) / 2) ) {
    return CanPosition[1]; // RED CAN
  }
  else if (S_CR < ( (Ref_CR_G + Ref_CR_Y) / 2 ) ) {
    return CanPosition[3]; // GREEN CAN
  }
  else {
    return CanPosition[2]; // YELLOW CAN
  }
}


void setCanPos() {
  while (SW_OK() == 0) {}

  oledClear();
  setTextSize(2);

  while (SW_OK() == 1)
  {
    int pos = knob(6);

    if (pos == 0)
    {
      oled(0, 0, "1: R \n2: Y   %d \n3: G", pos + 1);
      CanPosition[1] = 1; // R
      CanPosition[2] = 2; // Y
      CanPosition[3] = 3; // G
    }
    else if (pos == 1)
    {
      oled(0, 0, "1: R \n2: G   %d \n3: Y", pos + 1);
      CanPosition[1] = 1; // R
      CanPosition[2] = 3; // Y
      CanPosition[3] = 2; // G
    }
    else if (pos == 2)
    {
      oled(0, 0, "1: Y \n2: R   %d \n3: G", pos + 1);
      CanPosition[1] = 2; // R
      CanPosition[2] = 1; // Y
      CanPosition[3] = 3; // G
    }
    else if (pos == 3)
    {
      oled(0, 0, "1: Y \n2: G   %d \n3: R", pos + 1);
      CanPosition[1] = 3; // R
      CanPosition[2] = 1; // Y
      CanPosition[3] = 2; // G
    }
    else if (pos == 4)
    {
      oled(0, 0, "1: G \n2: R   %d \n3: Y", pos + 1);
      CanPosition[1] = 2; // R
      CanPosition[2] = 3; // Y
      CanPosition[3] = 1; // G
    }
    else
    {
      oled(0, 0, "1: G \n2: Y   %d \n3: R", pos + 1);
      CanPosition[1] = 3; // R
      CanPosition[2] = 2; // Y
      CanPosition[3] = 1; // G
    }
    //oledClear();
    //delay(10);
  }

  while (SW_OK() == 0) {}

  oledClear();
  beep();
  delay(500);
}
void showAllSensor() {
  int flag = 0;
  while (1) {
    if (SW_OK() == 0) {
      beep();
      while (SW_OK() == 0) {}
      oledClear();
      if (flag > 0) {
        flag = 0;
      }
      else {
        flag++;
      }
    }
    if (flag == 0) {
      oled(0, 0,  "Sensor Val|Sensor Val");
      oled(0, 7,  "---------------------");

      oled(20, 17, "%d ", S_LL); oled(40, 17, "%d ", S_L);

      oled(70, 17, "%d ", S_R); oled(90, 17, "%d ", S_RR);

      oled(0, 27, "%d ", S_LLL);
      oled(110, 27, "%d ", S_RRR);

      int x = 30;
      oled(0, 7 + x,  "---------------------");

      oled(20, 27 + x, "%d ", S_B_RR); oled(40, 27 + x, "%d ", S_B_R);

      oled(70, 27 + x, "%d ", S_B_L); oled(90, 27 + x, "%d ", S_B_LL);

      oled(0, 17 + x, "%d ", S_B_RRR);
      oled(110, 17 + x, "%d ", S_B_LLL);
    }
    else {
      oled(20, 17, "Distance: %d cm. ", getdist(S_Can));
      oled(20, 27, "Hand Red: %d ", S_CR);
      oled(20, 37, "Hand Green: %d ", S_CG);
      oled(20, 47, "CAN: %d", readCan());
    }
  }
}
void noCan(int can) {
  Stop(100);
  if (can == 1) {
    no_can1_to_can2();
  }
  else if (can == 2) {
    no_can2_to_can3();
  }
  else if (can == 3) {
    no_can3_to_can4();
  }
  else if (can == 4) {
    no_can4_to_can5();
  }
  else if (can == 5) {
    no_can5_to_can6();
  }
  else if (can == 6) {
    no_can6_to_can7();
  }
  else if (can == 7) {
    no_can7_to_can8();
  }
  else if (can == 8) {
    no_can8_to_can9();
  }
  else if (can == 9) {
    no_can9_to_can10();
  }
  else if (can == 10) {
    no_can10_to_can11();
  }
  else if (can == 11) {
    no_can11_to_can12();
  }
  else if (can == 12) {
    no_can12_to_can13();
  }
  else if (can == 13) {
    no_can13_to_can14();
  }
  else if (can == 14) {
    no_can14_to_can15();
  }
  else if (can == 15) {
    no_can15_to_finish();
  }
}
