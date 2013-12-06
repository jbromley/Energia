/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
*/
#include "Debouncer.h"

// 
// Minimum and maximum turn-on times for LEDs.
const int MIN_DELAY_TIME = 100;
const int MAX_DELAY_TIME = 1000;

// Current delay time.
int delayTime = 100;

// Button debouncer
Debouncer pushButton(PUSH2, 50);

// Have we incremented delay for current button push.
boolean incremented = false;

// Last update time for LEDs.
unsigned long previousUpdate;
int ledState = LOW;

int invertState(int state)
{
    return state == LOW ? HIGH : LOW;
}

void setup() 
{                
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);  

    pushButton.update();

    previousUpdate = millis();
    digitalWrite(RED_LED, ledState);
    digitalWrite(GREEN_LED, invertState(ledState));
}

void loop() {
    int buttonState = pushButton.update();
    if (buttonState == LOW) {
	if (!incremented) {
	    delayTime += 100;
	    if (delayTime > MAX_DELAY_TIME) {
		delayTime = MIN_DELAY_TIME;
	    }
	    incremented = true;
	} 
    } else {
	incremented = false;
    }

    unsigned long currentTime = millis();
    if (currentTime - previousUpdate > delayTime) {
	previousUpdate = currentTime;
	ledState = invertState(ledState);
	digitalWrite(RED_LED, ledState);
	digitalWrite(GREEN_LED, invertState(ledState));
    }
}
