#include "ModelPro.h"
#include "EEPROM.h"

int function = 0;

#define startReffAddress 0 // 0 - 5 
#define startServoSetAddress  50 // 10-11-12-13-14
#define startCanAddress 20 // 20 - 33
#define startColorAddress 40 // 40 - 43
#define startDiffAddress 70 // 40 - 43

#define S_LLL map(analog(0),0,1023,0,100) //พอร์ตเซ็นเซอร์นับแยกซ้าย
#define S_LL map(analog(1),0,1023,0,100)  //พอร์ตเซ็นเซอร์ทางซ้ายสุด
#define S_L map(analog(2),0,1023,0,100) //พอร์ตเซ็นเซอร์ด้านในซ้าย
#define S_C map(analog(3),0,1023,0,100) //พอร์ตเซ็นเซอร์ด้านในซ้าย
#define S_R map(analog(4),0,1023,0,100) //พอร์ตเซ็นเซอร์ด้านในขวา
#define S_RR map(analog(5),0,1023,0,100) //พอร์ตเซ็นเซอร์ทางขวาสุด
#define S_RRR map(analog(6),0,1023,0,100) //พอร์ตเซ็นเซอร์นับแยกขวา

#define S_B_LLL map(analog(7),0,1023,0,100) //พอร์ตเซ็นเซอร์นับแยกซ้าย
#define S_B_L map(analog(8),0,1023,0,100) //พอร์ตเซ็นเซอร์ด้านในซ้าย
#define S_B_C map(analog(9),0,1023,0,100) //พอร์ตเซ็นเซอร์กลาง
#define S_B_R map(analog(10),0,1023,0,100) //พอร์ตเซ็นเซอร์ด้านในขวา
#define S_B_RRR map(analog(11),0,1023,0,100) //พอร์ตเซ็นเซอร์นับแยกขวา

#define S_CG map(analog(12),0,1023,0,69) //พอร์ตเซ็นเซอร์สีเขียว
#define S_CR map(analog(13),0,1023,0,69) //พอร์ตเซ็นเซอร์สีแดง
#define S_Can ultrasonic(49,50) //พอร์ตเซ็นเซอร์เซ็คกระป๋อง

#define Clasp 2 //พอร์ต servo หนีบ
#define Raise 1 //พอร์ต servo ยก

int Ref_CG_R = EEPROM.read(startColorAddress + 1); // ค่าเซนเซอร์มือสีเขียวจับกระป๋องแดง
int Ref_CG_G = EEPROM.read(startColorAddress + 2); // ค่าเซนเซอร์มือสีเขียวจับกระป๋องเขียว
int Ref_CG_Y = EEPROM.read(startColorAddress + 3); // ค่าเซนเซอร์มือสีเขียวจับกระป๋องเหลือง
int Ref_CR_R = EEPROM.read(startColorAddress + 4); // ค่าเซนเซอร์มือสีแดงจับกระป๋องแดง
int Ref_CR_G = EEPROM.read(startColorAddress + 5); // ค่าเซนเซอร์มือสีแดงจับกระป๋องเขียว
int Ref_CR_Y = EEPROM.read(startColorAddress + 6); // ค่าเซนเซอร์มือสีแดงจับกระป๋องเหลือง
#define diff_can 5


int Ref_LLL = EEPROM.read(startReffAddress + 1); //ค่าแสงตเซ็นเซอร์นับแยกซ้าย
int Ref_LL = EEPROM.read(startReffAddress + 2); //ค่าแสงตเซ็นเซอร์ทางซ้ายสุด
int Ref_L = EEPROM.read(startReffAddress + 3); //ค่าแสงตเซ็นเซอร์ด้านในซ้าย
int Ref_C = EEPROM.read(startReffAddress + 4); //ค่าแสงตเซ็นเซอร์ด้านในซ้าย
int Ref_R = EEPROM.read(startReffAddress + 5); //ค่าแสงตเซ็นเซอร์ด้านในขวา
int Ref_RR = EEPROM.read(startReffAddress + 6); //ค่าแสงตเซ็นเซอร์ทางขวาสุด
int Ref_RRR = EEPROM.read(startReffAddress + 7); //ค่าแสงตเซ็นเซอร์นับแยกขวา

int Ref_B_LLL = EEPROM.read(startReffAddress + 8); //ค่าแสงตเซ็นเซอร์นับแยกซ้าย
int Ref_B_L = EEPROM.read(startReffAddress + 9); //ค่าแสงตเซ็นเซอร์ด้านในซ้าย
int Ref_B_C = EEPROM.read(startReffAddress + 10); //ค่าแสงตเซ็นเซอร์กลาง
int Ref_B_R = EEPROM.read(startReffAddress + 11); //ค่าแสงตเซ็นเซอร์ด้านในขวา
int Ref_B_RRR = EEPROM.read(startReffAddress + 12); //ค่าแสงตเซ็นเซอร์นับแยกขวา

int Max_LL = EEPROM.read(startReffAddress + 21);
int Max_RR = EEPROM.read(startReffAddress + 22);

int SS_Can = 3; // 5 //ระยะเข้าหนีบกระป๋อง cm

int diff_S_L = EEPROM.read(startDiffAddress + 1) == 255 ? 0 : EEPROM.read(startDiffAddress + 1);
int diff_S_R = EEPROM.read(startDiffAddress + 2) == 255 ? 0 : EEPROM.read(startDiffAddress + 2);
int diff_S_LL = EEPROM.read(startDiffAddress + 3) == 255 ? 0 : EEPROM.read(startDiffAddress + 3);
int diff_S_RR = EEPROM.read(startDiffAddress + 4) == 255 ? 0 : EEPROM.read(startDiffAddress + 4);

