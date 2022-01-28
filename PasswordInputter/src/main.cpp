#include <Arduino.h>
#include <ezButton.h>
#include "Keyboard.h"

//Definition Pins
#define PIN_BUTTON 5

#define PASSWORD "Password"

ezButton button(PIN_BUTTON);  // create ezButton object that attach to pin PIN_BUTTON;

void setup()
{
  //pinMode(PIN_BUTTON, INPUT);
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
  Keyboard.begin();
}

void loop() {
  button.loop(); // MUST call the loop() function first

  if(button.isPressed())
  {
    //Sende Passwort
    Keyboard.print(PASSWORD);
  }

  if(button.isReleased())
  {
    //no action
  }
}
