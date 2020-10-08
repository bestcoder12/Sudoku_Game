# include <iostream>

#ifndef SUDOKU_CLASS_H 
#include "sudoku_class.h"
#endif


using namespace std;

using namespace s_brd;

/*main function for calling the functions */

int main()
{
 Sudoku s;
 s.rand_init();
 /* calling the functions sudoku,input and print */
 for (;;)
 {
    s.print_board();
    s.input();
 }	
}
