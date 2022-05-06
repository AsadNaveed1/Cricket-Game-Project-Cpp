#include <iostream>
#include <iomanip>

#include "./game_mechanics.h"
#include "./constants.h"

// This function starts the toss and allows you to choose to start with the batting or bowling side if you win the toss
// It takes the variable that checks whether the user is batting ('player_batting_bool') as an input and sets 'player_batting_bool' to either true or false depending on the results of the toss
// It has no return value
void toss(bool &player_batting_bool) {    
    int coin_side_chosen, coin_side_landed;

    std::cout << std::endl << "WELCOME TO TOSS!" << std::endl << std::endl;
   
    std::cout << "Please enter '1' for Heads and '2' for Tails: ";
    std::cin >> coin_side_chosen;
    while(coin_side_chosen != 1 && coin_side_chosen != 2) {
        std::cout << "Please only enter '1' or '2' to select your choice: ";
        std::cin >> coin_side_chosen;
    }

    coin_side_landed = rand() % 2 + 1;
    bool toss_result;
    int side_choice;

    if(coin_side_landed == coin_side_chosen) {
        std::cout << std::endl << std::setw(PRETTY_PRINT_NUM) << std::setfill('-') << DUMMY_CHAR << " You've won the Toss " << std::setw(PRETTY_PRINT_NUM) << std::setfill('-') << DUMMY_CHAR << std::endl << std::endl;
        std::cout << "Select your side - please enter '1' for batting and '2' for bowling: ";
        std::cin >> side_choice;
    } else {
        std::cout << std::endl << std::setw(PRETTY_PRINT_NUM) << std::setfill('-') << DUMMY_CHAR << " You've lost the Toss " << std::setw(PRETTY_PRINT_NUM) << std::setfill('-') << DUMMY_CHAR << std::endl;
        side_choice = rand() % 2 + 1;
    }

    while(side_choice != 1 && side_choice != 2) {
        std::cout << "Please only enter '1' or '2' to select your choice: ";
        std::cin >> side_choice;
    }
    std::cout << std::endl;

    if(side_choice == 1) {
        player_batting_bool = true;
    } else if(side_choice == 2) {
        player_batting_bool = false;
    }
}

// Switches the batting and bowling sides in a cricket match
// It takes in the variable that checks whether the user is batting currently (player_batting_bool) and returns the team that isn't batting as the team that is batting (sets true to false and vice versa)
void switch_teams(bool &player_batting_bool) {
    if (player_batting_bool == true) {
        player_batting_bool = false;
    } else {
        player_batting_bool = true;
    }
}