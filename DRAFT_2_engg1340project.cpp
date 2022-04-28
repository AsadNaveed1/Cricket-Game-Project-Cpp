#include <iostream>
#include <time.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cmath>
#include <filesystem>
#include <deque>

using namespace std;

const int NUM_INNINGS = 2;
const int SMART_AI_STORAGE_SIZE = 3;
const int PRETTY_PRINT_NUM = 30;
const char SAVE_FILE_NAME[] = "cricket_save_file.txt";

const int CRICKETER_VALS = 3;
struct Cricketer {
    int score;
    int players_got_out;
    int balls_thrown;

    Cricketer() {
        score = 0;
        players_got_out = 0;
        balls_thrown = 0; 
    }

    Cricketer(int score_, int players_got_out_, int balls_thrown_) {
        score = score_;
        players_got_out = players_got_out_;
        balls_thrown = balls_thrown_;
    }
};

void delete_cricketer_array(Cricketer** &cricketer_array, int size) {
    for(int i = 0; i < size; i++) {
        delete cricketer_array[i];
    }
    delete [] cricketer_array;
}

void game_name(){
    
    cout << endl;
    cout << "|-----------------------------------------------------------|\n" << endl;
    cout << " ██████╗██████╗ ██╗ ██████╗██╗  ██╗███████╗████████╗"<<endl;
    cout << "██╔════╝██╔══██╗██║██╔════╝██║ ██╔╝██╔════╝╚══██╔══╝"<<endl;
    cout << "██║     ██████╔╝██║██║     █████╔╝ █████╗     ██║   "<<endl;
    cout << "██║     ██╔══██╗██║██║     ██╔═██╗ ██╔══╝     ██║   "<<endl;
    cout << "╚██████╗██║  ██║██║╚██████╗██║  ██╗███████╗   ██║   "<<endl;
    cout << " ╚═════╝╚═╝  ╚═╝╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝   ╚═╝   "<<endl;
    cout << endl;
    cout << "|----------------------------------------------------------|\n" << endl;
}

void main_menu() {
    cout << "\n\nMAIN MENU :-";
    cout << "\n\n1. Start a new game" << endl;
    cout << "\n2. Instructions" << endl;
    cout << "\nPress any other key to end the program" << endl;
    cout << "\nEnter your decision: ";
    
}
void instructions() {
    cout << endl;
    cout << "INSTRUCTIONS AND RULES";
    cout << endl;
    cout << "1. You have to choose which format you want to play." << endl;
    cout << "2. If you win the toss, you have to choose whether you want to bat or bowl." << endl;
    cout << "3. You have to choose a number between 1 and 6 when it's your turn." << endl;
    cout << "4. If your decision and your opponents decision are same, then the player who is batting is out." << endl;
    cout << "5. One who scores more during their batting is declared as WINNER." << endl;
    cout << "6. If both scores same, then the result will be a draw.\n" << endl;    
}

void toss(bool &player_batting_bool) {    
    int coin_side_chosen, coin_side_landed;

    cout << "\n\nWELCOME TO TOSS!\n";
   
    cout << "\n Player 1 Choose your call:\nPlease enter '1' for Heads and '2' for Tails ";
    cin >> coin_side_chosen;
    coin_side_landed = rand() % 2 + 1;
    bool toss_result;
    int side_choice;

    if(coin_side_landed == coin_side_chosen) {
        cout << "\n\n******************** You've won the Toss ********************" << endl;
        cout << "\nSelect your side:\n Please enter '1' for batting and '2' for bowling\n";
        cin >> side_choice;
    } else {
        cout << "\n\n******************** You've lost the Toss ********************" << endl;
        side_choice = rand() % 2 + 1;
    }

    if(side_choice == 1) {
        player_batting_bool = true;
    } else if(side_choice = 2) {
        player_batting_bool = false;
    } else {
        cout << "Please only enter '1' or '2' to select your choice";
    }
}

int player() {   
    char move;
    cout << "\nPlayer 1: Choose a number between 1 and 6, or choose q to save and quit: ";
    cin >> move;
    while((move > '6' || move < '1') && (move != 'q')) {
        cout << "Please only choose a number between 1 and 6 or the letter q: ";
        cin >> move;
    }
    return move;
}

void update_smart_ai_mem(deque<int> &smart_ai_mem, int &user_num) {
    smart_ai_mem.pop_back();
    smart_ai_mem.push_front(user_num);
}

