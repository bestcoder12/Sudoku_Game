# include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#ifndef SUDOKU_CLASS_H 
#include "sudoku_class.h"
#endif


using namespace std;

using namespace s_brd;


/*main function for calling the functions */
int main(int argc, char const *argv[])
{
    if (argc != 1)
    {
        cerr << "Usage: ./game\n Or game.exe";    
    }

    Sudoku s;
    s.random();
    int err_chk = 0;
    int ext_cd = 0;
 
    /* calling the functions sudoku,input and print */
    for (;;)
    {
        if (err_chk != 0)
        {
            cerr << "Unable to clear the screen.";
        }
        
        for (int i = 0; i < 500000000; i++) 
        {}
        
        #ifdef __linux__
            err_chk = system("clear");
        #elif defined(_WIN32)
            err_chk = system("cls");
        #endif
        
        s.print_board();
        ext_cd = s.input();
        
        if (ext_cd == -1)
        {
            return -1;
        }

        ext_cd = s.chk_win();

        if (ext_cd == 1)
        {
            break;
        }
    }
    
    return 0;	
}
