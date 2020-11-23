#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdio>

#include "player.h"


using namespace std;

class file
{
    public:
    fstream filename;
    string message="Welcome to the Sudoku Game";
    char namee[30];
    double highscore;
    string message1;
    string message2="WON,LOST,HIGHSCORE";
    int won=0;
    int lost=0;
    int diff=50;
    int searching();
    int filewrite(char[]);
    void display();
    int main();

};


int file::filewrite(char[])
{
   
  filename.open("Player_record.txt",ios::app | ios::in | ios::out);

    if(!filename)
    {
        cout<<"No File is Created "<<endl;
    }
    else
    {
        cout<<"File created successfully"<<endl;
    

    filename<<namee;
    filename>>namee;

    cout<<"New Record Added"<<endl;
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

    
    

    
}
void file::display()
{

         filename.read((char*)&namee, sizeof(namee));
         cout << "\n Player Name:\t" <<namee;
         cout << "\n WON" <<won;
         cout << "\n LOST \t" <<lost;
         cout << "\n HIGHSCORE \t"<<highscore;
                      
}
int file::searching()
{
     fstream filename;
     char name1[30];
     filename.open("Player_record.txt",ios::in|ios::app|ios::out);
     cout<<"Enter Player name\n";
     cin.getline(name1,30);
     if(!filename)
     {
        cout<<"file not created ";
     }
     
     else
     {
         filename.read((char*)this,sizeof(*this));
         while(!filename.eof())
         {
 
          if(!strcmp(this->namee,name1))
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

          
    
     
}
}
 

int main()
{
    file obj;

    char namee[30];
    
   if(obj.searching()==1)
   {
       obj.display();

   }
   else if(obj.searching()==-1)
   {
       cout<<"NOW ENTER NEW RECORD"<<endl;
       cin.getline(namee,30);
       obj.filewrite(namee);
   }
   

    return 0;


}

 