int Clasp_Keep = EEPROM.read(startServoSetAddress + 1) == 255 ? 20 : EEPROM.read(startServoSetAddress + 1) ; //ค่าหนีบกระป๋อง
int Clasp_Place = EEPROM.read(startServoSetAddress + 2) == 255 ? 120 : EEPROM.read(startServoSetAddress + 2) ; //ค่าวางกระป๋อง
int Clasp_Set = EEPROM.read(startServoSetAddress + 3) == 255 ? 150 : EEPROM.read(startServoSetAddress + 3) ; //ค่าเซ็ทมือ หลบกระป๋อง

int Raise_Up = EEPROM.read(startServoSetAddress + 4) == 255 ? 38 : EEPROM.read(startServoSetAddress + 4) ; //ค่ายกมือ
int Raise_Down = EEPROM.read(startServoSetAddress + 5) == 255 ? 19 : EEPROM.read(startServoSetAddress + 5) ; //ค่าเอามือลง
/////////////////////////////////
// Time Config //
int T1 = 50;
int T2 = 120;
int T3 = 160;
int T_SM = 50;
int T_CC = 50;
/////////////////////////////////
int can_check[16] = {
  0 // 0
  , 0 // 1
  , 0 // 2
  , 0 // 3
  , 0 // 4
  , 0 // 5
  , 0 // 6
  , 0 // 7
  , 0 // 8
  , 0 // 9
  , 0 // 10
  , 0 // 11
  , 0 // 12
  , 0 // 13
  , 0 // 14
  , 0 // 15
};
int CanPosition[4] = {
  0,
  1, // RED
  2, // YELLOW
  3 // GREEN
};


boolean keepingCan = false;
/////////////////////

void setup() {
  ok();
}

void loop() {
  if (function == 0) {
    // setCanPos();


    while (S_LLL >= Ref_LLL)
    {
     Pid(150); 
    }
    while (S_LLL <= Ref_LLL)
    {
     Pid(150); 
    }
    while (S_LLL >= Ref_LLL)
    {
     Pid(150); 
    }
    Wait();
    
    // code_checkcan(); // โค้ดวิ่ง
    
//    Pause(1000000); // วิ่งเสร็จ ให้หยุดหุ่นยนต์
//    Wait(); // รอกดสวิตส์
  }
  else if (function == 1) {
    setSensor(); // เซ้ทค่าแสง
  }
  else if (function == 2) {
    setSensorHand();
  }
  else if (function == 3) {
    setServo(); // เซ้ทค่าเซอร์โว
  }
  else if (function == 4) {
    showAllSensor();
  }
  else if (function == 5) {
    // oledClear();
    while (SW_OK() == false) {}
    while (SW_OK() == true) {
      // oledClear();
      oled(0, 10, "L:    %d ", S_L);
      oled(0, 20, "R:    %d ", S_R);
      oled(0, 30, "L-R:  %d ", S_L - S_R);
      oled(0, 40, "Diff_L:  %d ", diff_S_L);
      oled(0, 50, "Diff_R:  %d ", diff_S_R);
    }

    if (S_L < S_R) {
      EEPROM.update(startDiffAddress + 1, (S_R - S_L));
      EEPROM.update(startDiffAddress + 2, 0);
    }
    else {
      EEPROM.update(startDiffAddress + 1, 0);
      EEPROM.update(startDiffAddress + 2, (S_L - S_R));
    }
    if (S_LL < S_RR) {
      EEPROM.update(startDiffAddress + 3, (S_RR - S_LL));
      EEPROM.update(startDiffAddress + 4, 0);
    }
    else {
      EEPROM.update(startDiffAddress + 3, 0);
      EEPROM.update(startDiffAddress + 4, (S_LL - S_RR));
    }
    beep();
    while (SW_OK() == false) {}

  }
  else if (function == 6) {
    Keep();
    while (1) {
      // oledClear();
      oled(1, 10, "G : %d ", S_CG);
      oled(1, 20, "R : %d ", S_CR);
      oled(1, 30, "DistSensor : %d ", S_Can);
      oled(2, 40, "CAN: %d", readCan());
    }
  }
  else if (function == 7) {
    Pid_B(150);
  }
  else if (function == 8) {
    Pid(150); 
  }
  else if (function == 9) {

    while(S_LLL > Ref_LLL || S_RRR > Ref_RRR)
    {
      Pid(120);
    }
    Stop(100);
    while (S_L <= Ref_L)
    {
      motor(1,-50);
      motor(2,50);
      delay(40);
    }
    while (S_L >= Ref_L)
    {
      motor(1,-50);
      motor(2,50);
      delay(10);
    }
    while (S_L <= Ref_L)
    {
      motor(1,-50);
      motor(2,50);
      delay(10);
    }

    unsigned long currentTime=millis();
    while(millis()-currentTime < 1000)
    {
      if( S_L >= Ref_L )
      {
        motor(1,50);
        motor(2,-50);
        // delay(10);
      }
      else if( S_R >= Ref_R )
      {
        motor(1,-50);
        motor(2,50);
        // delay(10);
      }
    }

//    currentTime=millis();
//    while(millis()-currentTime < 200)
//    {
//      Pid(120);
//    }
    
    Pause(100);
    beep();
    
    Wait();
  }
  else {
    setCanPos();

    code_checkcan_R(); // โค้ดวิ่ง

    Pause(1000000); // วิ่งเสร็จ ให้หุ่นยนต์
    Wait(); // รอกดสวิตส์
  }
}
