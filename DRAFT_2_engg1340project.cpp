#include<iostream>
#include <time.h>
#include<string.h>
#include <cstdlib>
#include <ctime>

using namespace std;


void game_name(){
    
    cout << endl;
    
    cout << "\t|-----------------------------------------------------------|\n" << endl;


                                   
    cout << "              ██████╗██████╗ ██╗ ██████╗██╗  ██╗███████╗████████╗"<<endl;
    cout << "             ██╔════╝██╔══██╗██║██╔════╝██║ ██╔╝██╔════╝╚══██╔══╝"<<endl;
    cout << "             ██║     ██████╔╝██║██║     █████╔╝ █████╗     ██║   "<<endl;
    cout << "             ██║     ██╔══██╗██║██║     ██╔═██╗ ██╔══╝     ██║   "<<endl;
    cout << "             ╚██████╗██║  ██║██║╚██████╗██║  ██╗███████╗   ██║   "<<endl;
    cout << "              ╚═════╝╚═╝  ╚═╝╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝   ╚═╝   "<<endl;
                                                                 

                                                    

  
                                                    
    
    cout << "\t" << endl;
    cout << "\t|----------------------------------------------------------|\n" << endl;
}

void mainmenu()
{
    
    cout << "\n\n\t";
   
    cout << "MAIN MENU :-";
    
    cout << "\n\n\t1.Start a new game" << endl;
    cout << "\n\t2.Instructions" << endl;
    cout << "\n\tPress any other key to exit the game" << endl;
    cout << "\n\tEnter your descision: ";
    
}
void instructions()
{
    game_name();
    cout <<"\n";
    
    cout << "\t\t\t\tINSTRUCTIONS AND RULES";

    cout << "\n";
    cout << "\n\t1. You have to choose which format you want to play."<<endl;
    cout << "\n\t2. If you won a toss, you have to choose what you will do, i.e., Batting or Balling."<<endl;
    cout <<"\n\t3. You have to choose a number between 1 and 6 during your turn."<<endl;
    cout <<"\n\t4. If your descision and your opponents descision are same, then the person who is batting is considered as OUT."<<endl;
    cout <<"\n\t5. One who scores more during their batting is declared as WINNER."<<endl;
    cout <<"\n\t6. If both scores same, then the result will be 'DRAW'."<<endl;
    
    cout << "\n\n\t\tPress '0' to go back to main menu....";
    
}
bool toss()
{    
    char descision;
    int t,c;
    
    cout << "\n\n\t\t\tWELCOME TO TOSS!\n";
   
    cout << "\n\t Player 1 Choose your call:\n\t1. HEADS or 2. TAILS:\t";
    cin >>descision;
    if((descision=='h'||descision=='H'||descision=='1'))
    { 
        c=1;
    }
    else if((descision=='t'||descision=='T'||descision=='2'))
    { 
        c=2;
    }
    srand(time(0));
    t = rand()%2+1;
    if((t==1&&c==1 )||(t==2&&c==2))
    {
        
        cout << "\n\n\t********************\tPlayer 1 You've won the Toss\t********************" << endl;
        return true;
    }
    else
    {
        
        cout << "\n\n\t********************\tPlayer 2 You've won the Toss\t********************" << endl;
        return false;
    }
}

