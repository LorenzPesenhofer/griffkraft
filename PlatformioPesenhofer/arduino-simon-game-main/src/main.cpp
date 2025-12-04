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
    Serial.println("Yellow has been pressed");

    //Naiver Ansatz --> wird verbessert (entfernt)
    digitalWrite(LED_GRE, HIGH);
    delay(2000);
    digitalWrite(LED_GRE, LOW);
  }

  if(btnBlue.pressed())
  {
    Serial.println("Blue has been pressed");
  }
}
