#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    fstream filename;
    string message="Welcome to the Sudoku Game";
    string name;


    filename.open("Sudoku_file.txt", ios::out | ios::in );

    if(!filename)
    {
        cout<<"No File is Created "<<endl;
    }

    cout<<"File created successfully "<<endl;
    filename<<message<<endl;
    filename>>message;
    cout<<"Enter the Player Name "<<endl;
    getline(cin,name);
    filename<<name<<endl;
    filename>>name;

    
    cout<<message<<endl;
    cout<<"Your Name "<<name<<endl;

    filename.close();

    return 0;

}
