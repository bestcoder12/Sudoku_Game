// input output header file 
#include <iostream> 
// Header file for string operations
#include <string> 

// for cin and cout 
using namespace std; 

/*
 * Class sudoku creates a sudoku board with 9 cells in a row and 9 rows 
 * that is it has 81 cells in the whole board.
 */

class Sudoku 
{
	//Declaring private data members that is they cannot be accessed outside the class
	private: 
		//To design a 9x9 board for sudoku //
		    int board[9][9]; 
		//contains the number of cells filled in sudoku //
	        int filled; 
		//contains the number of unfilled or empty cells in sudoku //
	        int unfilled; 
	
	// Data members and functions within the public access specifier can be accessed from anywhere
	public: 
		
	    // Default constructor 
	    Sudoku() 
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
			
	        //for input of string difficulty
			getline(cin,Difficulty); 
			
			// Comparing difficulty entered by the user to the Specified  difficulty levels 
			
		    // Using string compare function which compares Difficulty entered by the user with the string specified //
		    if(Difficulty.compare("Easy") == 0) 
				//In this case it is comparing the difficulty with "Easy//
			{	
                //for easy		
				filled = 60; 
			}
			else if(Difficulty.compare("Medium") == 0)
			{ 
				//for medium
				filled = 50; 
			}
			else if(Difficulty.compare("Hard") == 0)
			{
				//for hard
				filled = 40;  
			}
			else
			{
				//if the difficulty is unspecified
				filled = 60; 
			}

            // remaining cells after removing the filled cells i.e the no of unfilled cells

			unfilled = 81-filled;

			// Initializing the board with invalid values
            // that is initializing every element or cells of the board as -1

			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					//every cell in the sudoku board is intiliazed as -1 //
					board[i][j] = -1; 
				}
			}
		}
		
	        //function for getting input for each cell of the sudoku
		void input() 
		{
			//inputing elements in the 9 x 9 sudoku or board
			
			for(i=0;i<10;i++) 
			{
				for(j=0;j<10;j++)
				{
					
                                       //asking for the location of the element you want to insert
					cout << "Enter the location where you want to insert the element" << endl; 
					
					 //taking row as a input
					cout << "Enter row: "; 
					cin >> row;
					
					//taking column as a input
					cout << "Enter column "; 
					cin >> col;
					
					
					//checking if the row or column entered by the player lies outside the range i.e., from 0 to 9
					if (row > 8 || row < 0 || col < 0 || col > 8) 
						                                                                                         
					{
						cout << "Error! Wrong position entered. Please enter the position again.\n" << endl;
						//skips or jumps out of the condition if the row or column lies outside the range
						continue; 
					}
					// checks if entered row and column lies with in the range 
					if(row==i && col==j) 
					{
						cout<<"Enter your Element"<<endl;
						//inputting element for the specified row and column
						cin>>a[i][j];	
					}
				}
			}
		}
}

