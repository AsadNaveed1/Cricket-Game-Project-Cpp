# STAGE 1 - PROPOSAL

## Team members:-

Muhammad Asad Naveed 3035957848   
Sumer Kaistha 3035859448  

## Game Description:-

We have made a cricket game based on a hand cricket game which is commonly played in India and Pakistan just like rock paper scissors. 

The game we have made is a User vs AI game. To start with, there is a toss. If the user wins the toss, he gets to choose whether to start with batting or bowling. The player can then customize the game as he or she wishes. For example - The user can customize their team size, their opponent's team size and the number of overs. The player is then asked to input a number from 1 - 6. If the player is batting then the runs he gets is equivalent to the number input. For example if the person inputs 2, he gets 2 runs. The opponent (AI) who is bowling will also choose a number from 1 - 6 and if the number chosen is the same as the number chosen by the player who is batting, the player who is batting is out and now and it moves onto the next player in the team. Once all player's are out then the user and the AI switch sides from batting to bowling or vice verse. At the end of the game the team with more runs will win the match.



## Game Rules/ Instructions:-

1. First there will be a toss, you have to choose either heads or tails. If you win the toss, you have to choose whether you want to bat or bowl.

2. You have to choose which format you want to play (How many overs you want per innings. There are 6 balls per over).

3. You will have to decide how many players to have on your team and the opponent's team.  

4. You have to choose a number between 1 and 6 when it's your turn or you can choose to save and quit.

5. If your decision and your opponent's decision are the same, then the player who is batting is out

6. When all the players in the team are out or the total number of balls in the over and thrown then the first innings ends and the teams will switch sides from batting to bowling or vice versa

7. The team that scores more during their batting is declared as the WINNER at the end of the match. If both teams score the same, then the result will be a draw

( Note: you can choose to continue your prevously saved session once the game starts )

### Enjoy!!!


## Compilation Commmand:-

First run "make main" in the terminal     
Then run "./main" to start the game


## Features:-

1. Structs are created to hold information about each player (Cricketer) and data structures suuch as an array of the struct cricketer will be used to store all the cricketers on a team. This covers the second requirement, i.e. Data Structures for storing the game status

2. Interactive and customizable team sizes for both the opponent and user as well as customizable number of overs per innings. The team is stored in an array and hence, dyanmic memory management is used in the game to allow for customization of the game. This covers the third requirement, i.e. Dynamic Memory Management

3. The AI uses a random generation of numbers from 1 - 6 as well the user's previous inputs to generate two possible choices from 1 - 6. The two options are then chosen from randomly at 7:3 ratio. This covers the first requirement, i.e. Generation of random game sets or events.

4. Use File input/output to store the status of the game. The user can choose to save and quit the game at any time during the game. If the player chooses the quit then the game can be loaded at a later time. This covers the fourth requirement, i.e. File input/output for saving and loading game status.

5. Using makefile to compile different files with each file holding information about different functions of the game. This covers the fifth requirement, i.e. Program code in multiple files

## Function and Files

1. Main File: Allows the user to start a game, read the instructions or exit the game

2. AI File: Holds the function to allow for a Smart AI choices

3. Constants File: Holds all the constant variables which do not change throughout the program

4. Cricketer File: Holds the definition of the struct 'Cricketer' and the function to delete the cricketer array

5. Game Mechanics File: Holds the functions that are used in the game mechanics. For example - toss function or switch_teams function

6. Game File: Holds the functions for outputting information about the game. For example - functions for outputting the main menu, game name, results, the user move and ai move

7. Players and Bots File: Functions for returning the move of the user and the AI

8. Saving and Loading File: Functions for Initializing the variables in the game (loading the game) and for saving the values of the variables to a text file and quitting the game (saving and quitting the game)
