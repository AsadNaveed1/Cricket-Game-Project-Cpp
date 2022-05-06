#include <iostream>

#include "./constants.h"
#include "./players_and_bots.h"
#include "./ai.h"

// This function takes an input from 1 - 6 or 'q' from the player and returns it
// It has no input values into the function and returns the number chosen by the user
int player() {   
    int move;
    std::cout << "Choose a number between 1 and 6, or choose 0 to save and quit: ";
    std::cin >> move;
    while(move > 6 || move < 0) {
        std::cout << "Please only choose a number between 1 and 6, or choose 0 to save and quit: ";
        std::cin >> move;
    }
    std::cout << std::endl;
    return move;
}

// This function makes the move for the AI by using the smart_batting_choice() and smarat_bowling_choice() functions
// For the first ball of the innings, the user has no previous moves stored in the deque and so the ai move is based only a random number from 1 - 6
// It takes in the deque, current ball, and which team is currently batting and returns the the number chosen by the smart AI (from 1 - 6) 
int comp(std::deque<int> &smart_ai_mem, int &curr_ball, bool &player_batting_bool) {
    if(curr_ball == 0) {
        int move = rand() % 6 + 1;
        std::cout << "The number delivered by the opponent is: " << move << std::endl << std::endl;
        return move;
    }

    int sum = 0;
    std::deque<int>::iterator itr;
    for(itr = smart_ai_mem.begin(); itr != smart_ai_mem.end(); itr++) {
        sum += *itr;
    }

    int avg;
    if(curr_ball < SMART_AI_STORAGE_SIZE) avg = sum / curr_ball;
    else avg = sum / SMART_AI_STORAGE_SIZE;

    int move;
    if(player_batting_bool) move = smart_bowling_choice(avg);
    else move = smart_batting_choice(avg);

    std::cout << "The number delivered by the opponent is: " << move << std::endl << std::endl;
    return move;
}