/* This file is used for the decryption of any ceasar-encrypted text. Please
 * use the gui file since this is only the logic
 */

#include <iostream>
#include <string>
#include <queue>
#include <bits/stdc++.h>

void decrypt_text() {
    std::string encrypted_text = "Hallo das ist ein Test!";    
    // Check for new e
    // Create Queue
    std::priority_queue<std::pair<int, char>> char_queue;

    for (int i = 1; i <= 26; i++){
        char current_char = (char)(96 + i);
        int counter = 0;
        for (int j = 0; j < encrypted_text.size(); j++){
            if (encrypted_text[j] == current_char) {
                counter++;
            }
        }
        char_queue.push(std::make_pair(counter, current_char));
    }
}

