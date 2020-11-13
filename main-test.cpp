#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>

#ifdef __linux__
    #include <unistd.h>
#elif defined (_WIN32)
    #include <windows.h>
#endif

#ifndef SUDOKU_CLASS_H 
    #include "sudoku_class.h"
#endif

#ifndef PLAYER_H
    # include "player.h"
#endif

using namespace std;

using namespace user_gm;

using namespace s_brd;


/*main function for calling the functions */
int main(int argc, char const *argv[])
{
    if (argc != 1)
    {
        cerr << "Usage: ./game\n Or game.exe\n"; 
        return -2;
    }

    int err_chk = 0;

    #ifdef __linux__
        err_chk = system("clear");
    #elif defined(_WIN32)
        err_chk = system("cls");
    #endif

    Sudoku s;
    s.random();
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    int ext_cd = 0;
    double time_diff = 0.0;
    Player p1;
    
    /* calling the functions sudoku,input and print */
    for (;;)
    {
        if (err_chk != 0)
        {
            cerr << "Unable to clear the screen.";
        }
    
        #ifdef __linux__
            sleep(2);
        #elif defined (_WIN32)
            sleep(2000);
        #endif

        #ifdef __linux__
            err_chk = system("clear");
        #elif defined(_WIN32)
            err_chk = system("cls");
        #endif

        time_diff = p1.timer(start);
        if (time_diff > 900.0)
        {
            cout << "Game lost!" << endl;
            break;
        }
        
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
