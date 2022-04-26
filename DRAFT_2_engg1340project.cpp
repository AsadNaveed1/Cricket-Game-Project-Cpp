#include<iostream>
#include <time.h>
#include<string.h>
#include <cstdlib>
#include <ctime>

using namespace std;



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

void main_menu()
{
    cout << "\n\nMAIN MENU :-";
    cout << "\n\n1. Start a new game" << endl;
    cout << "\n2. Instructions" << endl;
    cout << "\nPress any other key to end the program" << endl;
    cout << "\nEnter your decision: ";
    
}
void instructions()
{
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
bool toss()
{    
    int coin_side_chosen, coin_side_landed;

    cout << "\n\nWELCOME TO TOSS!\n";
   
    cout << "\n Player 1 Choose your call:\n Please enter '1' for Heads and '2' for Tails ";
    cin >> coin_side_chosen;
    coin_side_landed = rand()%2+1;
    if(coin_side_landed == coin_side_chosen)
    {
        
        cout << "\n\n******************** You've won the Toss ********************" << endl;
        return true;
    }
    else
    {
        
        cout << "\n\n******************** You've lost the Toss ********************" << endl;
        return false;
    }
}

int player()
{   
    int res;
    
    cout << "\nPlayer 1 Choose a number between 1 and 6: ";
    while(1)
    {
        cin >> res;
        if(res>6||res<1)
        {
            
            cout << "Please select a number between 1 and 6: ";
            continue;
        }
        else
        {
            break;
        } 
    }


    return res;
}
int player2()
{  
    int res;
    
    cout << "\nPlayer 2 Choose a number between 1 and 6: ";
    while(1)
    {
        cin >> res;
        if(res>6||res<1)
        {
            
            cout << "Please select a number between 1 and 6: ";
            continue;
        }
        else 
        {
            break;
        }    
    }
    return res;
}

int comp()
{ 
    int res;

    cout << "\nPlayer 1 input a number to deliver a ball: ";

    cin>>res;

    res = rand()%6+1;
    
    cout << "\nThe ball delivered by Player 1 is: " << res << endl;
    return res;
}

int comp2()
{ 
    int res;

    cout << "\nPlayer 2 input a number to ball: ";

    cin>>res;

    res = rand()%6+1;
    
    cout << "\nThe ball delivered by Player 2 is: " << res << endl;
    return res;
}

void start_game()
{
    game_name();
    srand(time(0));
    
    cout << "\n\n\n";
    
    cout << "GAME STARTS!!!"<<endl;
    
    int side_choice, overs, balls, t1, t2;
    int player_score=0, player2_score=0, b=0, first=0, second=0;  
    string bat, bowl;    
    
    cout << "\nHow many Overs match would you like to have?";
    cin >> overs;
    balls = overs * 6;
    bool toss_result = toss();
    bool out = false;
    if(toss_result)
    {    
        cout << "\nSelect your side:\n Please enter '1' for batting and '2' for bowling\n";
        cin >> side_choice;
    }
    else
    {
        side_choice = rand()%2 + 1;
    }
    if(side_choice == 1)
    {
        bat = "Player";
        bowl = "AI";
    }
    else if (side_choice = 2)
    {
        bowl = "Player";
        bat = "AI";
    }
    else
    {
        cout << "Please only enter '1' or '2' to select your choice";
    }
    
    cout << "\n\n";
   
    cout << "FIRST INNINGS";
    
    if(bat=="player") 
    {
        cout << "\n\n---------------------------------Player 1 is Batting---------------------------------\n";
        while((!out)&&(b<balls))
        {   //First Innings
            t1=player();
            t2=comp2();
            if(t1==t2) 
            {
                out = true;
            
                cout << "\nIt's OUT!!!\n";
            }
            else
            {
                player_score += t1;
            
            }
            b++;
        }

    }    
    else
    {
        cout << "\n\n---------------------------------Player 2 is Batting---------------------------------\n";
        while((!out)&&(b<balls))
        {   //First Innings
            t1=player2();
            t2=comp();
            if(t1==t2) 
            {
                out = true;
            
                cout << "\nIt's OUT!!!\n";
            }
            else
            {
                player2_score += t1;
            }
            b++;
        }

    } 

    //Before second innings need to change bat and bal
    if(bat=="player")
    {
        bat = "player2";
        bowl = "player";
        first = player_score;
        
        cout << "\nFirst Innings Ended!!\n";
       
        cout<<"\nPlayer 1 Score is "<< first <<endl;
   
        cout << "\n\n";
       
        cout << "SECOND INNINGS";
        
        cout << "\n\n---------------------------------Player 2 is Batting Now!!---------------------------------\n";
    }
    else
    {
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
    b=0;

    if(bat=="player")
    {
        while((!out)&&(b<balls)&&(second<=first))
        {   //Second Innings
            t1=player();
            t2=comp2();
            if(t1==t2)
            {
                out = true;
            
                cout << "\nIt's OUT!!!\n";
            } 
            else
            {
                player_score += t1;
                second+=t1;

            }
            b++;
        }

    }

    else
    {
        while((!out)&&(b<balls)&&(second<=first))
        {   //Second Innings
            t1=player2();
            t2=comp();
            if(t1==t2)
            {
                out = true;
            
                cout << "\nIt's OUT!!!\n";
            } 
            else
            {
 
                player2_score += t1;
                second+=t1;
            
            }
            b++;
        }
    }

    

    if(bat=="player")
    {
        
        cout << "\nSecond Innings Ended!!\n";
       
        cout <<"\nPlayer 1 Score is "<< second <<endl;
        
        cout <<"=============================================================================================================";
   
        cout << "\n\n";
       
        cout << "RESULT";
        if(first>second) 
        {
            
            cout << "\n\n    Player 2 WON!!";
        }
        else if(first == second) 
        {
        
            cout << "\n\nMatch Draw!!";
        }
        else
        {
           
            cout << "\n\n    Player 1 Won!!";
        }
    }
    else
    {
        
        cout << "\nSecond Innings Ended!!\n\n";
       
        cout <<"Player 2 Score is "<< second <<endl;
        
        cout <<"=============================================================================================================";
   
        cout << "\n\n";
       
        cout << "RESULT";
        if(first>second) 
        {
           
            cout << "\n\n    Player 1 Won!!";
        }
        else if(first == second) 
        {
            
            cout << "\n\nMatch Draw!!";
        }
        else 
        {
            
            cout << "\n\n    Player 2 Won!!";
        }
    }
    
    cout <<"\n\n=============================================================================================================";
   
    cout << "\n\nPress '0' to return to main menu....";
    
}
int main()
{
    while(1)
    {
        game_name()
        main_menu();
        char main_menu_choice, return_to_menu;
        cin >> main_menu_choice;
        if(main_menu_choice == '1')
        {
            start_game();       
            cout << "Press any key to return to main menu...";
            cin >> return_to_menu;
        }
        else if(main_menu_choice == '2')
        {
            instructions();
            cout << "Press any key to return to main menu...";
            cin >> return_to_menu;
        }
        else
        {
            break;
        }    
    }
    return 0;
}