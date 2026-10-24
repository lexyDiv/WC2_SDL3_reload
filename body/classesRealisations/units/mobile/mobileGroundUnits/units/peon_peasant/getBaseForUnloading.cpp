#include "inFightAnimation.cpp"
//=>trupCreate

Unit *Peon_peasant::getBaseForUnloading()
{
    Array<Unit *> mix;
    this->fraction->fLamberMill.lamberMills.forEach([&mix, this](Unit *lm)
                                                    {
                                                         if (lm->hp > 0 &&
                                                             lm->cell->plane == this->cell->plane) {
                                                                mix.push(lm);
                                                             } });
    this->fraction->fTownHoll.townHollsByLevel.forEach([&mix, this](Array<Unit *> &thblarr)
                                                       { thblarr.forEach([&mix, this](Unit *thbl)
                                                                    { 
                                            if (thbl->hp > 0 &&
                                                thbl->cell->plane == this->cell->plane) {
                                                    mix.push(thbl);
                                                } }); });

    if (mix.length)
    {

        MinData md = mix.getMinDataU([this](Unit *item)
                                     {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : item->cell->x, y : item->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = getDis(&delta);
                                                        return dis; });

        // int rand = intRand(0, mix.length);
        // Unit *rBase = mix.getItem(rand);

        Unit *minDisBase =
            // rBase;
            md.unit;
        return minDisBase;
    }
    return nullptr;
}