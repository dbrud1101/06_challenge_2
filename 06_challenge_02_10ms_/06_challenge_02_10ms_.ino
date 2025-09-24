#define LED_PIN 7
static int period_us = 1000;  
static int duty_pct  = 50;    

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  
}

void set_period(int us) {                 // 100~10000 μs
  period_us = constrain(us, 100, 10000);
}
void set_duty(int pct) {                  
  duty_pct = constrain(pct, 0, 100);
}

// PWM 한 주기 출력(액티브-로우: LOW가 '켜짐')
void pwm_once() {
  int tH = period_us * duty_pct / 100;   
  int tL = period_us - tH;               
  if (tH > 0) { digitalWrite(LED_PIN, LOW);  delayMicroseconds(tH); }  // ON
  if (tL > 0) { digitalWrite(LED_PIN, HIGH); delayMicroseconds(tL); }  // OFF
}
void loop() {
  set_period(10000);                      // 10 ms
  for (int d = 0; d <= 100; d += 2) {     // 상승 0→100
    set_duty(d); pwm_once();
  }
  for (int d = 98; d >= 2; d -= 2) {      // 하강 98→2
    set_duty(d); pwm_once();
  }
}
