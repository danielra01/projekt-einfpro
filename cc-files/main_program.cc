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
const unsigned int cols = 80;  // Number of columns for the nice looking output

void format_for_print(std::string text) {
    int number_of_lines = floor(text.size() / cols);
    for (int k = 1; k <= number_of_lines + 1; k++) {
        std::string line = "# ";
        int counter = 0;
        for (int l = 0; l < cols; l++) {
            counter++;
            if ((k-1)*cols+l < text.size()) {
                line = line + text[(k-1)*cols + l];
            } else {
                for (int n = l; n <= cols; n++) {
                    line = line + " ";
                }
                break;
            }
        }
        std::cout << line << " #: "<< counter << std::endl;
    }
}


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
    if (! (encrypted == "")) {
        std::cout << "\n\n\n############## Verschlüsselter Text ##############" << std::endl;
        format_for_print(encrypted);
        std::cout << "##################################################\n\n" << std::endl;
    }
}

void decrypt() {
    if (logging) {
        std::cout << "LOG: Starting decryption module..." << std::endl;
    }
    std::cout << "\n\n\n\n";
    std::cout << "Bitte den zu entschlüsselnden Text eigeben\n >> ";
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
        format_for_print(decrypted);
        std::cout << "#####################################################################################\n\n" << std::endl;
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
        std::cout << "Bitte ein Modul auswählen: \n1. Verschlüsseln    2. Entschlüsseln    3. Demo    4. Beenden\n [1,2,3,4] >> ";
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
