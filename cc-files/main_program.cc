/* This is the main file containing all function calls and user interaction
 * Please ALLWAYS execute this file and not the other functions directly
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <math.h>
#include "encrypt.h"
#include "decrypt.h"
#include "global.h"

bool logging = true;

void encrypt() {
    if (logging) {
        std::cout << "LOG: Starting encryption module..." << std::endl;
    }
    std::string encrypted;
    try {
        encrypted = encrypt_text();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        encrypted = "";
    }
    if (! (encrypted == "")) {  // TODO: Add for loop for a better format of output (like decrypt one)
        std::cout << "\n\n\n############## Verschlüsselter Text ##############" << std::endl;
        std::cout << encrypted << std::endl;
        std::cout << "##################################################\n\n" << std::endl;
    }
}

void decrypt() {
    if (logging) {
        std::cout << "LOG: Starting decryption module..." << std::endl;
    }
    std::cout << "\n\n\n\n";
    std::cout << "Bitte den zu entschlüsselnden Text eigeben: ";
    std::string text_for_decryption;
    std::cin.ignore();
    std::getline(std::cin, text_for_decryption);  // get line because of possible space character

    std::string decrypted;
    try {
        decrypted = decrypt_text(text_for_decryption);
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
        decrypted = "";
    }

    if (! (decrypted == "")) {
        std::cout << "\n\n\n############################### Entschlüsselter Text ################################" << std::endl;
        int number_of_lines = floor(decrypted.size() / 80);
        for (int k = 1; k <= number_of_lines + 1; k++) {
               std::string line = "# ";
               for (int l = 0; l <= 80; l++) {
                   if ((k-1)*80+l < decrypted.size()) {
                       line = line + decrypted[(k-1)*80 + l];
                   } else { // TODO: Add solution for moving # to the right in this case
                       break;
                   }
               }
            std::cout << line << " #" << std::endl;
        }
        std::cout << "######################################################################################\n\n" << std::endl;
    }

}

void demonstration() {
    // TODO: Add a demonstration case for presentation
    if (logging) {
        std::cout << "LOG: Starting demo module..." << std::endl;
    }
}



int main() {


    // Handle user choice
    bool running = true;
    while (running) {
        std::cout << "Bitte ein Modul auswählen: \n1. Verschlüsseln    2. Entschlüsseln    3. Demo    4. Beenden:   ";
        int choice;
        std::cin >> choice;
        // TODO: Add check for choice being an integer here

        switch (choice) {
            case 1: encrypt(); break;
            case 2: decrypt(); break;
            case 3: demonstration(); break;
            case 4: running = false; break;
            // default: std::cout << "Please only enter one number to choose module!" << std::endl; break;
        }
    }
    if (logging) {
        std::cout << "LOG: Exiting...!" << std::endl;
    }

    return 0;
}