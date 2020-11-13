#include <iostream>
#include <chrono>
#include <ratio>

#include "player.h"

using namespace std;

using namespace user_gm;

/* Now what???? */

double Player::timer(std::chrono::steady_clock::time_point start)
{
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double,std::milli> t_diff = end-start;
    double differ = t_diff.count() / 1000;
    int minute = 15 - (differ / 60);
    int seconds = 60 - ((int)differ % 60);   
    cout << "\t\t\t\t\t\t\t" << "Time left  " << minute << ":" << seconds << "\n";
    return differ;
}
