#include <iostream>

#include "./libraries/game.h"

// IMPORTANT: Comments explaining the functions are found in their respective .cpp files
// Opens with the game name and the main menu
int main() {
    game_name();
    while(1) {
        main_menu();
        int main_menu_choice;
        std::cin >> main_menu_choice;
        std::string return_to_menu;
        getline(std::cin, return_to_menu);
        if(main_menu_choice == 1) {
            start_game();
            std::cout << "Press enter to return to main menu...";
            getline(std::cin, return_to_menu);
            getline(std::cin, return_to_menu);
            std::cout << std::endl;
        } else if(main_menu_choice == 2) {
            instructions();
            std::cout << "Press enter to return to main menu...";
            getline(std::cin, return_to_menu);
            std::cout << std::endl;
        } else {
            break;
        }
        main_menu_choice = 0; // Resets the choice of the user
    }
    std::cout << std::endl;
    return 0;
}