#include <Arduino.h>
#include <Bounce2.h>

#define btn_ylw 7
#define btn_blu 6

const int LED_Yellow = 8;
const int LED_Blue = 9;

int counter = 0;

Bounce2::Button btnYellow = Bounce2::Button();
Bounce2::Button btnBlue = Bounce2::Button();


void setup() {
  Serial.begin(9600);
  btnYellow.attach(btn_ylw, INPUT_PULLUP);
  btnYellow.setPressedState(LOW);
  btnBlue.attach(btn_blu, INPUT_PULLUP);
  btnBlue.setPressedState(LOW);

  pinMode(LED_Blue, OUTPUT);
  pinMode(LED_Yellow, OUTPUT);
}


void loop() {
  btnBlue.update();
  btnYellow.update();

  if(btnYellow.pressed())
  {
    Serial.println("Yellow pressed");
    digitalWrite(LED_Yellow,HIGH);
    delay(2000);
    digitalWrite(LED_Yellow,LOW);

  }
    if(btnBlue.pressed())
  {
    Serial.println("Blue pressed");
  }
}
