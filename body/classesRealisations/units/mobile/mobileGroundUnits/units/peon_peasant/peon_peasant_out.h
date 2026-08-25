#include "trupCreate.cpp"
//=>units_out

Unit * Peon_peasant::getBaseForUnloading() {
        Array<Unit *> mix;
    this->fraction->fLamberMill.lamberMills.forEach([&mix, this](Unit *lm)
                                                    { mix.push(lm); });
    this->fraction->fTownHoll.townHolls.forEach([&mix, this](Unit *th)
                                                { mix.push(th); });
    if (mix.length)
    {
        mix.filterSelf([this](Unit * base){
            return base->isBlockedd(this);
        });
        MinData md = mix.getMinDataU([this](Unit *item)
                                    {
                                                        PointF pointThis = {x : this->cell->x, y : this->cell->y};
                                                        PointF pointLM = {x : item->cell->x, y : item->cell->y};
                                                        Delta delta = getDeltas(&pointThis, &pointLM);
                                                        double dis = getDis(&delta);
                                                        return dis; });
        Unit *minDisBase = md.unit;
        return minDisBase;
    }
    return nullptr;
}