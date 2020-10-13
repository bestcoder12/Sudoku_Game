#include <iostream>
#include <string> 
#include <ctime>

/* Header file for definition of the class Sudoku */
#include "sudoku_class.h"

using namespace std; 
using namespace s_brd;

/* Functions of class cell set_Val, get_Int and get_Editable */

void cell::set_Val(int t_num, bool edit_r_not)
{
	num = t_num;
	editable = edit_r_not;
}

int cell::get_Int()
{
	return num;
}

bool cell::get_Editable()
{
	return editable;
}

/* A Default constructor */
Sudoku::Sudoku() 
{
	/*
	 * Taking a string input for difficulty of the board so as 
	 * to enhance the readablity of the code and to remember 
	 * what value corresponds to which difficulty 
	 */
	
    string Difficulty; 
      
    cout << "Choose the difficulty from one of the below options: "<<endl;
	cout << "\t1. Easy" <<endl;
	cout << "\t2. Medium" <<endl;
	cout << "\t3. Hard" <<endl;
	cout << "\n" << endl;
	cout << "Your choice: ";		
	getline(cin,Difficulty); 
		
	
    if(Difficulty.compare("Easy") == 0) 
	{			
		filled = 45; 
	}
	else if(Difficulty.compare("Medium") == 0)
	{ 
		
		filled = 30; 
	}
	else if(Difficulty.compare("Hard") == 0)
	{
		
		filled = 20;  
	}
	else
	{
		cout << "Invalid option selected, defaulting to Easy...";
		filled = 60;
	}

    /* remaining cells after removing the filled cells i.e the no of unfilled cells */ 
	unfilled = 81-filled;

	/*
	 * Initializing the board with invalid values
	 * that is initializing every element or cells of the board as -1
	 */

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			board[i][j].set_Val(-1,true); 
		}
	}
}		

int Sudoku::chk_num(int temp_num, int t_row, int t_col)
{
	if (temp_num > 9 || temp_num < 1)
	{
		return -1;
	}
	int i = 0, j = 0;
	for (j = 0; j < 9; j++)
	{
		if (temp_num == board[t_row][j].get_Int())
		{
			return -1;
		}
	}
	
	for (i = 0; i < 9; i++)
	{
		if (temp_num == board[i][t_col].get_Int())
		{
			return -1;
		}
	}

	i = t_row - (t_row%3);
	j = t_col - (t_col%3);
	int row_lim = i+3;
	int col_lim = j+3;

	for (; i < row_lim; i++)
	{
		for (; j < col_lim; j++)
		{
			if (temp_num == board[i][j].get_Int())
			{
				return -1;
			}
		}
	}
	return 0;
}

void Sudoku::random() 
{
  srand((unsigned)time(NULL));
  
  int random_no,f,z,s=0;
  int error = 0;
   
	while(s<filled)
	{
		random_no=(rand()%9)+1;
		f=rand()%9;
		z=rand()%9; 
		error = chk_num(random_no,f,z);
	  
	  	if(board[f][z].get_Editable() == true) 
	   	{
			if(error == 0)
			{
				board[f][z].set_Val(random_no,false);
				s++;
	     	}
		}
	}
         
}

/* Input function for getting the row ,column and the element*/
void Sudoku::input() 
{
	int row = 0,col = 0, inp_num = 0, err_cd = 0, cnt = 0;
	 string loc, num;

	/* Asking the location of the box in which to enter the number */
	cout << "Enter the location where you want to insert the element in the format (x,y): "; 
	getline(cin,loc); 

	/* Declaring a string iterator to traverse the string character by character */
	string::iterator it = loc.begin();
	char c_to_num[2];

	for (; *it != ','; it++)
	{
		if (*it == '(' || *it == ' ')
		{
			continue;
		}
		if (cnt > 1)
		{
			break;
		}
		c_to_num[cnt] = *it;
		cnt++;
	}
	row = atoi(c_to_num);
	row -= 1;
	cnt = 0;

	for (; *it != ')'; it++)
	{
		if (*it == ' ' || *it == ',')
		{
			continue;
		}
		if (cnt > 1)
		{
			break;
		}
		c_to_num[cnt] = *it;
		cnt++;
	}
	col = atoi(c_to_num);
	col -= 1;

	if (row > 8 || row < 0 || col < 0 || col > 8) 			                                                                                         
	{
		cout << "Error! Wrong position entered. Please enter the position again.\n" << endl;
		return;
	}

	if (board[row][col].get_Editable() == false)
	{
		cout << "Error! This is already filled cell. Please enter the position again.\n" << endl;
		return;
	}

	cout << "Enter your Element: ";
	getline(cin,num);
	inp_num = stod(num);

	/* Checking the entered number for repetition in row, column or box. */
	err_cd = chk_num(inp_num,row,col);
	if (err_cd == -1)
	{
		cout << "The number you entered at " << "(" << row << "," << col << ")" << " repeats in a row, column or box." << endl;
		return;
	}

	/* Inputing the element in the 9 x 9 sudoku board */
	
	board[row][col].set_Val(inp_num,true);
	cout << "Number entered successfully!" << endl; 

}

/* 
 * This function prints a blank space if the cell has a value of -1 
 * otherwise the number is printed 
 */

void Sudoku::print_board()
{
	for (int i = 0; i < 9; i++)
	{
		cout << "-------------------------------------" << endl;
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j].get_Int() == -1)
			{
				cout << "|" << "   "; 
				
				/*skips or jumps out of the condition if the row or column lies outside the range*/
				continue;
			}
			cout << "| " << board[i][j].get_Int() << " "; 
		}
		cout << "|" << endl;
	}
	cout << "-------------------------------------" << endl;
}
