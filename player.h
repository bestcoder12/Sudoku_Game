#ifndef PLAYER_H
#define PLAYER_H

namespace user_gm
{
    class Player
    {
        private:
            double time_diff;
        
        public:
            /* Function to display the time left in the puzzle */
            void timer(std::chrono::steady_clock::time_point start);

            /* Function to tell the time difference */
            double show_Time ()
            {
                return time_diff;
            }
    };
}

#endif /* PLAYER_H */