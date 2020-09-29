#include <iostream> // input output header file 
#include <string> // Header file for string 

using namespace std; // for cin and cout 

/*
 * Class sudoku creates a sudoku board with 9 cells in a row and 9 rows 
 * that is it has 81 cells in the whole board.
 */

class Sudoku 
{
	private: //Declaring private data members that is they cannot be accessed outside the class
	
		int board[9][9]; //To design a 9x9 board for sudoku //
		int filled; //contains the number of cells filled in sudoku //
		int unfilled; //contains the number of unfilled or empty cells in sudoku //
	
	public: // Data members and functions within the public access specifier can be accessed from anywhere
		
	      Sudoku() // Default constructor 
		{
			// Taking a string input for difficulty of the board so as
			// to enhance the readablity of the code and not remember
			// what value corresponds to which difficulty

			string Difficulty; 
		      
		      // Printing the menu for difficulty for the User //
		      
			cout << "Enter the level of difficulty: "<<endl;
			cout << "\t1. Easy" <<endl;
			cout << "\t2. Medium" <<endl;
			cout << "\t3. Hard" <<endl;
			
			getline(cin,Difficulty); //for input of string difficulty
			
			// Comparing difficulty entered by the user to the Specified  difficulty levels 
			
			if(Difficulty.compare("Easy") == 0) // Using string compare function which compares Difficulty entered by the user with the string specified //
			
				//In this case it is comparing the difficulty with "Easy//
				
			{			
				filled = 60; //for easy
			}
			else if(Difficulty.compare("Medium") == 0)
			{
				filled = 50; //for medium
			}
			else if(Difficulty.compare("Hard") == 0)
			{
				filled = 40;  //for hard
			}
			else
			{
				filled = 60; //if the difficulty is unspecified
			}
			unfilled=81-filled; // remaining cells after removing the filled cells i.e the no of unfilled cells
			
			//initializing every element or cells of the board as -1

			for (int i = 0; i < 8; i++) 
			{
				for (int j = 0; j < 8; j++)
				{
					board[i][j] = -1; //every cell in the sudoku board is intiliazed as -1 //
				}
			}
		}
		
		void input() //function for getting input for each cell of the sudoku
		{
			//inputing elements in the 9 x 9 sudoku or board
			
			for(i=0;i<10;i++) 
			{
				for(j=0;j<10;j++)
				{
					cout << "Enter the location where you want to insert the element" << endl; //asking for the location of the element you want to insert
					
					cout << "Enter row: ";  //taking row as a input
					cin >> row;
					
					cout << "Enter column "; //taking column as a input
					cin >> col;
					
					if (row > 8 || row < 0 || col < 0 || col > 8) //checking if the row or column entered by the player lies outside the range i.e., from 0 to 9
						                                                                                         
					{
						cout << "Error! Wrong position entered. Please enter the position again.\n" << endl;
						continue; //skips or jumps out of the condition if the row or column lies outside the range
					}
					
					if(row==i && col==j) // checks if entered row and column lies with in the range 
					{
						cout<<"Enter your Element"<<endl;
						cin>>a[i][j];	//inputting element for the specified row and column
					}
				}
			}
		}
}

