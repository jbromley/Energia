// Debouncer.cpp
// Debounce a button read.
#include "Debouncer.h"

Debouncer::Debouncer(int button, long debounceDelay /* = 25 */)
    : m_button(button), 
      m_buttonState(HIGH), 
      m_lastButtonState(HIGH), 
      m_debounceDelay(debounceDelay)
{
    pinMode(button, INPUT_PULLUP);
}

int Debouncer::update()
{
    int readState = digitalRead(m_button);

    if (readState != m_lastButtonState) {
	m_lastDebounceTime = millis();
    }

    if ((millis() - m_lastDebounceTime) > m_debounceDelay) {
	m_buttonState = readState;
	Serial.println("button debounced");
    }

    m_lastButtonState = readState;

    return m_buttonState;
}
