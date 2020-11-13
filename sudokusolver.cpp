#include <random>
#include <ctime>
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


/* Check for repetition in row, column or box */
bool repInGrid(cell t_board[9][9], int temp_num, int t_row, int t_col)
{
	if (temp_num > 9 || temp_num < 1)
	{
		return false;
	}
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
		if (repInGrid(t_board,row, col, num))
		{
        
			t_board[row][col].set_Val(num,true);
         
			if (solveSudoku(t_board))
        	{
           		return true;
        	}
         
        	t_board[row][col].set_Val(-1,true);
      	}
	}
	return false;
}

/* Remove filled numbers from a solved board one at a time to generate the puzzle */
void Sudoku::cell_remover()
{
	std::default_random_engine defEngine(time(0));
	std::uniform_int_distribution<int> intDistro(0,8);
	   
	cell t_board[9][9];
	int c,r,rep_num = 0, i = 0;

	while(i < 81 - filled )
	{
		c = intDistro(defEngine);
		r = intDistro(defEngine);
	  
		rep_num = board[r][c].get_Int();
		board[r][c].set_Val(-1,true);
	      
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				t_board[j][k] = board[j][k];
			}
		}

		if (solveSudoku(t_board))
		{
			i++;
			continue;
		}
	      
		board[r][c].set_Val(rep_num,false);
	}
}