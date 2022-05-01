#ifndef GAME_H
#define GAME_H

struct Cricketer;

void main_menu();
void instructions();
void game_name();
void results(int&, int&, int&, int&, Cricketer**&, Cricketer**&);
void start_game();

#endif