/* This file is used for a demo of the ceasar-encryption. Please
 * use the main_programm file since this is only the logic for the demo.
 */

#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>
#include "global.h"
#include "decrypt.h"
#include "encrypt.h"
#include "format_print.h"


void demo_module() {
    std::cout << "Herzlich Willkommen im Demo-Modul für dieses Programm!\n\n" << std::endl;
    std::cout << "Zuerst braucht es einen deutschen Text mit mindestens 26 Zeichen:\n >> ";

    std::cin.ignore();
    std::string mein_text;
    std::getline(std::cin, mein_text);

    std::string encrypted;
    try {
        encrypted = encrypt_text(mein_text);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        encrypted = "";
    }
    if (!(encrypted=="")) {
        std::cout << "\n############################################ Verschlüsselter Text #############################################" << std::endl;
        format_for_print(encrypted, cols);
        std::cout << "###############################################################################################################\n" << std::endl;
    } else {
        std::cout << "FEHLER: Leider ist etwas schiefgelaufen!" << std::endl;
    }
    std::cout << "Dieser Text soll jetzt durch das Programm wieder entschlüsselt werden." << std::endl;
    std::cout << "Starte Entschlüsselung...\n\n" << std::endl;

    std::string decrypted;
    decrypted = decrypt_text(encrypted);

    std::cout << "\n############################################ Entschlüsselter Text #############################################" <<std::endl;
    format_for_print(decrypted, cols);
    std::cout << "###############################################################################################################\n\n\n" << std::endl;

}