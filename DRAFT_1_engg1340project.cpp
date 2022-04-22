#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
using namespace std;


struct Player
{
    string name;
    int runs;
};


string TEAM_NAME, TEAM_NAME_2;

string PLAYERS_Team1[5];
string PLAYERS_Team2[5];

string flipcoin()
{
    if (rand() % 2 == 0) 
    {
        return "HEADS";
    }    
    else 
    {
        return "TAILS";
    }    

}


string TOSS()
{
    cout<< " TOSS "<< endl;


    cout<< "Player 1 select HEADS or TAILS "<<endl<<endl;

    string descision;

    cin>> descision;

    if (flipcoin() == descision)
    {
        cout<<TEAM_NAME<<" won the toss"<<endl<<endl;

        return "Player 1 won the toss";
        

    }
    else
    {
        cout<<TEAM_NAME_2<<" won the toss"<<endl<<endl;

        return "Player 2 won the toss";

    }


}




void batting( string array[])
{



    int runs;
    string player;
    
  

    cin>>player;

    while(player != array[0] && player != array[1] && player != array[2] && player != array[2] && player != array[3] && player != array[4])
    {
        cout<<"Please input correct player name"<<endl<<endl;

        cin>>player;
    }

    cout<< player <<" please input runs between 0-6"<<endl<<endl;
 
    cin>> runs;
 
    while(runs != 0 && runs != 1 && runs != 2 &&  runs != 3 && runs != 0 &&  runs != 5 && runs != 6)
    {
        cout<< "Please input correct runs"<<endl<<endl;
        cin>> runs;
    }










    





}

int main()
{

    string result_toss;

    string choice;


    int overs;

    srand(time(NULL));
    cout<<endl;

    cout << setw(5)<< "           -------WELCOME TO THE GAME OF CRICKET-------            "<< endl<< endl;




    cout<<"Enter the number of Overs you want to have in the match (NOTE: Each Over has 6 balls)"<<endl<<endl;
    cout<<"2 OVERS or 4 OVERS  (ENTER 2 or 4)"<<endl;

    
    cin>>overs;
    while ((overs != 2)&&(overs != 4))
    {
        cout<<"Please enter correct overs"<<endl;

        cin>>overs;
    }


    cout<< "We are about to have a "<<overs <<" overs CRICKET MATCH !!"<<endl<<endl;

    cout<< "Player 1 Enter the name of your team: "<<endl<<endl;


    cin>> TEAM_NAME;

    cout<< "Player 2 Enter the name of your team: "<<endl<<endl;


    cin>> TEAM_NAME_2;


    cout<< "Player 1 enter your team player names (Total 5 names) "<<endl<<endl;

    for(int i=0; i<5; i++)
    {
        cin>>PLAYERS_Team1[i];
    }


    cout<< TEAM_NAME << " has the following players :"<<endl<<endl;

    for(int i=0; i< 5; i++)
    {
        cout<<PLAYERS_Team1[i]<<" ";
    }

    cout<<endl;

    cout<< "Player 2 enter your team player names (Total 5 names) "<<endl<<endl;

    for(int i=0; i<5; i++)
    {
        cin>>PLAYERS_Team2[i];
    }

    cout<< TEAM_NAME_2 << " has the following players :"<<endl<<endl;

    for(int i=0; i< 5; i++)
    {
        cout<<PLAYERS_Team2[i]<<" ";
    }
    cout<<endl;

    cout<<endl;



    result_toss= TOSS();

    cout<<endl;

    if(result_toss == "Player 1 won the toss")
    {
        cout<<"Player 1  what will you like to do first : BATTING OR BOWLING"<<endl<<endl;

        cin>> choice;

        if (choice == "BATTING")
        {
            cout<< TEAM_NAME << " decided to " << choice<< " first"<< endl<<endl;

            cout<< "Player 1 send your first player to bat"<<endl<<endl;

            batting(PLAYERS_Team1);
        }
    }
    else
    {
        cout<<"Player 2  what will you like to do first : BATTING OR BOWLING"<<endl<<endl;

        cin>> choice;

        if (choice == "BATTING")
        {
            cout<< TEAM_NAME_2 << " decided to " << choice<< " first"<< endl<<endl;

            cout<< "Player 2 send your first player to bat"<<endl<<endl;

            batting(PLAYERS_Team2);
        }

    }



    
}


