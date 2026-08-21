#include "in.h"
//=>out

    void  ThData::process()
    {

        while (!quit)
        {

            if (!this->num && !this->game->isGFComplite)
            {
                this->game->create();
            }

            this_thread::sleep_for(chrono::nanoseconds(1));
        }
    }