#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "./constants.h"
#include "./cricketer.h"
#include "./ai.h"
#include "./game_mechanics.h"

// This function saves the current game state, which includes all the current variable values and the data types to the save file
void save_and_quit_game(int &innings, int &overs, int &curr_ball, bool &player_batting_bool, int &user_current_player, int &ai_current_player, int &user_score, int &ai_score, int &user_num_cricketers, int &ai_num_cricketers, Cricketer** &user_cricketers_arr, Cricketer** &ai_cricketers_arr, std::deque<int> &smart_ai_mem) {
    std::ofstream fout;
    fout.open(SAVE_FILE_NAME);

    if(fout.fail()) {
        std::cout << "Error in file opening!" << std::endl;
        exit(1);
    }

    // Save output to the save file
    fout << user_num_cricketers << std::endl;
    fout << ai_num_cricketers << std::endl;

    // Loops for saving all the elements in the dynamic arrays to the save file
    for(int i = 0; i < user_num_cricketers; i++) {
        fout << user_cricketers_arr[i]->score << ',' << user_cricketers_arr[i]->players_got_out << ',' << user_cricketers_arr[i]->balls_thrown << std::endl;
    }

    for(int i = 0; i < ai_num_cricketers; i++) {
        fout << ai_cricketers_arr[i]->score << ',' << ai_cricketers_arr[i]->players_got_out << ',' << ai_cricketers_arr[i]->balls_thrown << std::endl;
    }

    fout << innings << std::endl;
    fout << overs << std::endl;
    fout << curr_ball << std::endl;
    fout << player_batting_bool << std::endl;
    fout << user_current_player << std::endl;
    fout << ai_current_player << std::endl;
    fout << user_score << std::endl;
    fout << ai_score << std::endl;

    // Loop through the deque to store the values in the save file
    std::deque<int>::iterator itr;
    for(itr = smart_ai_mem.begin(); itr != smart_ai_mem.end(); itr++) {
        if(itr == --smart_ai_mem.end()) fout << *itr;
        else fout << *itr << ',';
    }
    
    fout.close();
    // Deleting the dynamic arrays and structs by calling the delete_cricketer_array() funciton
    delete_cricketer_array(user_cricketers_arr, user_num_cricketers);
    delete_cricketer_array(ai_cricketers_arr, ai_num_cricketers);
    // Closing the game
    exit(0);
}

// Initializes the variables required by the game. The variables are initialized from the save file if the user wants a previous game to be loaded, otherwise it is initialized with default values
void initialize_game(char load_flag, int &innings, int &overs, int &curr_ball, bool &player_batting_bool, int &user_current_player, int &ai_current_player, int &user_score, int &ai_score, int &user_num_cricketers, int &ai_num_cricketers, Cricketer** &user_cricketers_arr, Cricketer** &ai_cricketers_arr, std::deque<int> &smart_ai_mem) {
    // Loading the game by initializing variables with default values
    if(load_flag == 'n') {
        innings = 1;
        curr_ball = 0;
        user_current_player = 0;
        ai_current_player = 0;
        user_score = 0;
        ai_score = 0;
        toss(player_batting_bool);

        std::cout << "How many Overs match would you like to have? ";
        std::cin >> overs;

        std::cout << "How many cricketers would you like on your team? ";
        std::cin >> user_num_cricketers;
        
        std::cout << "How many cricketers would you like on the opponent's team? ";
        std::cin >> ai_num_cricketers;

        user_cricketers_arr = new Cricketer*[user_num_cricketers];
        ai_cricketers_arr = new Cricketer*[ai_num_cricketers];
        // Loops through the dynamic arrays and intialize the structs inside with default values
        for(int i = 0; i < user_num_cricketers; i++) {
            user_cricketers_arr[i] = new Cricketer(0, 0, 0);
        }

        for(int i = 0; i < ai_num_cricketers; i++) {
            ai_cricketers_arr[i] = new Cricketer(0, 0, 0);
        }

        // Initialize the deque with default values 
        for(int i = 0; i < SMART_AI_STORAGE_SIZE; i++) {
            smart_ai_mem.push_front(0);
        }
    } else { // Load game data from the save file
        std::ifstream fin;
        fin.open(SAVE_FILE_NAME);
        
        if(!fin) {
            std::cout << "Save file does not exist. Please save a game before attempting to load one." << std::endl;
            
            char new_game_decision;
            std::cout << "Would you like to proceed with a new game? (y/n) ";
            std::cin >> new_game_decision;
            while(new_game_decision != 'y' && new_game_decision != 'n') {
                std::cout << "Please enter only y or n" << std::endl;
                std::cin >> new_game_decision;
            }
            
            if(new_game_decision == 'y') {
                initialize_game('n', innings, overs, curr_ball, player_batting_bool, user_current_player, ai_current_player, user_score, ai_score, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr, smart_ai_mem);
                return;
            } else {
                exit(0);
            }
        } else if(fin.fail()) {
            std::cout << "Error in file opening!" << std::endl;
            exit(1);
        }

        fin >> user_num_cricketers;
        fin >> ai_num_cricketers;

        user_cricketers_arr = new Cricketer*[user_num_cricketers];
        ai_cricketers_arr = new Cricketer*[ai_num_cricketers];

        // Loops through the dynamic arrays and initializes them with values from the save file
        for(int i = 0; i < user_num_cricketers; i++) {
            std::string cricketer_vals;
            fin >> cricketer_vals;
            std::istringstream ss(cricketer_vals);
            int vals_arr[] = {0, 0, 0};
            for(int i = 0; i < CRICKETER_VALS; i++) {
                std::string token;
                getline(ss, token, ',');
                vals_arr[i] = stoi(token);
            }
            user_cricketers_arr[i] = new Cricketer(vals_arr[0], vals_arr[1], vals_arr[2]);
        }

        for(int i = 0; i < ai_num_cricketers; i++) {
            std::string cricketer_vals;
            fin >> cricketer_vals;
            std::istringstream ss(cricketer_vals);
            int vals_arr[] = {0, 0, 0};
            for(int i = 0; i < CRICKETER_VALS; i++) {
                std::string token;
                getline(ss, token, ',');
                vals_arr[i] = stoi(token);
            }
            ai_cricketers_arr[i] = new Cricketer(vals_arr[0], vals_arr[1], vals_arr[2]);
        }

        fin >> innings;
        fin >> overs;
        fin >> curr_ball;
        fin >> player_batting_bool;
        fin >> user_current_player;
        fin >> ai_current_player;
        fin >> user_score;
        fin >> ai_score;

        // Initializes the deque with values from the save file
        std::string smart_ai_stored;
        fin >> smart_ai_stored;
        std::istringstream ss(smart_ai_stored);
        for(int i = 0; i < SMART_AI_STORAGE_SIZE; i++) {
            std::string token;
            getline(ss, token, ',');
            smart_ai_mem.push_front(stoi(token));
        }

        fin.close();
    }
}