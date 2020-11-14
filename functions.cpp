#include <iostream>
#include <string> 
#include <ctime>
#include <random>
#include <chrono>
#include <ratio>

/* Header file for definition of the class Sudoku */
#include "sudoku_class.h"

/* Header file for definition of a player */
#include "player.h"

using namespace std; 
using namespace s_brd;
using namespace user_gm;

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

void shift_three (cell t_board[9][9], int t_row)
{
	for (int t_col = 0; t_col < 9; t_col++)
	{
		t_board[t_row][(t_col+6)%9] = t_board[t_row-1][t_col];
	}
}

void shift_one (cell t_board[9][9], int t_row)
{
	for (int t_col = 0; t_col < 9; t_col++)
	{
		t_board[t_row][(t_col+8)%9] = t_board[t_row-1][t_col];
	}
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
	cout << "\n\tEasy\n";
	cout << "\tMedium\n";
	cout << "\tHard" <<endl;
	cout << "\n" << endl;
	cout << "Your choice: ";		
	getline(cin,Difficulty); 
		
	
    if(Difficulty.compare("Easy") == 0) 
	{			
		filled = 30; 
	}
	else if(Difficulty.compare("Medium") == 0)
	{ 
		
		filled = 25; 
	}
	else if(Difficulty.compare("Hard") == 0)
	{
		
		filled = 20;  
	}
	else
	{
		cout << "Invalid option selected, defaulting to Easy..." << endl;
		filled = 30;
	}

	/*
	 * Initializing the board with valid values
	 * that is initializing every element or cells of the board
	 * so as to have a solved board at the beginning from which 
	 * cells of required amount are unfilled.
	 */

	int rand_num = 0;
	default_random_engine defEngine1(time(0));
	uniform_int_distribution<int> intDistro1(1,9);
	int i = 0;
	while (i < 9)
	{
		rand_num = intDistro1(defEngine1);
		if (chk_num(rand_num,0,i) == -1)
		{
			continue;
		}
		board[0][i].set_Val(rand_num,false);
		i++;
	}
	
	for (int j = 1; j < 9; j++)
	{
		if (j%3 == 0)
		{
			shift_one(board,j);
		}
		else
		{
			shift_three(board,j);
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

	for (i = t_row - (t_row%3); i < row_lim; i++)
	{
		for (j = t_col - (t_col%3); j < col_lim; j++)
		{
			if (temp_num == board[i][j].get_Int())
			{
				return -1;
			}
		}
	}
	return 0;
}

/* Function for initializing the board with random numbers */
/* 
 * This function works as expected though due to some reason
 * unsolvable boards were being made. Set aside for sometime.
 * */
/* void Sudoku::random() 
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
*/

/* 
 * The function to time the puzzle and 
 * check whether the 15 minute limit is crossed or not.
 */
double Player::timer(std::chrono::steady_clock::time_point start)
{
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double,std::milli> t_diff = end-start;
    double differ = t_diff.count() / 1000;
    int minute = 15 - (differ / 60);
    int seconds = 60 - ((int)differ % 60);   
    cout << "\t\t\t\t\t\t\t" << "Time left  " << minute << ":" << seconds << "\n";
    return differ;
}

/* Input function for getting the row ,column and the element*/
int Sudoku::input() 
{
	int row = 0,col = 0, inp_num = 0, err_cd = 0, cnt = 0;
	 string loc, num;

	/* Asking the location of the box in which to enter the number */
	cout << "Enter the location where you want to insert the element in the format (x,y): "; 
	getline(cin,loc);

	if ( loc == " #!Q" || loc == "#!Q" )
	{
		return -1;
	}

	if (loc == "solve" || loc == "Solve")
	{
		if (solveSudoku(this->board))
		{
			print_board();
			exit(0);
		}
		cout << "Unable to solve the board! Exiting..." << endl;
		exit(-1);
	} 

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
		return -2;
	}

	if (board[row][col].get_Editable() == false)
	{
		cout << "Error! This is already filled cell. Please enter the position again.\n" << endl;
		return -2;
	}

	cout << "Enter your Element: ";
	getline(cin,num);

	if ( num == "#!Q" || num == " #!Q" )
	{
		return -1;
	} 
	
	if (num == "solve" || num == "Solve")
	{
		if (solveSudoku(this->board))
		{
			print_board();
			exit(0);
		}
		cout << "Unable to solve the board! Exiting..." << endl;
		exit(-1);
	} 

	if (num == " \n" || num == "\n")
	{
		cout << "Could not recognize the number. Please enter again." << "\n";
		return -2;
	}

	inp_num = stod(num);

	/* Checking the entered number for repetition in row, column or box. */
	err_cd = chk_num(inp_num,row,col);
	if (err_cd == -1)
	{
		cout << "The number you entered at " << "(" << row << "," << col << ")" << " repeats in a row, column or box." << endl;
		return -2;
	}

	/* Inputing the element in the 9 x 9 sudoku board */
	
	board[row][col].set_Val(inp_num,true);
	cout << "Number entered successfully!" << endl; 

	return 0;
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

int Sudoku::chk_win()
{
	int err_chk = 0;

	if (filled != 81)
	{
		return 0;
	}
	
	#ifdef __linux__
        err_chk = system("clear");
    #elif defined(_WIN32)
        err_chk = system("cls");
    #endif

	if (err_chk != 0)
	{
		cerr << "Error! Unable to clear the screen." << endl;
	}

	cout << "\n\n\n\n\t\t\t\tYOU HAVE WON THE GAME! CONGRATULATIONS!" << endl;
	return 1;
}
