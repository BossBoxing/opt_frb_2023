void Keep() { // คำสั่งหนีบกระป๋องและยกมือ

  // keepingCan = true;

  Pause(30);

  sKeep();
  sUp();

  Pause(1);
}
void Keep_Track() { // คำสั่งหนีบกระป๋องและยกมือ

  // keepingCan = true;

  Pause(30);

  sKeep();
  sUp_Back();

  Pause(1);
}
void Place() { // คำสั่งวาวมือและปล่อยกระป๋อง

  keepingCan = false;

  Pause(30);

  sKind();
  // sUp();
  
  Pause(1);
}

void sKeep() {

  for (int deg = Clasp_Place; deg > (Clasp_Keep + 20); deg -= 1) {
    servo(Clasp, deg);
    delay(2);
  }
  servo(Clasp, Clasp_Keep);  delay(250);
}
void sKind() {
  servo(Clasp, Clasp_Place);  delay(350);
}
void sUp() {
  servo(Raise, Raise_Up);  delay(250);
}
void sDown() {
  for (int i = Raise_Up; i > Raise_Down; i -= 1)
  {
    servo(Raise, i);
    delay(1);
    TrackCan();
  }
}
void sUp_Back() {
  for (int i = Raise_Down; i < Raise_Up; i += 1)
  {
    servo(Raise, i);
    delay(1);
    TrackSlow_B();
  }
}
void Pre_Place() { // คำสั่งวาวมือและปล่อยกระป๋อง
  Pause(1);
  servo(Raise, (int(Raise_Down + Raise_Up) / 2));  delay(150);
  // servo(Clasp, Clasp_Place);  delay(50);
  Pause(1);
}
