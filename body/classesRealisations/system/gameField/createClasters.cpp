#include "trupsControl.cpp"
//=>addClasterOnUpdate

void GameField::createClasters()
{
    int linesCount = (this->gabarit / this->clasterGabarit);

    // console.log("clastarsCount = ", clastersCount);

    int startIndex = (this->clasterGabarit - 1) / 2;
    int step = this->clasterGabarit;
    int length = this->field.length;
    int iterVer = 0;
    int iterHor = 0;
    for (int ver = startIndex; ver < length; ver += step)
    {
        Array<Cell *> &line = this->field.getItemLnk(ver);
        Array<Claster> lineClasters;

        iterHor = 0;
        for (int hor = startIndex; hor < length; hor += step)
        {
            Cell *c = line.getItem(hor);
            Claster claster = Claster(c, this->game, iterVer, iterHor);

            lineClasters.push(claster);

            // Claster *cl = lineClasters.getItem(lineClasters.length - 1);
            // cl->create();
            // // if (iterVer == 1 && iterHor == 1) {
            // cl->getZones();
            // // }

            iterHor++;
        }
        this->clasters.push(lineClasters);
        iterVer++;
    }

    this->clasters.forEach([this](Array<Claster> &line, int ver)
                           { line.forEach([&line, &ver, this](Claster &claster, int hor)
                                          {
                                              claster.create();
                                              claster.getZones();

                                              int maxIndex = line.length - 1;

                                              for (int v = ver - 1; v <= ver + 1; v++)
                                              {
                                                  for (int h = hor - 1; h <= hor + 1; h++)
                                                  {
                                                      if ( 
                                                        v >= 0 && v <= maxIndex && h >= 0 && h <= maxIndex
                                                    )
                                                      {
                                                          Claster *cl = this->clasters.getItemLnk(v).getItemPtr(h);
                                                          if (cl != &claster) {
                                                            claster.aroundClasters.push(cl);
                                                          if (ver == v || hor == h)
                                                          {
                                                              claster.aroundClasters_G.push(10);
                                                          }
                                                          else
                                                          {
                                                              claster.aroundClasters_G.push(15);
                                                          }
                                                          }
                                                      }
                                                  }
                                              } }); });
                                              

    this->clasters.forEach([](Array<Claster> &line, int ver)
                           { line.forEach([&ver](Claster &cl, int hor)
                                          {
                                              cl.zones.forEach([](Zone *z)
                                                               { z->getAroundZones(); });
                                          }); });
}