#include <Arduino.h>

uint8_t A = 14;
uint8_t AIN1 = 26;
uint8_t AIN2 = 27;

uint8_t B = 32;
uint8_t BIN1 = 25;
uint8_t BIN2 = 33;

void stopMotor(){
  analogWrite(A, 0);
  analogWrite(B, 0);

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);

  Serial.println("setopp");
}

void motor(){
  pinMode(A, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(B, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  stopMotor();
}

void setMotor(int kiri, int kanan){
  if(kiri >= 0){
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  } else{
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    kiri = -kiri;
  }

  if(kanan >= 0){
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else{
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    kanan = -kanan;
  }

  kiri = constrain(kiri, 0, 255);
  kanan = constrain(kanan, 0, 255);

  analogWrite(A, kanan);
  analogWrite(B, kiri);

}
