#include "aktuator.h"

const int normal = 150;

#define MAJU    0b000000000001
#define MUNDUR  0b000000000010
#define KANAN   0b000000000100
#define KIRI    0b000000001000

#define TUBRUK  0b000100000000
#define SELIPR  0b001000000000
#define SELIPL  0b010000000000
#define BACK    0b100000000000

void maju(int speed){
  setMotor(speed, 200);
}

void mundur(int speed){
  setMotor(-speed, -200);
}

void kanan(int speed){
  setMotor(speed, 0);
}

void puterR(int speed){
  setMotor(speed, -speed);
}

void kiri(int speed){
  setMotor(0, speed);
}

void puterL(int speed){
  setMotor(-speed, speed);
}

void tubruk(int speed){
  setMotor(speed, speed);
}

void berenti(){
  setMotor(0, 0);
}

void selipR(){
  puterR(255);

  maju(200);
  delay(normal);

  puterL(255);
}

void selipL(){
  puterL(255);

  maju(200);
  delay(normal);

  puterR(255); 
}

void back(){
  puterR(255);

  maju(200);
  delay(normal);

  puterL(255);
}

void handlePS3() {

  // failsafe
  if (!Ps3.isConnected()) {
    berenti();
    return;
  }

  uint16_t tombol = 0;

  // Mapping tombol PS3 -> bitmask
  if (Ps3.data.button.r2)       tombol |= MAJU;
  if (Ps3.data.button.l2)     tombol |= MUNDUR;
  if (Ps3.data.button.r1)    tombol |= KANAN;
  if (Ps3.data.button.l1)     tombol |= KIRI;

  if (Ps3.data.button.cross)    tombol |= TUBRUK;
  if (Ps3.data.button.circle)   tombol |= SELIPR;
  if (Ps3.data.button.square)   tombol |= SELIPL;
  if (Ps3.data.button.triangle) tombol |= BACK;

  if (tombol == MAJU) {
    maju(250);
    Serial.println("majuu");

  } else if (tombol == MUNDUR) {
    mundur(255);
    Serial.println("mundurr");

  } else if (tombol == KANAN) {
    kanan(200);
    Serial.println("nganan");

  } else if (tombol == KIRI) {
    kiri(200);
    Serial.println("ngiri");

  } else if (tombol == TUBRUK) {
    tubruk(255);
    Serial.println("gass");

  } else if (tombol == SELIPR) {
    selipR();
    Serial.println("nyelip kanan");

  } else if (tombol == SELIPL) {
    selipL();
    Serial.println("nyelip kiri");

  } else if (tombol == BACK) {
    back();
    Serial.println("back stabb");

  } else {
    berenti();
    Serial.println("ga gerak");
  }
}