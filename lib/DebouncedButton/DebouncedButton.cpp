#include "DebouncedButton.hpp"

DebouncedButton::DebouncedButton(uint8_t pin, uint32_t delay, bool activeState) {
    buttonPin = pin;
    debounceDelay = delay;
    lastDebounceTime = 0;
    lastButtonState = !activeState; // Start in the opposite state
    buttonState = !activeState;    // Start in the opposite state
    lastDebouncedState = !activeState; // Start in the opposite state
    pressedEvent = false;
    releasedEvent = false;
    this->activeState = activeState; // Store the active state
    pinMode(buttonPin, INPUT);
}


void DebouncedButton::update() {
    bool reading = digitalRead(buttonPin);

    if (reading != lastButtonState) {
        lastDebounceTime = millis(); // Reset debounce timer
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != buttonState) {
            // Button state has changed
            buttonState = reading;

            // Detect pressed and released events
            if (buttonState == activeState && lastDebouncedState != activeState) {
                pressedEvent = true;  // Button was just pressed
            } else if (buttonState != activeState && lastDebouncedState == activeState) {
                releasedEvent = true; // Button was just released
            }

            lastDebouncedState = buttonState;
        }
    }

    lastButtonState = reading;
}


bool DebouncedButton::isPressed() {
    this->update();
    return buttonState == activeState; // Return true if the button matches the active state
}

bool DebouncedButton::wasPressed() {
    this->update();
    if (pressedEvent) {
        pressedEvent = false; // Reset the event flag
        return true;
    }
    return false;
}

bool DebouncedButton::wasReleased() {
    this->update();
    if (releasedEvent) {
        releasedEvent = false; // Reset the event flag
        return true;
    }
    return false;
}

uint8_t DebouncedButton::getState() {
    this->update();
    return buttonState;
}
