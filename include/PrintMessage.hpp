/**
 * @file PrintMessage.hpp
 * @brief Function to display a message on an LCD screen with word wrapping.
 */

/**
 * @brief Prints a message on the LCD screen with automatic word wrapping.
 *
 * This function takes a message and displays it on an LCD screen, wrapping
 * the text across multiple lines while respecting the screen's width and height.
 *
 * @param message A pointer to a null-terminated character array containing the message to be displayed.
 *                The message will be modified in-place as it uses `strtok` for parsing.
 *
 * @note
 * - The LCD is assumed to have a defined width (`LCD_WIDTH`) and height (`LCD_HEIGHT`).
 * - The function uses `strtok`, which modifies the input string. Ensure that the message
 *   is not a read-only string (e.g., string literals) to avoid segmentation faults.
 * - This function assumes `lcd` and `BACKLIGHT_PIN` are globally defined and properly initialized.
 */

#ifndef LCD_PRINTMSG_H
#define LCD_PRINTMSG_H

#include "main.hpp"

 void printMessage(char *message);

#endif
