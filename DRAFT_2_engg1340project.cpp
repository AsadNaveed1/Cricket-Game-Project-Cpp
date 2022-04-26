#include <iostream>
#include <time.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

const int NUM_INNINGS = 2;
const int PRETTY_PRINT_NUM = 30;
const char save_file_name[] = "cricket_save_file.txt";

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
    cout << "1. You have to choose which format you want to play."<<endl;
    cout << "2. If you win the toss, you have to choose whether you want to bat or bowl."<<endl;
    cout << "3. You have to choose a number between 1 and 6 when it's your turn."<<endl;
    cout << "4. If your decision and your opponents decision are same, then the player who is batting is out."<<endl;
    cout << "5. One who scores more during their batting is declared as WINNER."<<endl;
    cout << "6. If both scores same, then the result will be a draw."<<endl;    
}

void toss(bool &player_batting_bool) {    
    int coin_side_chosen, coin_side_landed;

    cout << "\n\nWELCOME TO TOSS!\n";
   
    cout << "\n Player 1 Choose your call:\n Please enter '1' for Heads and '2' for Tails ";
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
    int res;
    cout << "\nPlayer 1 Choose a number between 1 and 6: ";
    while(1) {
        cin >> res;
        if(res>6||res<1) {   
            cout << "Please select a number between 1 and 6: ";
            continue;
        } else {
            break;
        } 
    }
    return res;
}
int player2() {  
    int res;
    
    cout << "\nPlayer 2 Choose a number between 1 and 6: ";
    while(1) {
        cin >> res;
        if(res>6||res<1) {
            cout << "Please select a number between 1 and 6: ";
            continue;
        } else {
            break;
        }    
    }
    return res;
}

int comp() { 
    int res;

    cout << "\nPlayer 1 input a number to deliver a ball: ";

    cin>>res;

    res = rand()%6+1;
    
    cout << "\nThe ball delivered by Player 1 is: " << res << endl;
    return res;
}

int comp2() { 
    int res;

    cout << "\nPlayer 2 input a number to ball: ";

    cin>>res;

    res = rand()%6+1;
    
    cout << "\nThe ball delivered by Player 2 is: " << res << endl;
    return res;
}

void save_and_quit_game(int &innings, int &overs, int &curr_ball, bool &player_batting_bool, int &user_num_cricketers, int &ai_num_cricketers, Cricketer** &user_cricketers_arr, Cricketer** &ai_cricketers_arr) {
    ofstream fout;
    fout.open(save_file_name);

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
    
    fout.close();
    delete_cricketer_array(user_cricketers_arr, user_num_cricketers);
    delete_cricketer_array(ai_cricketers_arr, ai_num_cricketers);
    exit(0);
}

