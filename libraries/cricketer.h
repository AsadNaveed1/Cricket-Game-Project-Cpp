#ifndef CRICKETER_H
#define CRICKETER_H

// A struct which has the points scored, the number of players got out and the number of balls thrown for a cricketer on a team
struct Cricketer {
    int score;
    int players_got_out;
    int balls_thrown;
    Cricketer();
    Cricketer(int, int, int);
};

void delete_cricketer_array(Cricketer**&, int);

#endif