#ifndef SUDOKU_CLASS_H 
#define SUDOKU_CLASS_H 

namespace s_brd
{
	/*
	 * Cell is a class for each individual cell 
	 * so as to avoid editing system filled cells by the user
	 * 
	 * PS: This class will also be useful for graphicss
	 */	
	class cell
	{
		private:
			int num;
			bool editable;
		
		public:
			void set_Val(int t_num, bool edit_r_not)
			{
				num = t_num;
				editable = edit_r_not;
			}
			int get_int()
			{
				return num;
			}
			bool get_editable()
			{
				return editable;
			}
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

			//function for getting input for each cell of the sudoku
			void input();

			// Function for printing the sudoku board
			void print_board();

			// Function for initializing board with random numbers
			//void rand_init();

	};
}

#endif	/* SUDOKU_CLASS_H */
