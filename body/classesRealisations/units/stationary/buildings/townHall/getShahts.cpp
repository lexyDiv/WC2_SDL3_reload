#include "wellCome.cpp"
//=>getTrees

void TownHall::getShahts()
{
    Array<CellDis> shahtsData;
    this->cell->plane->shahts.forEach([&shahtsData, this](Unit *shaht)
                                      {
        CellDis cd;
       PointF pointThis = {x : this->cell->x, y : this->cell->y};
       PointF pointLM = {x : shaht->cell->x, y : shaht->cell->y};
       Delta delta = getDeltas(&pointThis, &pointLM);
       double dis = getDis(&delta); 
       cd.unit = shaht;
       cd.dis = dis;
       shahtsData.push(cd); });
    shahtsData.sort([](CellDis a, CellDis b)
                    { return a.dis < b.dis; });
    this->orderedShahts = shahtsData.mapU([](CellDis cd)
                                         { return cd.unit; });
}