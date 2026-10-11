#include "byCl_createPW.cpp"
//=>get_G

void ThData::byCl_exploreNewZone(Unit *unit, Zone *fatherZone, Zone *sonZone, int i)
{
    Td_way_data_z *sonZone_thwd = sonZone->thwd.getItemPtr(this->num);
    Td_way_data_z *fatherZone_thwd = fatherZone->thwd.getItemPtr(this->num);

    if (sonZone_thwd->explored != this->createCount)
    {
        if (sonZone_thwd->createCountData == this->createCount)
        {
            int G = this->byCl_get_G(fatherZone, sonZone) + fatherZone_thwd->G;
            int F = G + sonZone_thwd->H;
            if (sonZone_thwd->F > F)
            {
                sonZone_thwd->wayFather = fatherZone;
                sonZone_thwd->G = G;
                sonZone_thwd->F = F;
            }
        }
        else
        //  (
        //     unit->isNewCellOnGetWayValide(potentialCell, this->iter))
        {
            sonZone_thwd->wayFather = fatherZone;

            sonZone_thwd->createCountData = this->createCount;
            int G = this->byCl_get_G(fatherZone, sonZone);
            int H = this->byCl_get_H(sonZone);

            sonZone_thwd->G = fatherZone ? G + fatherZone_thwd->G : G;
            sonZone_thwd->H = H;
            sonZone_thwd->F = sonZone_thwd->G + sonZone_thwd->H;

            this->openArr_z.push(sonZone);
        }
    }
}