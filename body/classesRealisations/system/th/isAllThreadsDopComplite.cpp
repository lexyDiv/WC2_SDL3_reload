#include "isAllThreadsBasicComplite.cpp"
//=>PWProcess

bool ThData::isAllThreadsDopComplite()
{
    for (int i = 0; i < this->thds->length; i++)
    {
        ThData *th = this->thds->getItem(i);

        if (!th->isDopActiveProgComplite)
        {
            return false;
        }
    }
    return true;
}