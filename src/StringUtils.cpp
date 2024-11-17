#include "StringUtils.hpp"

void copyMessageSubset(char *dest, const char *progmemMessage, uint8_t start, uint8_t length) {
    for (uint8_t i = 0; i < length; i++) {
        dest[i] = pgm_read_byte(progmemMessage + start + i);
    }
    dest[length] = '\0';
}

void updateScrollBuffer(char *buffer, const char *message, int scrollPosition, uint8_t bufferSize) {
    memset(buffer, ' ', bufferSize);
    buffer[bufferSize] = '\0';

    for (uint8_t bufferIndex = 0; bufferIndex < bufferSize; bufferIndex++) {
        int8_t msgIndex = scrollPosition + bufferIndex;
        if (msgIndex >= 0 && msgIndex < static_cast<int16_t>(strlen_P(message))) {
            buffer[bufferIndex] = pgm_read_byte(&message[msgIndex]);
        }
    }
}
