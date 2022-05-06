#include <iostream>
#include <time.h>
#include <cmath>
#include <iomanip>

#include "./constants.h"
#include "./saving_and_loading.h"
#include "./ai.h"
#include "./game_mechanics.h"
#include "./players_and_bots.h"
#include "./cricketer.h"

// This function is used for printing out the game name
// It takes no inputs and returns no value
void game_name() {
    std::cout << std::endl;
    std::cout << "|" << std::setw(2 * PRETTY_PRINT_NUM) << std::setfill('-') << DUMMY_CHAR << "|" << std::endl << std::endl;
    std::cout << "    " << " ██████╗██████╗ ██╗ ██████╗██╗  ██╗███████╗████████╗" << std::endl;
    std::cout << "    " << "██╔════╝██╔══██╗██║██╔════╝██║ ██╔╝██╔════╝╚══██╔══╝" << std::endl;
    std::cout << "    " << "██║     ██████╔╝██║██║     █████╔╝ █████╗     ██║   " << std::endl;
    std::cout << "    " << "██║     ██╔══██╗██║██║     ██╔═██╗ ██╔══╝     ██║   " << std::endl;
    std::cout << "    " << "╚██████╗██║  ██║██║╚██████╗██║  ██╗███████╗   ██║   " << std::endl;
    std::cout << "    " << " ╚═════╝╚═╝  ╚═╝╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝   ╚═╝   " << std::endl;
    std::cout << std::endl;
    std::cout << "|" << std::setw(2 * PRETTY_PRINT_NUM) << std::setfill('-') << DUMMY_CHAR << "|" << std::endl << std::endl;
}

// This function prints out the main menu screen with options to choose from for the player
// It takes in no inputs and returns no value
void main_menu() {
    std::cout << "MAIN MENU:" << std::endl;
    std::cout << "1. Start a game" << std::endl;
    std::cout << "2. Instructions" << std::endl;
    std::cout << "Press any other key to end the program" << std::endl << std::endl;
    std::cout << "Enter your decision: ";
}

// This function prints out the instruction of the game
// It takes in no inputs and returns no value
void instructions() {
    std::cout << std::endl;
    std::cout << "INSTRUCTIONS AND RULES:";
    std::cout << std::endl;
    std::cout << "1. You can choose to load a previous game or start a new game." << std::endl;
    std::cout << "1. If a new game is started, there is a toss. If you win the toss, you have to choose whether you want to bat or bowl." << std::endl;
    std::cout << "2. You have to choose how many players you want on your team, the opponent's team and how many overs in an innings." << std::endl;
    std::cout << "3. You have to choose a number between 1 and 6 when it's your turn." << std::endl;
    std::cout << "4. If your decision and your opponents decision are same, then the player who is batting is out." << std::endl;
    std::cout << "5. The team that scores more during their batting is declared as the WINNER." << std::endl;
    std::cout << "6. If both teams score same, then the result will be a draw." << std::endl << std::endl;    
}

