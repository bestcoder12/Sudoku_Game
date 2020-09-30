#include <iostream>
#include <string> 

/* Header file for definition of the class Sudoku */
#include "sudoku_class.h"

using namespace std; 
using namespace s_brd;
	
/* A Default constructor */
Sudoku::Sudoku() 
{
	/* Taking a string input for difficulty of the board so as 
	  to enhance the readablity of the code and to remember 
      what value corresponds to which difficulty */
	
    string Difficulty; 
      
    cout << "Enter the level of difficulty: "<<endl;
	cout << "\t1. Easy" <<endl;
	cout << "\t2. Medium" <<endl;
	cout << "\t3. Hard" <<endl;
			
	getline(cin,Difficulty); 
		
	
    if(Difficulty.compare("Easy") == 0) 
	{			
		filled = 60; 
	}
	else if(Difficulty.compare("Medium") == 0)
	{ 
		
		filled = 50; 
	}
	else if(Difficulty.compare("Hard") == 0)
	{
		
		filled = 40;  
	}
	else
	{
		
		filled = 60; 
	}

    /* remaining cells after removing the filled cells i.e the no of unfilled cells */ 
	unfilled = 81-filled;

	/* Initializing the board with invalid values
    that is initializing every element or cells of the board as -1 */
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = -1; 
		}
	}
}		
		

/* Input function for getting the row ,column and the element*/
void Sudoku::input() 
{
	
	/*inputing elements in the 9 x 9 sudoku or board */
	for(i=0;i<10;i++) 
	{
	    for(j=0;j<10;j++)
		{
			cout << "Enter the location where you want to insert the element" << endl; 
			cout << "Enter row: "; 
			cin >> row;
					
			cout << "Enter column "; 
			cin >> col;
					
		
			if (row > 8 || row < 0 || col < 0 || col > 8) 			                                                                                         
			{
				cout << "Error! Wrong position entered. Please enter the position again.\n" << endl;
				
				/*skips or jumps out of the condition if the row or column lies outside the range*/
				continue; 
			}
			
			if(row==i && col==j) 
			{
			    cout<<"Enter your Element"<<endl;
				cin>>a[i][j];	
			}
		}
	} 
}
