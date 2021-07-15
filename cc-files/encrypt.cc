/* This file contains all the necessary code for encrypting a given text or
 * string for later trying to decrypt it
 */

#include <iostream>
#include <string>


int main() {
    
    std::cout << "Bitte geben Sie einen zu verschlüsselnden Text ein: ";
    std::string mein_text;
    std::getline(std::cin, mein_text);
    
    if (mein_text.length() <= 25) {
        std::cout << "Bitte einen längeren Text eingeben" << std::endl;
        return 1;
    }

    std::cout << "Bitte geben Sie die Verschlüsselung ein: A -> ";
    const char abcd = std::cin;
    std::cout << mein_text << std::endl;
    std::cout << "A wird zu " << abcd << std::endl;
    return 0;
}
    
