#ifndef PLAYER_H
#define PLAYER_H

namespace user_gm
{
    class Player
    {
        private:
            int high_score;
            int gm_won;
            int gm_lost;

        
        public:
            /* Function to display the time left in the puzzle */
            double timer(std::chrono::steady_clock::time_point start);
    };
}

#endif /* PLAYER_H */