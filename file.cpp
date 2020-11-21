#include<iostream>
#include<fstream>
#include<string>

#include "player.h"

using namespace std;
using namespace user_gm;

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class file
{
    public:
    fstream filename;
    string message="Welcome to the Sudoku Game";
    char name[30];
    double highscore;
    string message1;
    string message2="WON,LOST,HIGHSCORE";
    int won=0;
    int lost=0;
    int diff=50;
    void filewrite();
    void fileread();

};
void file::filewrite()
{
   
  filename.open("Player_record.txt",ios::app | ios::in | ios::out);

    if(!filename)
    {
        cout<<"No File is Created "<<endl;
    }
    else
    {
        cout<<"File created successfully"<<endl;
    }
    
    filename<<message;
    filename>>message;


    if(filename)
    
    filename<<name;
    filename>>name;

    cout<<name;

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
    filename>>message2>>won>>lost>>highscore;

    
    filename.close();

    
}

void file::fileread()
{

    char name2[30];
     cout<<"Enter Your Name"<<endl;
     cin.getline(name2,30);

     if(name==name2)
     {
         filename.read((char*)&name2, sizeof(name2));
         cout << "\n Player Name:\t" << name;
         cout << "\n WON" <<won;
         cout << "\n LOST \t" <<lost;
         cout << "\n HIGHSCORE \t"<<highscore;
                      
    }
    
   else
    {
       cout<<"Creating new Player Record"<<endl;
       fileread();
       filename.close();
    }
                  
}
int main()
{
    file obj;
    
    obj.fileread();


}
