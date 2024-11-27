/**
 * @file DebouncedButton.hpp
 * @brief Library for debouncing button presses.
 */

#ifndef DEBOUNCEDBUTTON_HPP
#define DEBOUNCEDBUTTON_HPP

#include <Arduino.h>

/*
 * @brief Constructs a new DebouncedButton object.
 * 
 * @param pin The GPIO pin number connected to the button.
 * @param delay The debounce delay in milliseconds to ignore button state changes.
 * @param activeState The active state of the button (e.g., HIGH for active-high, LOW for active-low).
 */
class DebouncedButton {
private:
    uint8_t buttonPin;
    uint32_t lastDebounceTime;
    uint32_t debounceDelay;
    uint8_t lastButtonState;
    uint8_t buttonState;
    uint8_t lastDebouncedState;
    bool activeState;
    bool pressedEvent;
    bool releasedEvent;

public:
    DebouncedButton(uint8_t pin, uint32_t delay = 50, bool activeState = LOW);

    /**
    * @brief Updates the button's state by reading its input and handling debounce logic.
    */
    void update();

    /**
    * @brief Checks if the button is currently pressed.
    * 
    * @return true if the button is in the active state (pressed); false otherwise.
    */
    bool isPressed();     // Returns true if the button is currently pressed

    /**
     * @brief Checks if the button was pressed since the last check.
     * 
     * This method will return `true` only once for each press event and will reset the
     * internal press event flag after being called.
     * 
     * @return true if the button was pressed since the last check; false otherwise.
     */
    bool wasPressed();    // Returns true only once when the button is pressed

    /**
     * @brief Checks if the button was released since the last check.
     * 
     * This method will return `true` only once for each release event and will reset the
     * internal release event flag after being called.
     * 
     * @return true if the button was released since the last check; false otherwise.
     */
    bool wasReleased();   // Returns true only once when the button is released

    /**
     * @brief Gets the raw current state of the button.
     * 
     * @return The current state of the button as read from the digital input pin.
     *         This value is not debounced.
     */
    uint8_t getState();
};

#endif // DEBOUNCEDBUTTON_HPP
