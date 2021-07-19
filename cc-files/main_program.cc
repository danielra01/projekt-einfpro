/* This is the main file containing all function calls and user interaction
 * Please ALLWAYS execute this file and not the other functions directly
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "encrypt.h"
#include "global.h"

bool logging = false;

void encrypt() {
    // TODO: Call function encrypt_text and create while loop for catching exceptions
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
    if (! (encrypted == "")) {  // TODO: Add for loop for a better format of output
        std::cout << "\n\n\n############## Verschlüsselter Text ##############" << std::endl;
        std::cout << encrypted << std::endl;
        std::cout << "##################################################\n\n" << std::endl;
    }
}

void decrypt() {
    // TODO: Call function decrypt_text and create while loop for catching exceptions
    if (logging) {
        std::cout << "LOG: Starting decryption module..." << std::endl;
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