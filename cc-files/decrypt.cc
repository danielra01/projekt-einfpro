/* This file is used for the decryption of any ceasar-encrypted text. Please
 * use the main_programm file since this is only the logic
 */

#include <iostream>
#include <string>
#include <queue>
//#include <bits/stdc++.h>
#include <utility>
#include <stdexcept>
#include "global.h"

std::string decrypt_text(std::string text_to_decrypt) {
    // Check for new e by looking for letter with highest occurrence
    // Therefore creating a PriorityQueue

    // Check that input doesn't contain any upper case letters
    for (int u = 0; u < text_to_decrypt.size(); u++) {
        if (((int)text_to_decrypt[u] > 64 ) && ((int)text_to_decrypt[u] < 91 )) {
            text_to_decrypt[u] = (char) ((int)text_to_decrypt[u] + 32);  // +32 in ascii converts to lower case
        }
    }

    if (text_to_decrypt.size() <= 25) {
        throw std::invalid_argument( "FEHLER: Bitte einen längeren Text eingeben!" );
    }
    std::priority_queue<std::pair<int, char>> char_queue;
    // Loop to every letter in the alphabet
    for (int i = 1; i <= 26; i++){
        char current_char = (char)(96 + i);
        int counter = 0;
        for (int j = 0; j < text_to_decrypt.size(); j++){
            if (text_to_decrypt[j] == current_char) {
                counter++;
            }
        }
        char_queue.push(std::make_pair(counter, current_char));
    }

    // Now calculate the difference between the e the most occurring letter
    for (int i = 1; i <= 3; i++) {
        char new_e_char = std::get<1>(char_queue.top());
        if (logging) {
            std::cout << "LOG: Possibly identified " << new_e_char << " as new e" << std::endl;
        }

        int new_e_int = (int) new_e_char;
        int diff = new_e_int - 101;  // in ascii e is 101

        std::string result;
        for (int j = 0; j < text_to_decrypt.size(); j++) {
            int current = (int) text_to_decrypt[j];
            char shifted_char;
            if ((97 <= current) && (current <= 122)) {
                shifted_char = (char) (((current - 97) + 26 - diff) % 26) + 97;
            } else {
                shifted_char = text_to_decrypt[j];
            }
            result.push_back(shifted_char);
        }

        // Check if this is correct
        std::cout << "Mögliche Lösung: " << result.substr(0,30) << "..."    << "\nIst das ein korrekter Text?\n [j,n] >> ";
        std::string correct;
        std::cin >> correct;
        if (correct == "j") {
            return result;
        } else if (correct == "n") {
            char_queue.pop();  // To delete and if needed get a new maximum later
            continue;
        } else {
            throw std::invalid_argument("FEHLER: Bitte j für ja oder n für nein wählen");
        }

    }  // We now have checked four different shifts but nothing worked, therefore one could assume, something isn't quiet right with the input
    throw std::invalid_argument("FEHLER: Dieser Text ist wahrscheinlich nicht mit einer Caesar-Verschlüsselung verschlüsselt worden!");
}

