#include <Arduino.h>
#include <Bounce2.h>

//Buttons an den Pins anhängen
const int BTN_YLW = 2;
const int BTN_BLU = 3;

const int LED_GRE = 9;
const int LED_PNK = 10;

Bounce2::Button btnYellow = Bounce2::Button();
Bounce2::Button btnBlue = Bounce2::Button();

void setup() {
  Serial.begin(9600);
  btnYellow.attach(BTN_YLW, INPUT_PULLUP);
  btnYellow.setPressedState(LOW);

  btnBlue.attach(BTN_BLU, INPUT_PULLUP);
  btnBlue.setPressedState(LOW);

  pinMode(LED_GRE, OUTPUT);
  pinMode(LED_PNK, OUTPUT);
}

void loop() {
  btnBlue.update();
  btnYellow.update();

  if(btnYellow.pressed())
  {
    for(int i = 0; i < 3 ;i++)
    {
      digitalWrite(LED_PNK, HIGH);
      delay(200);
      digitalWrite(LED_PNK, LOW);
      delay(200);
    }
    for(int i = 0; i < 3 ;i++)
    {
      digitalWrite(LED_PNK, HIGH);
      delay(1000);
      digitalWrite(LED_PNK, LOW);
      delay(1000);
    }
    for(int i = 0; i < 3 ;i++)
    {
      digitalWrite(LED_PNK, HIGH);
      delay(200);
      digitalWrite(LED_PNK, LOW);
      delay(200);
    }
  }

  if(btnBlue.pressed())
  {
    for (int i = 0; i < 10; i++)
    {
      digitalWrite(LED_GRE, HIGH);
      delay(200);
      digitalWrite(LED_GRE, LOW);
      delay(100);
      digitalWrite(LED_PNK, HIGH);
      delay(200);
      digitalWrite(LED_PNK, LOW);
      delay(100);
    }
  }
}
