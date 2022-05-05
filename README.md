# STAGE 1 - PROPOSAL

## Team members:-

Muhammad Asad Naveed 3035957848   
Sumer Kaistha 3035859448  

## Game Description:-

We have made a cricket game based on a hand cricket game which is commonly played in India just like rock paper scissors. 

The game we have made is a User vs AI game. To start with, there is a toss. If the user wins the toss, he gets to choose whether to start with batting or bowling. The player is then asked to input a number from 1 - 6. If the player is batting then the runs he gets is equivalent to the number input. For example if the person inputs 2, he gets 2 runs. The opponent (AI) who is bowling will also choose a number from 1 - 6 and if the number chosen is the same as the number chosen by the player who is batting, the player who is batting is out and now and it moves onto the next player in the team. Once all player's are out then the user and the AI switch sides from batting to bowling or vice verse. At the end of the game the team with more runs will win the match.



## Game Rules:-

1. First there will be a toss, you have to choose either heads or tails. If you win the toss, you have to choose whether you want to bat or bowl.

2. You have to choose which format you want to play (How many overs you want per innings. There are 6 balls per over).

3.  You will have to decide how many players to have on your team and the opponent's team.  

4. You have to choose a number between 1 and 6 when it's your turn.

5. If your decision and your opponent's decision are the same, then the player who is batting is out

6. When all the players in the team are out or the total number of balls in the over and thrown then the first innings ends and the teams will switch sides from batting to bowling or vice versa

7. The team that scores more during their batting is declared as the WINNER at the end of the match. If both teams score the same, then the result will be a draw

### Enjoy!!!



## Features:-

1. Structs are created to hold information about each player (Cricketer) and data structures suuch as an array of the struct cricketer will be used to store all the cricketers on a team.

2. Interactive and customizable team sizes for both the opponent and user as well as customizable number of overs per innings. The team is stored in an array and hence, dyanmic memory management is used in the game to allow for customization of the game. 

3. The AI uses a random generation of numbers from 1 - 6 as well the user's previous inputs to generate two possible choices from 1 - 6. The two options are then chosen from randomly at 7:3 ratio. This covers the first requirement, i.e Generation of random game sets or events.

4. Use File input/output to store the status of the game. The user can choose to save and quit the game at any time during the game. If the player chooses the quit then the game can be loaded at a later time.  

5. Using makefile to compile different files with each file holding information about different functions of the game.