// This function loops through the dynamic arrays which hold your team of cricketers and the opponent's team of cricketers (AI) and outputs the best player statistics as well as your final result
// It takes in the arrays, the size of the arrays, and the user and AI scores and it returns no value
void results(int &user_score, int &ai_score, int &user_num_cricketers, int &ai_num_cricketers, Cricketer** &user_cricketers_arr, Cricketer** &ai_cricketers_arr) {
    int user_best_batter_index = 0, ai_best_batter_index = 0, user_best_bowler_index = 0, ai_best_bowler_index = 0;
    int user_best_batter_score = 0, ai_best_batter_score = 0, user_best_bowler_score = 0, ai_best_bowler_score = 0;

    // Loops through user's cricketer team and stores the best batter's position in 'user_best_batter_index' and the best bowler's position in the 'user_best_bowler_index'
    for(int i = 0; i < user_num_cricketers; i++) {
        if(user_cricketers_arr[i]->score > user_best_batter_score) {
            user_best_batter_index = i;
            user_best_batter_score = user_cricketers_arr[i]->score;
        }
        if(user_cricketers_arr[i]->players_got_out > user_best_bowler_score) {
            user_best_bowler_index = i;
            user_best_bowler_score = user_cricketers_arr[i]->players_got_out;
        }
    }
    // Loops through opponent's (AI) cricketer team and stores the best batter's position in 'ai_best_batter_index' and the best bowler's position in the 'ai_best_bowler_index'
    for(int i = 0; i < ai_num_cricketers; i++) {
        if(ai_cricketers_arr[i]->score > ai_best_batter_score) {
            ai_best_batter_index = i;
            ai_best_batter_score = ai_cricketers_arr[i]->score;
        }
        if(ai_cricketers_arr[i]->players_got_out > ai_best_bowler_score) {
            ai_best_bowler_index = i;
            ai_best_bowler_score = ai_cricketers_arr[i]->players_got_out;
        }
    }

    // Outputs the users statistics found from the previous loops and the final result
    std::cout << "User Player Statistics" << std::endl;
    std::cout << "Player " << user_best_batter_index + 1 << " was the best batter on your team: Scored " << user_best_batter_score << " point(s) for you!" << std::endl;
    std::cout << "Player " << user_best_bowler_index + 1 << " was the best bowler on your team: Threw " << user_cricketers_arr[user_best_bowler_index]->balls_thrown  << " ball(s) and got " << user_best_bowler_score << " player(s) out!" << std::endl;
    std::cout << std::endl;
    std::cout << "AI Player Statistics" << std::endl;
    std::cout << "Player " << ai_best_batter_index + 1 << " was the best batter on your opponent's team: Scored " << ai_best_batter_score << " point(s) for the AI!" << std::endl;
    std::cout << "Player " << ai_best_bowler_index + 1 << " was the best bowler on your opponent's team: Threw " << ai_cricketers_arr[ai_best_bowler_index]->balls_thrown << " ball(s) and got " << ai_best_bowler_score << " player(s) out!" << std::endl;
    std::cout << std::endl;
    std::cout << "Your team score was: " << user_score << std::endl;
    std::cout << "Your opponent's team score was: " << ai_score << std::endl;
    std::cout << std::endl;
    if(user_score > ai_score) {
        std::cout << "CONGRATULATIONS, YOU HAVE WON!" << std::endl << std::endl;
    } else if(user_score < ai_score) {
        std::cout << "You have Lost... Better luck next time..." << std::endl << std::endl;
    } else {
        std::cout << "It's a Draw? Hmm... That's rare" << std::endl << std::endl;
    }
}

