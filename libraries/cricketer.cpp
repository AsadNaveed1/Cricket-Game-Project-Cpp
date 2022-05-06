#include "./cricketer.h"

// Default empty constructor; does nothing
Cricketer::Cricketer() {
    score = 0;
    players_got_out = 0;
    balls_thrown = 0;
}

// Parameterized constructor to allow for easy input into the struct
Cricketer::Cricketer(int score_, int players_got_out_, int balls_thrown_) {
    score = score_;
    players_got_out = players_got_out_;
    balls_thrown = balls_thrown_;
}

// This function deletes every dynamic struct inside the array and then deletes the array itself
// It takes the Cricketer array and the size of the array as input and has no return value as it directly deletes the values inside the array and then the array itself
void delete_cricketer_array(Cricketer** &cricketer_array, int size) {
    for(int i = 0; i < size; i++) {
        delete cricketer_array[i];
    }
    delete [] cricketer_array;
}