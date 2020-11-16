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

    /* Board is contained within the Sudoku class */
    Sudoku game_Board;
    game_Board.cell_remover();
    
    int ext_cd = 0;

    /* Player class used to conceptualize the idea of time taken by the user */
    Player p1;
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    
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
            Sleep(2000);
        #endif

        #ifdef __linux__
            err_chk = system("clear");
        #elif defined(_WIN32)
            err_chk = system("cls");
        #endif

        p1.timer(start);
        
        if (p1.show_Time() > 900.0)
        {
            cout << "Game lost!" << endl;
            exit(-1);
        }

        game_Board.print_board();
        ext_cd = game_Board.input();
        
        if (ext_cd == -1)
        {
            return -1;
        }

        ext_cd = game_Board.chk_win();

        if (ext_cd == 1)
        {
            break;
        }
    }
    
    return 0;	
}
