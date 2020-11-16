#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

#include "sudoku_class.h"

using namespace s_brd;

/* get empty location and update row and column */
bool findEmptyPlace(cell t_board[9][9],int &row, int &col)
{ 
	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			if (t_board[row][col].get_Int() == -1) 
			{
				return true;
			}
		}
	}
	return false;
}


/* Check for repetition in row, column or box (function similar to chk_num)*/
bool safetyInGrid(cell t_board[9][9], int temp_num, int t_row, int t_col)
{
	int i = 0, j = 0;
	
	for (j = 0; j < 9; j++)
	{
		if (temp_num == t_board[t_row][j].get_Int())
		{
			return false;
		}
	}
	
	for (i = 0; i < 9; i++)
	{
		if (temp_num == t_board[i][t_col].get_Int())
		{
			return false;
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
			if (temp_num == t_board[i][j].get_Int())
			{
				return false;
			}
		}
	}
	return true;
}

/* Function to solve the given board if needed. */
bool Sudoku::solveSudoku(cell t_board[9][9])
{
	int row, col;
   
	/* If true all the cells are filled and the game is complete */
   	if (!findEmptyPlace(t_board,row,col))
	{
		return true;
   	}
  
	for (int num = 1; num <= 9; num++)
	{
		if (safetyInGrid(t_board, num, row, col))
		{
        
			this->board[row][col].set_Val(num,false);
         
			if (solveSudoku(t_board))	
        	{
           		return true;
        	}
         
        	this->board[row][col].set_Val(-1,true);
      	}
	}
	return false;
}

/* Generates the random number for random_shuffle function */
int genRandNum (int Max)
{
	return rand()%Max;
}

void Sudoku::init_gridPos()
{
	srand(time(0));
	for (int i = 0; i < 81; i++)
	{
		this->gridPos[i] = i;
	}
	std::random_shuffle (this->gridPos, (this->gridPos)+81, genRandNum);
}

void Sudoku::count_Sols (int &num)
{
	int row, col;
	if (!findEmptyPlace(this->board, row, col))
	{
		num++;
		return;
	}
	std::default_random_engine defEngine(time(0));
	std::uniform_int_distribution<int> intDistro(1,9);
	int randNum = 0;

	for (int i = 0; i < 9 && num < 2; i++)
	{
		randNum = intDistro(defEngine);
		if (safetyInGrid(this->board,randNum,row,col))
		{
			this->board[row][col].set_Val(randNum,false);
			count_Sols(num);
		}

		this->board[row][col].set_Val(-1,true);
	}

}

/* Remove filled numbers from a solved board one at a time to generate the puzzle */
void Sudoku::cell_remover()
{	
	this->init_gridPos();
	for (int i = 0; i < 81; i++)
	{
		int x = gridPos[i]/9;
		int y = gridPos[i]%9;
		int temp_num = this->board[x][y].get_Int();
		this->board[x][y].set_Val(-1,true);

		int numSols = 0;
		count_Sols(numSols);

		if (numSols != 1)
		{
			this->board[x][y].set_Val(temp_num,false);
		}
	}
}