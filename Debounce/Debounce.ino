/* 
   Debounce
 
   Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
   press), the output pin is toggled from LOW to HIGH or HIGH to LOW.  There's
   a minimum delay between toggles to debounce the circuit (i.e. to ignore
   noise).  
 
   The circuit:
   * Onboard LED attached to pin P1.0
   * Onboard push button attached to pin P1.3 (PUSH2)
 
   * Note: Everything for this sketch is on the MSP430 LaunchPad.
 
   created 21 November 2006
   by David A. Mellis
   modified 30 Aug 2011
   by Limor Fried
   modified 27 Apr 2012
   Robert Wessels
 
   This example code is in the public domain.
 
   http://www.arduino.cc/en/Tutorial/Debounce
*/
#include "Debouncer.h"

// Set the push button and LED pins.
const int PUSH_BUTTON = PUSH2;
const int LED_PIN =  GREEN_LED;

// Button debouncer
Debouncer pushButton(PUSH_BUTTON, 50);

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState = LOW;       // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    pushButton.update();
}

void loop() 
{
    int buttonState = pushButton.update();

    // set the LED using the state of the button:
    digitalWrite(LED_PIN, buttonState);
}

