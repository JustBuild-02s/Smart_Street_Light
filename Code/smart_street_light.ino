/*
Project: Smart Street Light
Board: Arduino Uno
Sensors: 2x IR Sensor, LDR Module (Digital Output)
*/

int ir1 = 3;
int ir2 = 4;
int ldr = 9;  // DO pin of LDR module

int led_ir1 = 5;
int led_ir2 = 6;
int led_ldr1 = 7;
int led_ldr2 = 8;

void setup() {
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ldr, INPUT);

  pinMode(led_ir1, OUTPUT);
  pinMode(led_ir2, OUTPUT);
  pinMode(led_ldr1, OUTPUT);
  pinMode(led_ldr2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int ir1State = digitalRead(ir1);
  int ir2State = digitalRead(ir2);
  int ldrState = digitalRead(ldr);

  Serial.print("IR1: "); Serial.print(ir1State);
  Serial.print("  IR2: "); Serial.print(ir2State);
  Serial.print("  LDR: "); Serial.println(ldrState);

  // IR sensors (active LOW)
  digitalWrite(led_ir1, ir1State == LOW ? HIGH : LOW);
  digitalWrite(led_ir2, ir2State == LOW ? HIGH : LOW);

  // LDR control (Digital Output module)
  if (ldrState == HIGH) {  // Bright
    digitalWrite(led_ldr1, HIGH);
    digitalWrite(led_ldr2, HIGH);
  } else {                 // Dark
    digitalWrite(led_ldr1, LOW);
    digitalWrite(led_ldr2, LOW);
  }

  delay(100);
}
