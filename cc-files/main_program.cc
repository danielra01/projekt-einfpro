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
#include "demonstration.h"

bool first_run = true;
bool logging = false;
const unsigned int cols = 106;  // Number of columns for the nice looking output set it to -1 to disable this feature
// NOTE: This causes some trouble when used with ä,ü,ö and ß

void clear_console() {
    for (int x = 0; x < 100; x++) {
        std::cout << "" << std::endl;
    }
}


void format_for_print(std::string text) {
    if (cols > 0) {
        int number_of_lines = floor(text.size() / cols);
        for (int k = 1; k <= number_of_lines + 1; k++) {
            std::string line = "# ";
            int counter = 0;
            for (int l = 0; l <= cols; l++) {
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
            std::cout << line <<  " #" << std::endl;
        }
    } else {
        std::cout << text << std::endl;
    }
}


void encrypt() {
    clear_console();
    std::cout << "Bitte geben Sie einen zu verschlüsselnden Text ein\n >> ";
    //Todo: Check for length
    std::string mein_text;
    std::cin.ignore();
    getline(std::cin, mein_text);

    if (logging) {
        std::cout << "LOG: Starting encryption module..." << std::endl;
    }
    std::string encrypted;
    try {
        encrypted = encrypt_text(mein_text);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        encrypted = "";
    }
    if (! (encrypted == "")) {
        clear_console();
        std::cout << "\n\n\n############################################ Verschlüsselter Text #############################################" << std::endl;
        format_for_print(encrypted);
        std::cout << "###############################################################################################################\n" << std::endl;
    }
}

void decrypt() {
    if (logging) {
        std::cout << "LOG: Starting decryption module..." << std::endl;
    }
    clear_console();
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
        clear_console();
        std::cout << "############################################ Entschlüsselter Text #############################################" << std::endl;
        format_for_print(decrypted);
        std::cout << "###############################################################################################################\n" << std::endl;
    }
}

void demonstration() {
    clear_console();
    demo_module();
    if (logging) {
        std::cout << "LOG: Starting demo module..." << std::endl;
    }
}

int main() {
    // Handle user choice
    bool running = true;
    while (running) {
        if (first_run) {
            clear_console();
            std::cout << "###############################################################################################################" << std::endl;
            std::cout << "#    _____                                                                                                    #" << std::endl;
            std::cout << "#   / ____|                                                                                                   #" << std::endl;
            std::cout << "#  | |        __ _    ___   ___    __ _   _ __     ______                                                     #" << std::endl;
            std::cout << "#  | |       / _` |  / _ \\ / __|  / _` | | '__|   |______|                                                    #" << std::endl;
            std::cout << "#  | |____  | (_| | |  __/ \\__ \\ | (_| | | |                                                                  #" << std::endl;
            std::cout << R"(#   \_____|  \__,_|  \___| |___/  \__,_| |_|                                                                  #)" << std::endl;
            std::cout << "#                                                                                                             #" << std::endl;
            std::cout << "#   __      __                             _       _   _   _                      _                           #" << std::endl;
            std::cout << R"(#   \ \    / /                            | |     | | (_) (_)                    | |                          #)" << std::endl;
            std::cout << R"(#    \ \  / /    ___   _ __   ___    ___  | |__   | |  _   _   ___   ___    ___  | |  _   _   _ __     __ _   #)" << std::endl;
            std::cout << R"(#     \ \/ /    / _ \ | '__| / __|  / __| | '_ \  | | | | | | / __| / __|  / _ \ | | | | | | | '_ \   / _` |  #)" << std::endl;
            std::cout << R"(#      \  /    |  __/ | |    \__ \ | (__  | | | | | | | |_| | \__ \ \__ \ |  __/ | | | |_| | | | | | | (_| |  #)" << std::endl;
            std::cout << R"(#       \/      \___| |_|    |___/  \___| |_| |_| |_|  \__,_| |___/ |___/  \___| |_|  \__,_| |_| |_|  \__, |  #)" << std::endl;
            std::cout << "#                                                                                                      __/ |  #" << std::endl;
            std::cout << "#                                                                                                     |___/   #" << std::endl;
            std::cout << "#                                                                                                             #" << std::endl;
            std::cout << "#                                                            Copyright 2021 by Theresa Maurer & Daniel Rath   #" << std::endl;
            first_run = false;
        }

        std::cout << "###############################################################################################################" << std::endl;
        std::cout << "#      Bitte ein Modul auswählen:                                                                             #\n#       1. Verschlüsseln             2. Entschlüsseln            3. Demonstration            4. Beenden       #\n#  [1,2,3,4] >> ";
        int choice;
        std::cin >> choice;
        // TODO: Add check for choice being an integer here
        switch (choice) {
            case 1: encrypt(); break;
            case 2: decrypt(); break;
            case 3: demonstration(); break;
            case 4: running = false; break;
        }
    }
    // Logging
    if (logging) {
        std::cout << "LOG: Exiting...!" << std::endl;
    }
    return 0;
}