int player()
{   
    int res;
    
    cout << "\n\tPlayer 1 Choose a number between 1 and 6: ";
    while(1)
    {
        cin >> res;
        if(res>6||res<1)
        {
            
            cout << "\tPlease select a number between 1 and 6: ";
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
    
    cout << "\n\tPlayer 2 Choose a number between 1 and 6: ";
    while(1)
    {
        cin >> res;
        if(res>6||res<1)
        {
            
            cout << "\tPlease select a number between 1 and 6: ";
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

    cout << "\n\tPlayer 1 input a number to deliver a ball: ";

    cin>>res;

    res = rand()%6+1;
    
    cout << "\n\tThe ball delivered by Player 1 is: " << res << endl;
    return res;
}

int comp2()
{ 
    int res;

    cout << "\n\tPlayer 2 input a number to ball: ";

    cin>>res;

    res = rand()%6+1;
    
    cout << "\n\tThe ball delivered by Player 2 is: " << res << endl;
    return res;
}

void start_game()
{
    game_name();
    
    
    cout << "\n\n\n\t\t\t\t";
    
    cout << "    GAME STARTS!!!"<<endl;
    
    int descision,Overs,balls, t1,t2;
    int player_score=0,player2_score=0,b=0,first=0,second=0;  
    string bat,bal;    
    
    cout << "\n\tHow many Overs match would you like to have?\n\t1. 1 Over Match\n\t2. 2 Over Match\n\t3. 5 Over Match\n\t\tEnter your descision: ";
    cin>>Overs;
    while(1)
    {   
        if(Overs==1)
        {
            balls = 6;
            break;
        }
        else if(Overs==2)
        {
            balls = 12;
            break;
        }
        else if(Overs==3)
        {
            balls = 30;
            break;
        
        }
        else
        {
            
            cout << "\n\tPlease select a valid format!";
            continue;
        }
    }
    bool toss_result = toss();
    bool out=false;
    if(toss_result)
    {    
        cout << "\n\tSelect your descision:\n\t1.Batting\t\t2.Balling\n\t";
        cin >> descision;
        if(descision==1)
        {
            bat = "player";
            bal = "player2";
        }
        else
        {
            bat = "player2";
            bal = "player";
        }
    }
    else
    {
        cout << "\n\tWhat would you like to do first:\n\t1.Batting\t\t2.Balling\n\t";
        cin >> descision;
        if(descision==1)
        {
            bat = "player2";
            bal = "player";
        }
        else
        {
            bat = "player";
            bal = "player2";
        }
    }
    
    cout << "\n\n\t\t\t\t";
   
    cout << "     FIRST INNINGS";
    
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
            
                cout << "\n\tIt's OUT!!!\n";
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
            
                cout << "\n\tIt's OUT!!!\n";
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
        bal = "player";
        first = player_score;
        
        cout << "\n\tFirst Innings Ended!!\n";
       
        cout<<"\n\tPlayer 1 Score is "<< first <<endl;
   
        cout << "\n\n\t\t\t\t";
       
        cout << "SECOND INNINGS";
        
        cout << "\n\n---------------------------------Player 2 is Batting Now!!---------------------------------\n";
    }
    else
    {
        bal = "player2";
        bat = "player";
        first = player2_score;
        
        cout << "\n\tFirst Innings Ended!!\n";
       
        cout<<"\n\tPlayer 2 Score is "<< first <<endl;
   
        cout << "\n\n\t\t\t\t";
       
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
            
                cout << "\n\tIt's OUT!!!\n";
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
            
                cout << "\n\tIt's OUT!!!\n";
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
        
        cout << "\n\tSecond Innings Ended!!\n";
       
        cout <<"\n\tPlayer 1 Score is "<< second <<endl;
        
        cout <<"=============================================================================================================";
   
        cout << "\n\n\t\t\t\t\t";
       
        cout << "RESULT";
        if(first>second) 
        {
            
            cout << "\n\n\t\t\t\t    Player 2 WON!!";
        }
        else if(first == second) 
        {
        
            cout << "\n\n\t\t\t\t\tMatch Draw!!";
        }
        else
        {
           
            cout << "\n\n\t\t\t\t    Player 1 Won!!";
        }
    }
    else
    {
        
        cout << "\n\tSecond Innings Ended!!\n\n";
       
        cout <<"\tPlayer 2 Score is "<< second <<endl;
        
        cout <<"=============================================================================================================";
   
        cout << "\n\n\t\t\t\t\t";
       
        cout << "RESULT";
        if(first>second) 
        {
           
            cout << "\n\n\t\t\t\t    Player 1 Won!!";
        }
        else if(first == second) 
        {
            
            cout << "\n\n\t\t\t\t\tMatch Draw!!";
        }
        else 
        {
            
            cout << "\n\n\t\t\t\t    Player 2 Won!!";
        }
    }
    
    cout <<"\n\n=============================================================================================================";
   
    cout << "\n\n\t\tPress '0' to return to main menu....";
    
}
int main()
{
    srand(time(NULL));

    while(1)
    {
        game_name();

        mainmenu();

        char descision;
        cin >> descision;
        if(descision=='1')
        {
            start_game();
            char ch;
            cin >> ch;
            while(ch!='0')
            {
                
                cout << "\t\tPress '0' to return to main menu....";
                
                cin >> ch;
            }
            continue;
        }
        else if(descision=='2')
        {
            instructions();
            char character;
            cin >> character;
            while(character!='0')
            {
                
                cout << "\t\t\tPress '0' to return to main menu....";
                
                cin >> character;
            }
            continue;
        }
        else
        {
            break;
        }    
    }
    return 0;
}