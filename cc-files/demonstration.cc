/* This file is used for a demo of the ceasar-encryption. Please
 * use the main_programm file since this is only the logic for the demo.
 */


#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <stdexcept>
#include "global.h"
#include "decrypt.h"
#include "encrypt.h"

int cols = 106;

void format_for_print_2(std::string text) {
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


void demo_module() {
    std::cin.ignore();
    std::cout << "Herzlich Willkommen im Demo-Modul für dieses Programm!\n\n" << std::endl;
    std::cout << "Zuerst braucht es einen deutschen Text mit mindestens 26 Zeichen:\n >> ";

    std::string mein_text;
    std::cin.ignore();
    std::getline(std::cin, mein_text);

    std::string encrypted;
    try {
        encrypted = encrypt_text(mein_text);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        encrypted = "";
    }
    if (!(encrypted=="")) {
        std::cout << "\n############################################ Verschlüsselter Text #############################################\n" << std::endl;
        format_for_print_2(encrypted);
        std::cout << "###############################################################################################################\n" << std::endl;
    } else {
        std::cout << "FEHLER: Leider ist etwas schiefgelaufen!" << std::endl;
    }
    std::cout << "Dieser Text soll jetzt durch das Programm wieder entschlüsselt werden." << std::endl;
    std::cout << "Starte Entschlüsselung...\n\n" << std::endl;
    std::string decrypted;
    decrypted = decrypt_text(encrypted);

    std::cout << "\n############################################ Entschlüsselter Text #############################################\n" << decrypted << "\n\n\n\n" <<std::endl;

}