// TODO: Handle case when file does not exist (load chosen before any save) or when file is empty
void initialize_game(char load_flag, int &innings, int &overs, int &curr_ball, bool &player_batting_bool, int &user_num_cricketers, int &ai_num_cricketers, Cricketer** &user_cricketers_arr, Cricketer** &ai_cricketers_arr) {
    if(load_flag == 'n') {
        innings = 1;
        curr_ball = 0;
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
    } else {
        ifstream fin;
        fin.open(save_file_name);
        
        if(fin.fail()) {
            cout << "Error in file opening!" << endl;
            exit(1);
        }

        // Load game data from file
        fin >> user_num_cricketers;
        fin >> ai_num_cricketers;

        user_cricketers_arr = new Cricketer*[user_num_cricketers];
        ai_cricketers_arr = new Cricketer*[ai_num_cricketers];

        for(int i = 0; i < user_num_cricketers; i++) {
            string cricketer_vals;
            fin >> cricketer_vals;
            istringstream ss(cricketer_vals);
            int vals_arr[] = {0, 0, 0};
            for(int i = 0; i < 3; i++) {
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
            for(int i = 0; i < 3; i++) {
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
    }
}

void start_game() {
    game_name();
    srand(time(0));
    
    cout << "\n\n\n";
    
    cout << "GAME STARTS!!!" << endl;

    int innings, overs, curr_ball;
    bool player_batting_bool;
    Cricketer** user_cricketers_arr;
    Cricketer** ai_cricketers_arr;
    int user_num_cricketers;
    int ai_num_cricketers;
    
    char load_flag;
    cout << "Do you want to load the game from the previous saved session? y/n" << endl;
    cin >> load_flag;

    while(load_flag != 'y' && load_flag != 'n') {
        cout << "Please enter only y or n" << endl;
        cin >> load_flag;
    }
    
    int t1, t2;
    int player_score=0, player2_score=0,  first=0, second=0;
    string bat="player";
    string bowl="player2";

    initialize_game(load_flag, innings, overs, curr_ball, player_batting_bool, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr);
    // save_and_quit_game(innings, overs, curr_ball, player_batting_bool, user_num_cricketers, ai_num_cricketers, user_cricketers_arr, ai_cricketers_arr);

    int balls = overs * 6;

    bool out = false;
    
    cout << "\n\n";
   
    cout << "FIRST INNINGS";
    
    if(bat=="player")  {
        cout << "\n\n---------------------------------Player 1 is Batting---------------------------------\n";
        while((!out) && (curr_ball < balls)) {   //First Innings
            t1=player();
            t2=comp2();
            if(t1==t2)  {
                out = true;
                cout << "\nIt's OUT!!!\n";
            } else {
                player_score += t1;
            }
            curr_ball++;
        }
    } else {
        cout << "\n\n---------------------------------Player 2 is Batting---------------------------------\n";
        while((!out)&&(curr_ball<balls)) {   //First Innings
            t1=player2();
            t2=comp();
            if(t1==t2) {
                out = true;
                cout << "\nIt's OUT!!!\n";
            } else {
                player2_score += t1;
            }
            curr_ball++;
        }
    } 

    //Before second innings need to change bat and bal
    if(bat=="player") {
        bat = "player2";
        bowl = "player";
        first = player_score;
        
        cout << "\nFirst Innings Ended!!\n";
       
        cout<<"\nPlayer 1 Score is "<< first <<endl;
   
        cout << "\n\n";
       
        cout << "SECOND INNINGS";
        
        cout << "\n\n---------------------------------Player 2 is Batting Now!!---------------------------------\n";
    } else {
        bowl = "player2";
        bat = "player";
        first = player2_score;
        
        cout << "\nFirst Innings Ended!!\n";
       
        cout<<"\nPlayer 2 Score is "<< first <<endl;
   
        cout << "\n\n";
       
        cout << "SECOND INNINGS";
        
        cout << "\n\n---------------------------------Player 1 is Batting Now!!---------------------------------\n";
    }

    out = false;
    curr_ball=0;

    if(bat=="player") {
        while((!out)&&(curr_ball<balls)&&(second<=first)) {   //Second Innings
            t1=player();
            t2=comp2();
            if(t1==t2) {
                out = true;
                cout << "\nIt's OUT!!!\n";
            } else {
                player_score += t1;
                second+=t1;
            }
            curr_ball++;
        }
    } else {
        while((!out)&&(curr_ball<balls)&&(second<=first)) {   //Second Innings
            t1=player2();
            t2=comp();
            if(t1 == t2) {
                out = true;
                cout << "\nIt's OUT!!!\n";
            } else {
                player2_score += t1;
                second+=t1;
            }
            curr_ball++;
        }
    }

    if(bat=="player") {
        cout << "\nSecond Innings Ended!!\n";
       
        cout <<"\nPlayer 1 Score is "<< second <<endl;
        
        cout <<"=============================================================================================================";
   
        cout << "\n\n";
       
        cout << "RESULT";
        if(first>second)  {
            cout << "\n\n    Player 2 WON!!";
        } else if(first == second)  {
            cout << "\n\nMatch Draw!!";
        } else {
            cout << "\n\n    Player 1 Won!!";
        }
    } else {
        cout << "\nSecond Innings Ended!!\n\n";
       
        cout <<"Player 2 Score is "<< second <<endl;
        
        cout <<"=============================================================================================================";
   
        cout << "\n\n";
       
        cout << "RESULT";

        if(first>second) {
            cout << "\n\n    Player 1 Won!!";
        } else if(first == second)  {
            cout << "\n\nMatch Draw!!";
        } else {
            cout << "\n\n    Player 2 Won!!";
        }
    }
    
    cout <<"\n\n=============================================================================================================";

    delete_cricketer_array(user_cricketers_arr, user_num_cricketers);
    delete_cricketer_array(ai_cricketers_arr, ai_num_cricketers);
}

int main() {
    while(1) {
        game_name();
        main_menu();
        char main_menu_choice, return_to_menu;
        cin >> main_menu_choice;
        if(main_menu_choice == '1') {
            start_game();
            cout << "Press any key to return to main menu...";
            cin >> return_to_menu;
        } else if(main_menu_choice == '2') {
            instructions();
            cout << "Press any key to return to main menu...";
            cin >> return_to_menu;
        } else {
            break;
        }    
    }
    return 0;
}