// Starts the game and sets srand to current time to start with a unique seed
// The variables are initialized and then the game begins in a while loop twice - once for batting and once for bowling
// Once the first innings is completed batting and bowling sides swap and after the second innings, the results are displayed
// It takes in no input values and has no return value
void start_game() {
    srand(time(0));
    
    std::cout << std::endl;

    std::cout << std::setw(2 * PRETTY_PRINT_NUM) << std::setfill('-') << DUMMY_CHAR << std::endl << std::endl;
    std::cout << "GAME STARTS!" << std::endl << std::endl;

    int innings, overs, curr_ball;
    int user_num_cricketers, ai_num_cricketers;
    int user_current_player, ai_current_player;
    int user_score, ai_score;
    bool player_batting_bool;
    char load_flag;
    Cricketer** user_cricketers_arr;
    Cricketer** ai_cricketers_arr;
    std::deque<int> smart_ai_mem;

    std::cout << "Do you want to load the game from the previous saved session? (y/n) ";
    std::cin >> load_flag;

    while(load_flag != 'y' && load_flag != 'n') {
        std::cout << "Please enter only y or n: ";
        std::cin >> load_flag;
    }
    std::cout << std::endl;
    
    // Calls the initialize_game() function from saving_and_loading.cpp to initialize the variables 
    initialize_game(load_flag, innings, overs, curr_ball, player_batting_bool, user_current_player, ai_current_player, user_score, ai_score, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr, smart_ai_mem);
    
    // Initializes other variables based on the ones initialized in the previous function
    int total_balls = overs * 6;
    int user_balls_before_switch = ceil(total_balls / user_num_cricketers); // Number of balls that can be thrown by a cricketer on the user's team
    int ai_balls_before_switch = ceil(total_balls / ai_num_cricketers); // Number of balls that can be thrown by a cricketer on the AI's team
    bool all_out = false;
    
    std::cout << std::endl;
    
    int ai_num, user_num;

    // Loops twice for each innings
    for(innings; innings <= 2; innings++) {
        if(innings == 1) {
            std::cout << "FIRST INNINGS" << std::endl;
        }
        if(innings == 2) {
            std::cout << "SECOND INNINGS" << std::endl;
        }

        if(player_batting_bool==true) {
            std::cout << std::endl << std::setw(PRETTY_PRINT_NUM) << std::setfill('-') << DUMMY_CHAR << " You Are Batting " << std::setw(PRETTY_PRINT_NUM) << std::setfill('-') << DUMMY_CHAR << std::endl << std::endl;
            // Loops until your entire team is out or the overs come to an end
            while((!all_out) && (curr_ball < total_balls)) {
                user_num = player();
                if(user_num == 0) save_and_quit_game(innings, overs, curr_ball, player_batting_bool, user_current_player, ai_current_player, user_score, ai_score, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr, smart_ai_mem);
                
                ai_num = comp(smart_ai_mem, curr_ball, player_batting_bool);
                update_smart_ai_mem(smart_ai_mem, user_num);

                if(user_num == ai_num) {
                    std::cout << "BATTER OUT!" << std::endl << std::endl;
                    ai_cricketers_arr[ai_current_player]->players_got_out += 1;
                    user_current_player += 1;
                } else {
                    user_score += user_num;
                    user_cricketers_arr[user_current_player]->score += user_num;
                }

                // Increments balls thrown for the AI's current cricketer
                ai_cricketers_arr[ai_current_player]->balls_thrown += 1;

                // Switches to the next AI cricketer if the current cricketer has thrown the max number of balls possible
                if(ai_cricketers_arr[ai_current_player]->balls_thrown == ai_balls_before_switch ) {
                    ai_current_player += 1; 
                }

                // Checks if the user team is out
                if(user_current_player == user_num_cricketers) {
                    all_out = true;
                }

                curr_ball++;
            }
        } else {
            std::cout << std::endl << std::setw(PRETTY_PRINT_NUM) << std::setfill('-') << DUMMY_CHAR << " You Are Bowling " << std::setw(PRETTY_PRINT_NUM) << std::setfill('-') << DUMMY_CHAR << std::endl << std::endl;
            // Loops until you get the entire enemy team out or the overs come to an end
            while((!all_out) && (curr_ball < total_balls)) { 
                user_num = player();
                if(user_num == 0) save_and_quit_game(innings, overs, curr_ball, player_batting_bool, user_current_player, ai_current_player, user_score, ai_score, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr, smart_ai_mem);
                
                ai_num = comp(smart_ai_mem, curr_ball, player_batting_bool);
                update_smart_ai_mem(smart_ai_mem, user_num);

                if(user_num == ai_num) {
                    std::cout << "BATTER OUT!" << std::endl << std::endl;
                    user_cricketers_arr[user_current_player]->players_got_out += 1;
                    ai_current_player += 1;
                } else {
                    ai_score += ai_num;
                    ai_cricketers_arr[ai_current_player]->score += ai_num;
                }

                // Increments balls thrown for the user's current cricketer
                user_cricketers_arr[user_current_player]->balls_thrown += 1;

                // Switches to the next user cricketer if the current cricketer has thrown the max number of balls possible
                if(user_cricketers_arr[user_current_player]->balls_thrown == user_balls_before_switch) {
                    user_current_player += 1;
                }

                // Checks if the AI team is out
                if(ai_current_player == ai_num_cricketers) {
                    all_out = true;
                }

                curr_ball++;
            }
        }

        if(curr_ball == total_balls) {
            std::cout << "Innings is over - the last Over has been completed" << std::endl << std::endl;
        } else {
            std::cout << "ALL PLAYERS OUT!" << std::endl << std::endl;
        }

        // Resets the variables and switches sides
        switch_teams(player_batting_bool);
        all_out = false;
        user_current_player = 0;
        ai_current_player = 0;
        curr_ball = 0;
        for(int i = 0; i < SMART_AI_STORAGE_SIZE; i++) {
            int reset_val = 0;
            update_smart_ai_mem(smart_ai_mem, reset_val);
        }
    }

    // Prints out the results and player statistics
    results(user_score, ai_score, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr);

    // Deletes the dynamic structs inside the arrays and then the dynamic arrays itself
    delete_cricketer_array(user_cricketers_arr, user_num_cricketers);
    delete_cricketer_array(ai_cricketers_arr, ai_num_cricketers);
}
