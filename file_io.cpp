#include<iostream>
#include<fstream>
#include<string>

#include "player.h"

using namespace std;
using namespace user_gm;



void Player::player_input(double diff)
{
    fstream filename;
    string message="Welcome to the Sudoku Game";
    string name;
    double highscore;
    string message1;
    string message2="WON,LOST,HIGHSCORE";
    int won=0;
    int lost=0;


    filename.open("Sudoku_file.txt",ios::app | ios::in);

    if(!filename)
    {
        cout<<"No File is Created "<<endl;
    }

    filename<<message;
    filename>>message;
    cout<<"Enter the Player Name "<<endl;
    getline(cin,name);
    filename<<name;
    filename>>name;


    highscore=900-diff;

    if(highscore<0)
    {
        message1="You already crossed the Time limit i.e., 900 seconds";
        filename<<message1;
        ++lost;
    }
    else if(highscore>450 && highscore<800)
    {
        message1="GOOD";
        filename<<message1;
        ++won;

    }
    else if(highscore>800)
    {
        message1="Outstanding";
        filename<<message1;
        ++won;

    }
    else if(highscore<200)
    {
        message1="Bad";
        filename<<message1;
        ++won;
    }
    filename<<message2<<won<<lost<<highscore;
    
    filename.close();

    

}
