#include <iostream>

#include "./constants.h"
#include "./ai.h"

// This function stores inputs the user's last move and removes the user's move from 4 turns ago to ensure that the deque only holds the user's last 3 moves 
void update_smart_ai_mem(std::deque<int> &smart_ai_mem, int &user_num) {
    smart_ai_mem.pop_back();
    smart_ai_mem.push_front(user_num);
}

// This function randomly chooses between the average of the user's last 3 moves stored in the deque and a random number generator which generates numbers from 1 - 6
// The random number generator is picked 70% of the time while the average is picked 30% of the time
int smart_bowling_choice(int &avg) {
    int chooser = rand() % 10 + 1;
    if(chooser >= 1 && chooser <= 3) return avg;
    else return rand() % 6 + 1;

}

// This function randomly chooses between anything from 1 - 6 but the average of the user's last 3 moves stored in the deque and a random number generator which generates numbers from 1 - 6
// The random number generator is picked 70% of the time while the anything from 1 - 6 but the average is picked 30% of the time
int smart_batting_choice(int &avg) {
    int chooser = rand() % 10 + 1;
    if(chooser >= 1 && chooser <= 3) {
        int res = rand() % 6 + 1;
        while(res == avg) res = rand() % 6 + 1;
        return res;
    }
    else return rand() % 6 + 1;
}