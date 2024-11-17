#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include "main.hpp"

void copyMessageSubset(char *dest, const char *progmemMessage, uint8_t start, uint8_t length);
void updateScrollBuffer(char *buffer, const char *message, int scrollPosition, uint8_t bufferSize);

#endif // STRINGUTILS_HPP
