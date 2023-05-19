// replace motor in library. /ModelPro_motor.h
void motor_speed(char ch, int Pow) {
  long p = Pow;
  if (Pow >= -255 && Pow <= 255)
  {
    // p = map(Pow,0,100,0,255);
    if (ch == 1 && Pow > 0)
    {
      pinMode(InA1, OUTPUT);
      pinMode(InB1, OUTPUT);
      pinMode(Pwm1, OUTPUT);
      digitalWrite(InA1, LOW);
      digitalWrite(InB1, HIGH);
      analogWrite(Pwm1, (int)p);
    }
    else if (ch == 1 && Pow <= 0)
    {
      pinMode(InA1, OUTPUT);
      pinMode(InB1, OUTPUT);
      pinMode(Pwm1, OUTPUT);
      digitalWrite(InA1, HIGH);
      digitalWrite(InB1, LOW);
      analogWrite(Pwm1, -(int)p);
    }
    else if (ch == 2 && Pow > 0)
    {
      pinMode(InA2, OUTPUT);
      pinMode(InB2, OUTPUT);
      pinMode(Pwm2, OUTPUT);
      digitalWrite(InA2, LOW);
      digitalWrite(InB2, HIGH);
      analogWrite(Pwm2, (int)p);
    }
    else if (ch == 2 && Pow <= 0)
    {
      pinMode(InA2, OUTPUT);
      pinMode(InB2, OUTPUT);
      pinMode(Pwm2, OUTPUT);
      digitalWrite(InA2, HIGH);
      digitalWrite(InB2, LOW);
      analogWrite(Pwm2, -(int)p);
    }
    else if (ch == 3 && Pow > 0)
    {
      pinMode(InA3, OUTPUT);
      pinMode(InB3, OUTPUT);
      pinMode(Pwm3, OUTPUT);
      digitalWrite(InA3, LOW);
      digitalWrite(InB3, HIGH);
      analogWrite(Pwm3, (int)p);
    }
    else if (ch == 3 && Pow <= 0)
    {
      pinMode(InA3, OUTPUT);
      pinMode(InB3, OUTPUT);
      pinMode(Pwm3, OUTPUT);
      digitalWrite(InA3, HIGH);
      digitalWrite(InB3, LOW);
      analogWrite(Pwm3, -(int)p);
    }
    else if (ch == 4 && Pow > 0)
    {
      pinMode(InA4, OUTPUT);
      pinMode(InB4, OUTPUT);
      pinMode(Pwm4, OUTPUT);
      digitalWrite(InA4, HIGH);
      digitalWrite(InB4, LOW);
      analogWrite(Pwm4, (int)p);
    }
    else if (ch == 4 && Pow <= 0)
    {
      pinMode(InA4, OUTPUT);
      pinMode(InB4, OUTPUT);
      pinMode(Pwm4, OUTPUT);
      digitalWrite(InA4, LOW);
      digitalWrite(InB4, HIGH);
      analogWrite(Pwm4, -(int)p);
    }
  }
}

/////
