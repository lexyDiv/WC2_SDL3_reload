#include "createMyActiveProgZone.cpp"
//=>isAllThreadsDopComplite

bool ThData::isAllThreadsBasicComplite()
{
    for (int i = 0; i < this->thds->length; i++)
    {
       
        ThData *th = this->thds->getItem(i);
     

        if (!th->isBasicActiveProgComplite)
        {
            return false;
        }
    }
    return true;
}