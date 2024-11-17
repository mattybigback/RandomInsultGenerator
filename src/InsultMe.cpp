#include "InsultMe.hpp"

RandomNoDupes rndInsult;
RandomNoDupes rndObservation;
RandomNoDupes rndAdjective;
RandomNoDupes rndCommand;

void insultMe() {
    debugPrintLn("Insult triggered");
    char buffer[BUFFER_SIZE] = {0}; // Buffer for constructing the message
    screenNumber = 1;
    timerOld = timer;
    uint8_t insultType = random(2); // Choose insult type randomly
    // Buffer for temporary storage of PROGMEM strings
    char tempWord[BUFFER_SIZE]; // Ensure this is large enough for the largest word in your tables
    debugPrint("Insult type ");
    debugPrintLn(insultType);
    if (insultType == 0) {
        uint8_t idxCommand = rndCommand.next(commandCount);
        debugPrint("Command index: ");
        debugPrintLn(idxCommand);
        uint8_t idxAdjective = rndAdjective.next(adjectiveCount);
        debugPrint("Adjective index: ");
        debugPrintLn(idxAdjective);

        // Retrieve words from PROGMEM and store in tempWord
        strcpy_P(tempWord, reinterpret_cast<char *>(pgm_read_word(&(command_table[idxCommand]))));
        snprintf(buffer, sizeof(buffer), "%s you ", tempWord);

        strcpy_P(tempWord, reinterpret_cast<char *>(pgm_read_word(&(adjective_table[idxAdjective]))));
        uint8_t currentLen = strlen(buffer);
        snprintf(buffer + currentLen, sizeof(buffer) - currentLen, "%s", tempWord);

    } else {
        uint8_t idxObservation = rndObservation.next(observationCount);
        debugPrint("Observation index: ");
        debugPrintLn(idxObservation);
        strcpy_P(tempWord, reinterpret_cast<char *>(pgm_read_word(&(observation_table[idxObservation]))));
        snprintf(buffer, sizeof(buffer), "%s", tempWord);
    }

    // Append insult
    uint8_t idxInsult = rndInsult.next(insultCount);
    debugPrint("Noun index: ");
    debugPrintLn(idxInsult);
    strcpy_P(tempWord, reinterpret_cast<char *>(pgm_read_word(&(insult_table[idxInsult]))));
    uint8_t currentLen = strlen(buffer);
    snprintf(buffer + currentLen, sizeof(buffer) - currentLen, " %s", tempWord);
    // Correct 'a' to 'an' if the next word starts with a vowel
    for (char *articlePos = strstr(buffer, " a "); articlePos; articlePos = strstr(articlePos + 1, " a ")) {
        const char *nextWordStart = articlePos + 3; // Start of the next word after " a "
        if (strchr("aeiouAEIOU", *nextWordStart)) {
            debugPrintLn("Correcting a to an");
            int remaining = sizeof(buffer) - (articlePos - buffer) - 2; // Remaining buffer size after 'an'
            memmove(articlePos + 3, articlePos + 2, remaining);
            articlePos[2] = 'n'; // Change " a " to " an "
        }
    }
    debugPrintLn(buffer);
    printMessage(buffer);
}