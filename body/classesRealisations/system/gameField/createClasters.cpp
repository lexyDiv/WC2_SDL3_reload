#include "trupsControl.cpp"
//=>addClasterOnUpdate

void GameField::createClasters()
{
    int linesCount = (this->gabarit / this->clasterGabarit);

    // console.log("clastarsCount = ", clastersCount);

    this->clasters.reserv(linesCount);

    int startIndex = (this->clasterGabarit - 1) / 2;
    int step = this->clasterGabarit;
    int length = this->field.length;
    int iterVer = 0;
    int iterHor = 0;
    for (int ver = startIndex; ver < length; ver += step)
    {
        Array<Cell *> &line = this->field.getItemLnk(ver);
        Array<Claster *> lineClasters;
        lineClasters.reserv(linesCount);
        iterHor = 0;
        for (int hor = startIndex; hor < length; hor += step)
        {
            Cell *c = line.getItem(hor);
            Claster *claster = new Claster(c, this->game, iterVer, iterHor);

            lineClasters.push(claster);

            Claster *cl = lineClasters.getItem(lineClasters.length - 1);
            cl->create();
            // if (iterVer == 1 && iterHor == 1) {
            cl->getZones();
            // }

            iterHor++;
        }
        this->clasters.push(lineClasters);
        iterVer++;
    }

    this->getAroundClasters(1, false, [](Claster *focusClaster, Claster *pushedClaster)
                            { focusClaster->aroundClasters.push(pushedClaster); });

    this->clasters.forEach([](Array<Claster *> &line, int ver)
                           { line.forEach([&ver](Claster *cl, int hor)
                                          {
         // if (ver == 1 && hor == 1) {
            cl->zones.forEach([](Zone *z){
            z->getAroundZones();
         }
        );
         // } 
        }); });
}