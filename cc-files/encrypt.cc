/* This file contains all the necessary code for encrypting a given text or
 * string for later trying to decrypt it
 */

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    
    std::cout << "Bitte geben Sie einen zu verschlüsselnden Text ein: ";
    std::string mein_text;
    std::getline(std::cin, mein_text);
    
    if (mein_text.length() <= 25) {
        std::cout << "Bitte einen längeren Text eingeben" << std::endl;
        return 1;
    }

    std::cout << "Bitte geben Sie die Verschlüsselung ein: a -> ";
    char new_A_char;
    std::cin >> new_A_char;
    if ((97 <= new_A_char) && (new_A_char <= 122)) {
        std::cout << "a wird zu " << new_A_char << std::endl;
    } else {
        return 1;  // Has to be a lower case letter
    }
    std::cout << "Starte Verschlüsselung..." << std::endl;
    int new_A_ord = (int)new_A_char;

    // Convert to lower case string
    transform(mein_text.begin(), mein_text.end(), mein_text.begin(), ::tolower);
    std::cout << "Convert to lower case string: ";
    std::cout << mein_text << std::endl;

    // Start encryption of every character in the string by iterating over them
    // Calculate difference
    int diff = new_A_ord - 97;  // difference to a
    std::string mein_text_encrypted;
    char new_letter;
    for (int i = 0; i < mein_text.length(); i++) {
        int ord_i = (int)mein_text[i];
        if ((97 <= ord_i) && (ord_i <= 122)) {  // To only inlcude letters
            ord_i = ((ord_i - 97) + diff) % 26;
            ord_i = ord_i + 97;  // Shift back to ascii
        }
        new_letter = (char)ord_i;
        mein_text_encrypted.push_back(new_letter);
    }
    std::cout << mein_text_encrypted << std::endl;
    return 0;
}
    
