#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdio>

#include "player.h"

using namespace std;
using namespace user_gm;

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
    int searching();
    void filewrite();
    void display();
    int main();

};


void file::filewrite()
{
   
  filename.open("Player_record.csv",ios::app | ios::in | ios::out);

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
    {
    cout<<"Enter your name"<<endl;
    gets(name);
    filename<<name;
    filename>>name;
    }

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
void file::display()
{

         filename.read((char*)&name, sizeof(name));
         cout << "\n Player Name:\t" << name;
         cout << "\n WON" <<won;
         cout << "\n LOST \t" <<lost;
         cout << "\n HIGHSCORE \t"<<highscore;
                      
}
int file::searching()
{
     fstream filename;
     char name1[30];
     filename.open("Player_record.csv",ios::in|ios::app|ios::out);
     cout<<"Enter Player name";
     gets(name1);
     if(!filename)
        cout<<"file not created ";
     
     else
     {
         filename.read((char*)this,sizeof(*this));
         while(!filename.eof())
         {
 
          if(!strcmp(this->name,name1))
          {
            return 1;
             break;
          }
          filename.read((char*)this,sizeof(*this));
         }
         if(filename.eof())
         {
          cout<<"\nRecord not found\n";
          return -1;
         }

          
    
     filename.close();
}
}
 

int main()
{
    file obj;
    

   if(obj.searching()==-1)
   {
       cout<<"You are a new Player "<<endl;
       obj.filewrite();
   }
   else if(obj.searching()==1)
   {
       cout<<"Your Record Exists"<<endl;
       obj.display();
   }

    return 0;


}

 
