#include <iostream>
#include <ctime>

#include "player.h"

using namespace std;

using namespace user_gm;

/* Now what???? */
double diff;

double Player::timer(time_t start)
{
    time_t now = time(NULL);
    double differ = difftime(now,start);
    int minute = 15 - (differ / 60);
    int seconds = 60 - ((int)differ % 60);   
    cout << "\t\t\t\t\t\t\t" << "Time left  " << minute << ":" << seconds << "\n";
    return differ;
    diff=differ;
}
