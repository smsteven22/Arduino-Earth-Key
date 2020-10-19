#include <Servo.h>
Servo myServo;
int const potPin = A0;
int potVal;
int potValLow = 1023;
int potValHigh = 0;
int ledBlue = 8;
int ledGreen = 7;
int ledYellow = 6;
int ledRed = 5;
int angle;
void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);

  Serial.begin(9600);

  pinMode(ledBlue, OUTPUT);
  digitalWrite(ledBlue, HIGH);
  pinMode(ledGreen, OUTPUT);
  digitalWrite(ledGreen, HIGH);
  pinMode(ledYellow, OUTPUT);
  digitalWrite(ledYellow, HIGH);
  pinMode(ledRed, OUTPUT);
  digitalWrite(ledRed, HIGH);

  while (millis() < 5000) {
    potVal = analogRead(A0);
    if (potVal > potValHigh) {
      potValHigh = potVal;
    }
    if (potVal < potValLow) {
      potValLow = potVal;
    }
  }
  
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);

  int pitch = 
    map(potVal, potValLow, potValHigh, 50, 4000);

  tone(10, pitch, 20);

  if (potVal >= 0 && potVal < 250) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledBlue, LOW);
  }
  else if (potVal >= 250 && potVal < 500) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledBlue, LOW);
  }
  else if (potVal >= 500 && potVal < 750) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledBlue, LOW);
  }
  else if (potVal >= 750 && potVal <= 1000) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledBlue, HIGH);    
  }
  
  Serial.print("potVal: ");
  Serial.print(potVal);
  
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(" , angle: ");
  Serial.println(angle);
  
  myServo.write(angle);
  
  delay(15);
}
