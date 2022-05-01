SRC=.
SRC_LIB=./libraries
GCC = g++
FLAGS = -pedantic-errors -std=c++11
RM = rm -rf

constants.o: $(SRC_LIB)/constants.cpp $(SRC_LIB)/constants.h
	$(GCC) $(FLAGS) -c $<

ai.o: $(SRC_LIB)/ai.cpp $(SRC_LIB)/ai.h $(SRC_LIB)/constants.h
	$(GCC) $(FLAGS) -c $<

cricketer.o: $(SRC_LIB)/cricketer.cpp $(SRC_LIB)/cricketer.h
	$(GCC) $(FLAGS) -c $<

game_mechanics.o: $(SRC_LIB)/game_mechanics.cpp $(SRC_LIB)/game_mechanics.h
	$(GCC) $(FLAGS) -c $<

players_and_bots.o: $(SRC_LIB)/players_and_bots.cpp $(SRC_LIB)/players_and_bots.h $(SRC_LIB)/constants.h $(SRC_LIB)/ai.h
	$(GCC) $(FLAGS) -c $<

saving_and_loading.o: $(SRC_LIB)/saving_and_loading.cpp $(SRC_LIB)/saving_and_loading.h $(SRC_LIB)/cricketer.h $(SRC_LIB)/constants.h $(SRC_LIB)/ai.h $(SRC_LIB)/game_mechanics.h
	$(GCC) $(FLAGS) -c $<

game.o: $(SRC_LIB)/game.cpp $(SRC_LIB)/game.h $(SRC_LIB)/constants.h $(SRC_LIB)/saving_and_loading.h $(SRC_LIB)/ai.h $(SRC_LIB)/game_mechanics.h $(SRC_LIB)/players_and_bots.h
	$(GCC) $(FLAGS) -c $<

main.o: $(SRC)/main.cpp $(SRC_LIB)/game.h
	$(GCC) $(FLAGS) -c $<

main: main.o game.o saving_and_loading.o players_and_bots.o game_mechanics.o cricketer.o ai.o constants.o
	$(GCC) $(FLAGS) $^ -o $@

clean:
	$(RM) main *.o

.PHONY: clean