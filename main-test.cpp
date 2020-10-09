# include <iostream>
#include <cstdlib>

#ifndef SUDOKU_CLASS_H 
#include "sudoku_class.h"
#endif


using namespace std;

using namespace s_brd;

/*main function for calling the functions */

int main()
{
 Sudoku s;
 //s.rand_init();
 int err_chk = 0;
 /* calling the functions sudoku,input and print */
 for (;;)
 {
    if (err_chk != 0)
    {
    	cout << "Unable to clear the screen." << endl;
    }
    s.print_board();
    s.input();
    for (int i = 0; i < 500000; i++)
    {}
	#ifdef __linux__
		err_chk = system("clear");
	#endif
	#ifdef _WIN32
		err_chk = system("cls");
	#endif
 }	
}
