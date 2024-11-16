#include "DebouncedButton.hpp"

DebouncedButton::DebouncedButton(uint8_t pin, uint32_t delay) {
    buttonPin = pin;
    debounceDelay = delay;
    lastDebounceTime = 0;
    lastButtonState = HIGH;
    buttonState = HIGH;
    lastDebouncedState = HIGH;
    pressedEvent = false;
    releasedEvent = false;
    pinMode(buttonPin, INPUT);
}

void DebouncedButton::update() {
    int reading = digitalRead(buttonPin);

    if (reading != lastButtonState) {
        lastDebounceTime = millis(); // Reset debounce timer
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != buttonState) {
            // Button state has changed
            buttonState = reading;

            // Detect pressed and released events
            if (buttonState == LOW && lastDebouncedState == HIGH) {
                pressedEvent = true;  // Button was just pressed
            } else if (buttonState == HIGH && lastDebouncedState == LOW) {
                releasedEvent = true; // Button was just released
            }

            lastDebouncedState = buttonState;
        }
    }

    lastButtonState = reading;
}

bool DebouncedButton::isPressed() {
    return buttonState == LOW; // Adjust if your button logic is reversed
}

bool DebouncedButton::wasPressed() {
    if (pressedEvent) {
        pressedEvent = false; // Reset the event flag
        return true;
    }
    return false;
}

bool DebouncedButton::wasReleased() {
    if (releasedEvent) {
        releasedEvent = false; // Reset the event flag
        return true;
    }
    return false;
}

int DebouncedButton::getState() {
    return buttonState;
}
