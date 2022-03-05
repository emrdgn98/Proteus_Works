int potentiometer = A0;
int feedback = A1;
int PWM = 3;
int pwm = 0;

void setup() {
  pinMode(potentiometer, INPUT);
  pinMode(feedback, INPUT);
  pinMode(PWM, OUTPUT);  
  TCCR2B = TCCR2B & B11111000 | B00000001;    // pin 3 and 11 PWM frequency of 31372.55 Hz
}

void loop() {  
  float voltage = analogRead(potentiometer);
  float output  = analogRead(feedback);

  if (voltage > output)
   {
    pwm = pwm-1;
    pwm = constrain(pwm, 1, 254);
   }

  if (voltage < output)
   {
    pwm = pwm+1;
    pwm = constrain(pwm, 1, 254);
   }

   analogWrite(PWM,pwm);
}
