#ifndef SUDOKU_CLASS_H 
#define SUDOKU_CLASS_H 

namespace s_brd
{
	/*
	 * Cell is a class for each individual cell 
	 * so as to avoid editing system filled cells by the user
	 * 
	 * 
	 * PS: This class will also be useful for graphicss
	 */	
	
	class cell
	{
		private:
			
			/* Number contained within each cell */
				int num;
			
			/* 
			 * Number in the cell editable or not. 
			 * To avoid overwriting system generated (random) numbers.
			 */
				bool editable;
		
		public:
			
			/* Function to set values of each cell object */
			void set_Val(int t_num, bool edit_r_not);
			
			/* Function to get the number in each cell for further use */
			int get_Int();

			/* Function to get the editable property of each cell */
			bool get_Editable();
			
	};

	/*
	 * Class sudoku creates a sudoku board with 9 cells in a row and 9 rows 
	 * that is it has 81 cells in the whole board.
	 */

	class Sudoku 
	{
		private: 
			
			/* To design a 9x9 board for sudoku */
				cell board[9][9]; 
			/* contains the number of cells filled in sudoku */
				int filled; 
			/* contains the number of unfilled or empty cells in sudoku */
				int unfilled; 
		
		public: 
			
			/* Default constructor for creating the board initially */
			Sudoku(); 

			/* Function for checking whether the entered number is repeated or not*/
			int chk_num(int temp_num,int t_row, int t_col);

			bool solveSudoku(cell t_board[9][9]);

			/* Function for initializing the board with random numbers */
			/*void random();*/
			void cell_remover();

			/* Function for getting input for each cell of the sudoku */
			int input();

			/* Function for printing the sudoku board */
			void print_board();

			/* Function for checking the game for completion */
			int	chk_win();
		
	};
}

#endif	/* SUDOKU_CLASS_H */
