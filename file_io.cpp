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


    filename.open("Sudoku_file.txt",ios::out | ios::in);

    if(!filename)
    {
        cout<<"No File is Created "<<endl;
    }

    filename<<message;
    filename>>message;
    cout<<"Enter the Player Name "<<endl;
    getline(cin,name);
    filename<<name<<endl;
    filename>>name;

    cout<<message<<endl;
    cout<<"Your Name : "<<name<<endl;

    highscore=900-diff;

    if(highscore<0)
    {
        filename<<"You already crossed the Time limit i.e., 900 seconds"<<endl;
        filename>>"You already crossed the Time limit i.e., 900 seconds"<<endl;
    }
    else if(highscore>450 && highscore<800)
    {
        message1="GOOD";
        filename<<message1;
        filename>>message1;

    }
    else if(highscore>800)
    {
        message1="Outstanding";
        filename<<message1;
        filename>>message1;

    }
    else if(highscore<200)
    {
        message1="Bad";
        filename<<message1;
        filename>>message;
    }
    


    filename.close();

    

    return 0;

}
