#include <iostream>
#include <ctime>

#include "player.h"

using namespace std;

using namespace user_gm;

/* Now what???? */

double Player::timer(time_t start)
{
    time_t now = time(NULL);
    double differ = difftime(now,start);
    int minute = differ / 60;
    int seconds = (int)differ % 60;   
    cout << "\t\t\t\t\t\t\t" << "Time played  " << minute << ":" << seconds << "\n";
    return differ;
}