int smart_bowling_choice(int &avg) {
    int chooser = rand() % 10 + 1;
    if(chooser >= 1 && chooser <= 3) return avg;
    else return rand() % 6 + 1;

}

int smart_batting_choice(int &avg) {
    int chooser = rand() % 10 + 1;
    if(chooser >= 1 && chooser <= 3) {
        int res = rand() % 6 + 1;
        while(res == avg) res = rand() % 6 + 1;
        return res;
    }
    else return rand() % 6 + 1;
}

int comp(deque<int> &smart_ai_mem, int &curr_ball, bool &player_batting_bool) {
    if(curr_ball == 0) {
        int move = rand() % 6 + 1;
        cout << "\nThe number delivered by the opponent is: " << move << endl;
        return move;
    }

    int sum = 0;
    deque<int>::iterator itr;
    for(itr = smart_ai_mem.begin(); itr != smart_ai_mem.end(); itr++) {
        sum += *itr;
    }

    int avg;
    if(curr_ball < SMART_AI_STORAGE_SIZE) avg = sum / curr_ball;
    else avg = sum / SMART_AI_STORAGE_SIZE;

    int move;
    if(player_batting_bool) move = smart_bowling_choice(avg);
    else move = smart_batting_choice(avg);

    cout << "\nThe number delivered by the opponent is: " << move << endl;
    return move;
}

void switch_teams(bool &player_batting_bool) {
    if (player_batting_bool == true) {
        player_batting_bool = false;
    } else {
        player_batting_bool = true;
    }
}

void results(int &user_score, int &ai_score, int &user_num_cricketers, int &ai_num_cricketers, Cricketer** &user_cricketers_arr, Cricketer** &ai_cricketers_arr) {
    int user_best_batter_index = 0, ai_best_batter_index = 0, user_best_bowler_index = 0, ai_best_bowler_index = 0;
    int user_best_batter_score = 0, ai_best_batter_score = 0, user_best_bowler_score = 0, ai_best_bowler_score = 0;
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

    cout << "User Player Statistics" << endl;
    cout << "The best batter on your team scored " << user_best_batter_score << " points for you!" << endl;
    cout << "The best bowler on your team threw " << user_cricketers_arr[user_best_bowler_index]->balls_thrown  << " balls and got " << user_best_bowler_score << " players out!" << endl;
    cout << endl;
    cout << "AI Player Statistics" << endl;
    cout << "The best batter on your opponent's team scored " << ai_best_batter_score << " points for the AI!" << endl;
    cout << "The best bowler on your opponent's team threw " << ai_cricketers_arr[ai_best_bowler_index]->balls_thrown << " balls and got " << ai_best_bowler_score << " players out!" << endl;
    cout << endl;
    cout << "Your team score was " << user_score << endl;
    cout << "Your opponent's team score was " << ai_score << endl;
    if(user_score > ai_score) {
        cout << "CONGRATULATIONS, YOU HAVE WON!!!" << endl;
    } else if(user_score < ai_score) {
        cout << "You have Lost... Better luck next time..." << endl;
    } else {
        cout << "It's a Draw? Hmm... That's rare" << endl;
    }
}

void save_and_quit_game(int &innings, int &overs, int &curr_ball, bool &player_batting_bool, int &user_current_player, int &ai_current_player, int &user_score, int &ai_score, int &user_num_cricketers, int &ai_num_cricketers, Cricketer** &user_cricketers_arr, Cricketer** &ai_cricketers_arr, deque<int> &smart_ai_mem) {
    ofstream fout;
    fout.open(SAVE_FILE_NAME);

    if(fout.fail()) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    // Save output to file
    fout << user_num_cricketers << endl;
    fout << ai_num_cricketers << endl;

    for(int i = 0; i < user_num_cricketers; i++) {
        fout << user_cricketers_arr[i]->score << ',' << user_cricketers_arr[i]->players_got_out << ',' << user_cricketers_arr[i]->balls_thrown << endl;
    }

    for(int i = 0; i < ai_num_cricketers; i++) {
        fout << ai_cricketers_arr[i]->score << ',' << ai_cricketers_arr[i]->players_got_out << ',' << ai_cricketers_arr[i]->balls_thrown << endl;
    }

    fout << innings << endl;
    fout << overs << endl;
    fout << curr_ball << endl;
    fout << player_batting_bool << endl;
    fout << user_current_player << endl;
    fout << ai_current_player << endl;
    fout << user_score << endl;
    fout << ai_score << endl;

    deque<int>::iterator itr;
    for(itr = smart_ai_mem.begin(); itr != smart_ai_mem.end(); itr++) {
        if(itr == --smart_ai_mem.end()) fout << *itr;
        else fout << *itr << ',';
    }
    
    fout.close();
    delete_cricketer_array(user_cricketers_arr, user_num_cricketers);
    delete_cricketer_array(ai_cricketers_arr, ai_num_cricketers);
    exit(0);
}

