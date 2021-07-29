#include <iostream>
#include <string>

void format_for_print(std::string text, int columns) {
    if (columns > 0) {
        int number_of_lines = floor(text.size() / columns);
        for (int k = 1; k <= number_of_lines + 1; k++) {
            std::string line = "# ";
            int counter = 0;
            for (int l = 0; l <= columns; l++) {
                counter++;
                if ((k-1)*columns+l < text.size()) {
                    line = line + text[(k-1)*columns + l];
                } else {
                    for (int n = l; n <= columns; n++) {
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