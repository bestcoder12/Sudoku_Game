#include<iostream>
#include<fstream>
#include<string>

using namespace std;
using namespace user_gm;


int main()
{
    fstream filename;
    string message="Welcome to the Sudoku Game";
    string name;
    string highscore;
    string message1;
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
    filename<<"Your Name: "<<name;
    filename>>"Your Name: ">>name;


    highscore=900-diff;

    if(highscore<0)
    {
        filename<<"You already crossed the Time limit i.e., 900 seconds";
        filename>>"You already crossed the Time limit i.e., 900 seconds";
        ++lost;
    }
    else if(highscore>450 && highscore<800)
    {
        message1="GOOD";
        filename<<message1;
        filename>>message1;
        ++won;

    }
    else if(highscore>800)
    {
        message1="Outstanding";
        filename<<message1;
        filename>>message1;
        ++won;

    }
    else if(highscore<200)
    {
        message1="Bad";
        filename<<message1;
        filename>>message;
        ++won;
    }
    filename<<"No of games WON: "<<won<<"    No of games Lost: "<<lost<<"    HighScore:"<<highscore;
    filename>>"No of games WON: ">>won>>"    No of games Lost: ">>lost>>"    HighScore:"<<highscore;
    
    filename.close();

    

    return 0;

}
