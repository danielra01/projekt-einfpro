/* This is the main file containing all function calls and user interaction
 * Please ALLWAYS execute this file and not the other functions directly
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "encrypt.h"

bool logging = true;  // To enable logging

void encrypt() {
    // TODO: Call function encrypt_text and create while loop for catching exceptions
    if (logging) {
        std::cout << "Starting encryption module..." << std::endl;
    }
    try {
        std::string encrypted;
        encrypted = encrypt_text();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

}

void decrypt() {
    // TODO: Call function decrypt_text and create while loop for catching exceptions
    if (logging) {
        std::cout << "Starting decryption module..." << std::endl;
    }
}

void demonstration() {
    // TODO: Add a demonstration case for presentation
    if (logging) {
        std::cout << "Starting demo module..." << std::endl;
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
        std::cout << "Exiting...!" << std::endl;
    }

    return 0;
}