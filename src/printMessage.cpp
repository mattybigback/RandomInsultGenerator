#include "printMessage.hpp"

void printMessage(char* message) {
  uint8_t lineLength = 0; // Current line length
  uint8_t line = 0; // Current line number
  char lineBuffer[LCD_WIDTH + 1] = {0}; // Buffer to hold the text of each line with initialization
  char* word = strtok(message, " ");
  debugPrintLn("Resetting screen");
  lcd.setCursor(0,0);
  lcd.clear();
  debugPrintLn("Powering screen on");
  lcd.display();
  debugPrintLn("Backlight to full brightness");
  brightness = 255;                         // Set brigntness variable
  analogWrite(BACKLIGHT_PIN, brightness);   // Write brightness
  while (word != NULL && line < LCD_HEIGHT) {
    uint8_t wordLength = strlen(word);
    uint8_t spaceNeeded = lineLength == 0 ? wordLength : wordLength + 1;

    // Check if there is a need to move to a new line
    if (lineLength + spaceNeeded > LCD_WIDTH) {
      lcd.setCursor(0, line);
      lcd.print(lineBuffer);
      line++;
      lineLength = 0;
      lineBuffer[0] = '\0'; // Reset buffer
      if (line >= LCD_HEIGHT) break;
    }

    // Add a space before the word if it's not the first word on the line
    if (lineLength > 0) {
      strncat(lineBuffer, " ", LCD_WIDTH - lineLength); // Safe to add one space
      lineLength++;
    }

    // Add the word to the buffer
    strncat(lineBuffer, word, LCD_WIDTH - lineLength);
    lineLength += wordLength;

    // Move to next word
    word = strtok(NULL, " ");
  }

  // Print the last buffered line if any
  if (lineLength > 0) {
    lcd.setCursor(0, line);
    lcd.print(lineBuffer);
  }
}