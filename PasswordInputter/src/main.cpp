#include <Arduino.h>
#include "Keyboard.h"

//Definition Pins
#define PIN_BUTTON 5

#define PASSWORD "Password"

//globale Variablen
byte buttonState = 0;

//SW Entprellung Taster
bool isButtonPressed(byte buttonPin)
{
  byte buttonValue = digitalRead(buttonPin);

  if(buttonState == 0 && buttonValue == HIGH)
  {
    // Taster wird gedrückt (steigende Flanke)
    buttonState = 1;
    return true;
  }
  else if (buttonState == 1 && buttonValue == HIGH)
  {
    // Taster wird gehalten
    buttonState = 2;
    return false;
  }
  else if (buttonState == 2 && buttonValue == LOW)
  {
    // Taster wird losgelassen (fallende Flanke)
    buttonState = 3;
    return false;
  }
  else if (buttonState == 3 && buttonValue == LOW)
  {
    // Taster losgelassen
    buttonState = 0;
    return false;
  }
}


void setup()
{
  //Initialisierung Buttons
  pinMode(PIN_BUTTON, INPUT);
  Keyboard.begin();
}

void loop()
{
  //Knopf gedrückt --> PW schreiben
  if(isButtonPressed == true)
  {
    //Sende Passwort
    Keyboard.print(PASSWORD);
  }
}
