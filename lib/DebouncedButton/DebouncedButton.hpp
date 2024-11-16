#ifndef DEBOUNCEDBUTTON_HPP
#define DEBOUNCEDBUTTON_HPP

#include <Arduino.h>

class DebouncedButton {
private:
    uint8_t buttonPin;
    uint32_t lastDebounceTime;
    uint32_t debounceDelay;
    int lastButtonState;
    int buttonState;
    int lastDebouncedState;
    bool pressedEvent;
    bool releasedEvent;

public:
    DebouncedButton(uint8_t pin, uint32_t delay = 50);

    void update();

    bool isPressed();     // Returns true if the button is currently pressed
    bool wasPressed();    // Returns true only once when the button is pressed
    bool wasReleased();   // Returns true only once when the button is released

    int getState();
};

#endif // DEBOUNCEDBUTTON_HPP
