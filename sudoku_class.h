#ifndef SUDOKU_CLASS_H 
#define SUDOKU_CLASS_H 

namespace s_brd
{

	/*
	* Class sudoku creates a sudoku board with 9 cells in a row and 9 rows 
	* that is it has 81 cells in the whole board.
	*/

	class Sudoku 
	{
		private: 
			/* To design a 9x9 board for sudoku */
				int board[9][9]; 
			/* contains the number of cells filled in sudoku */
				int filled; 
			/* contains the number of unfilled or empty cells in sudoku */
				int unfilled; 
		
		public: 
			
			// Default constructor for creating the board initially
			Sudoku(); 

			//function for getting input for each cell of the sudoku
			void input();

			// Function for printing the sudoku board
			void print_board();
	};
}

#endif	/* SUDOKU_CLASS_H */