void initialize_game(char load_flag, int &innings, int &overs, int &curr_ball, bool &player_batting_bool, int &user_current_player, int &ai_current_player, int &user_score, int &ai_score, int &user_num_cricketers, int &ai_num_cricketers, Cricketer** &user_cricketers_arr, Cricketer** &ai_cricketers_arr, deque<int> &smart_ai_mem) {
    if(load_flag == 'n') {
        innings = 1;
        curr_ball = 0;
        user_current_player = 0;
        ai_current_player = 0;
        user_score = 0;
        ai_score = 0;
        toss(player_batting_bool);

        cout << "\nHow many Overs match would you like to have?" << endl;
        cin >> overs;

        cout << "How many cricketers would you like on your team? ";
        cin >> user_num_cricketers;
        
        cout << "How many cricketers would you like on the opponent's team? ";
        cin >> ai_num_cricketers;

        user_cricketers_arr = new Cricketer*[user_num_cricketers];
        ai_cricketers_arr = new Cricketer*[ai_num_cricketers];

        for(int i = 0; i < user_num_cricketers; i++) {
            user_cricketers_arr[i] = new Cricketer(0, 0, 0);
        }

        for(int i = 0; i < ai_num_cricketers; i++) {
            ai_cricketers_arr[i] = new Cricketer(0, 0, 0);
        }

        for(int i = 0; i < SMART_AI_STORAGE_SIZE; i++) {
            smart_ai_mem.push_front(0);
        }
    } else { // Load game data from file
        ifstream fin;
        fin.open(SAVE_FILE_NAME);
        
        if(!fin) {
            cout << "\nSave file does not exist. Please save a game before attempting to load one." << endl;
            
            char new_game_decision;
            cout << "Would you like to proceed with a new game? (y/n) ";
            cin >> new_game_decision;
            while(new_game_decision != 'y' && new_game_decision != 'n') {
                cout << "Please enter only y or n" << endl;
                cin >> new_game_decision;
            }
            
            if(new_game_decision == 'y') {
                initialize_game('n', innings, overs, curr_ball, player_batting_bool, user_current_player, ai_current_player, user_score, ai_score, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr, smart_ai_mem);
                return;
            } else {
                exit(0);
            }
        } else if(fin.fail()) {
            cout << "Error in file opening!" << endl;
            exit(1);
        }

        fin >> user_num_cricketers;
        fin >> ai_num_cricketers;

        user_cricketers_arr = new Cricketer*[user_num_cricketers];
        ai_cricketers_arr = new Cricketer*[ai_num_cricketers];

        for(int i = 0; i < user_num_cricketers; i++) {
            string cricketer_vals;
            fin >> cricketer_vals;
            istringstream ss(cricketer_vals);
            int vals_arr[] = {0, 0, 0};
            for(int i = 0; i < CRICKETER_VALS; i++) {
                string token;
                getline(ss, token, ',');
                vals_arr[i] = stoi(token);
            }
            user_cricketers_arr[i] = new Cricketer(vals_arr[0], vals_arr[1], vals_arr[2]);
        }

        for(int i = 0; i < ai_num_cricketers; i++) {
            string cricketer_vals;
            fin >> cricketer_vals;
            istringstream ss(cricketer_vals);
            int vals_arr[] = {0, 0, 0};
            for(int i = 0; i < CRICKETER_VALS; i++) {
                string token;
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

        string smart_ai_stored;
        fin >> smart_ai_stored;
        istringstream ss(smart_ai_stored);
        for(int i = 0; i < SMART_AI_STORAGE_SIZE; i++) {
            string token;
            getline(ss, token, ',');
            smart_ai_mem.push_front(stoi(token));
        }

        fin.close();
    }
}

void start_game() {
    game_name();
    srand(time(0));
    
    cout << "\n\n\n";
    
    cout << "GAME STARTS!!!" << endl;

    int innings, overs, curr_ball;
    int user_num_cricketers, ai_num_cricketers;
    int user_current_player, ai_current_player;
    int user_score, ai_score;
    bool player_batting_bool;
    char load_flag;
    Cricketer** user_cricketers_arr;
    Cricketer** ai_cricketers_arr;
    deque<int> smart_ai_mem;

    cout << "Do you want to load the game from the previous saved session? (y/n) ";
    cin >> load_flag;

    while(load_flag != 'y' && load_flag != 'n') {
        cout << "Please enter only y or n" << endl;
        cin >> load_flag;
    }
    
    initialize_game(load_flag, innings, overs, curr_ball, player_batting_bool, user_current_player, ai_current_player, user_score, ai_score, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr, smart_ai_mem);
    
    int total_balls = overs * 6;
    int user_balls_before_switch = ceil(total_balls / user_num_cricketers);
    int ai_balls_before_switch = ceil(total_balls / ai_num_cricketers);
    bool all_out = false;
    
    cout << "\n\n";
    
    int ai_num, user_num;
    char user_num_char;
    for(innings; innings <= 2; innings++) {
        if(innings == 1) {
            cout << "FIRST INNINGS";
        }
        if(innings == 2) {
            cout << "SECOND INNINGS";
        }

        if(player_batting_bool==true) {
            cout << "\n\n---------------------------------You Are Batting---------------------------------\n";
            while((!all_out) && (curr_ball < total_balls)) {
                user_num_char = player();
                if(user_num_char == 'q') save_and_quit_game(innings, overs, curr_ball, player_batting_bool, user_current_player, ai_current_player, user_score, ai_score, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr, smart_ai_mem);
                user_num = user_num_char - '0';
                ai_num = comp(smart_ai_mem, curr_ball, player_batting_bool);
                update_smart_ai_mem(smart_ai_mem, user_num);
                if(user_num == ai_num) {
                    cout << "\nIt's OUT!!!\n" << endl;
                    ai_cricketers_arr[ai_current_player]->players_got_out += 1;
                    user_current_player += 1;
                } else {
                    user_score += user_num;
                    user_cricketers_arr[user_current_player]->score += user_num;
                }
                ai_cricketers_arr[ai_current_player]->balls_thrown += 1;

                if(ai_cricketers_arr[ai_current_player]->balls_thrown == ai_balls_before_switch ) {
                    ai_current_player += 1;
                }
                // Checks if team is out
                if(user_current_player == user_num_cricketers) {
                    all_out = true;
                }

                curr_ball++;
            }
        } else {
            cout << "\n\n---------------------------------You Are Bowling---------------------------------\n";
            while((!all_out) && (curr_ball < total_balls)) { 
                user_num_char = player();
                if(user_num_char == 'q') save_and_quit_game(innings, overs, curr_ball, player_batting_bool, user_current_player, ai_current_player, user_score, ai_score, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr, smart_ai_mem);
                user_num = user_num_char - '0';
                ai_num = comp(smart_ai_mem, curr_ball, player_batting_bool);
                update_smart_ai_mem(smart_ai_mem, user_num);
                if(user_num == ai_num) {
                    cout << "\nIt's OUT!!!\n" << endl;
                    user_cricketers_arr[user_current_player]->players_got_out += 1;
                    ai_current_player += 1;
                } else {
                    ai_score += ai_num;
                    ai_cricketers_arr[ai_current_player]->score += ai_num;
                }
                user_cricketers_arr[user_current_player]->balls_thrown += 1;
                if(user_cricketers_arr[user_current_player]->balls_thrown == user_balls_before_switch) {
                    user_current_player += 1;
                }
                if(ai_current_player == ai_num_cricketers) {
                    all_out = true;
                }
                curr_ball++;
            }
        }

        if(curr_ball == total_balls) {
            cout << "\nInnings is over - last Over has been completed\n" << endl;
        } else {
            cout << "\nALL PLAYERS OUT!!!\n" << endl;
        }

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

    results(user_score, ai_score, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr);

    delete_cricketer_array(user_cricketers_arr, user_num_cricketers);
    delete_cricketer_array(ai_cricketers_arr, ai_num_cricketers);
}

int main() {
    game_name();
    while(1) {
        main_menu();
        char main_menu_choice;
        string return_to_menu;
        cin >> main_menu_choice;
        getline(cin, return_to_menu);
        if(main_menu_choice == '1') {
            start_game();
            cout << "Press enter to return to main menu...";
            getline(cin, return_to_menu);
        } else if(main_menu_choice == '2') {
            instructions();
            cout << "Press enter to return to main menu...";
            getline(cin, return_to_menu);
        } else {
            break;
        }
    }
    cout << endl;
    return 0;
}