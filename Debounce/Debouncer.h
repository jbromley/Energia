// Debounce a button press.
#include "Energia.h"

class Debouncer
{
public:
    Debouncer(int button, long debounceDelay = 50);
    int update();
  
private:
    int m_button;
    int m_buttonState;
    int m_lastButtonState;
    long m_lastDebounceTime;
    long m_debounceDelay;
};
