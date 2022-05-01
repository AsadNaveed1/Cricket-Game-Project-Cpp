#ifndef SAVING_AND_LOADING_H
#define SAVING_AND_LOADING_H

#include <deque>

struct Cricketer;

void save_and_quit_game(int&, int&, int&, bool&, int&, int&, int&, int&, int&, int&, Cricketer**&, Cricketer**&, std::deque<int>&);
void initialize_game(char, int&, int&, int&, bool&, int&, int&, int&, int&, int&, int&, Cricketer**&, Cricketer**&, std::deque<int>&);

#endif