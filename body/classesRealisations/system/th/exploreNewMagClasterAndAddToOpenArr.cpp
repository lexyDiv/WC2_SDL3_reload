#include "createMagistralWay.cpp"
//=>get_GMagistral

void getVCTF(MagistralClaster *son, Array<Cell *> *contactToSonCells, Unit *unit, ThData *td)
{
    son->validCellsToFather.clear();

    for (int i = 0; i < contactToSonCells->length; i++)
    {
        Cell *fc = contactToSonCells->getItem(i);
        if (fc->thwd.getItemPtr(td->num)->createCountData == td->createCount)
        {
            for (int k = 0; k < fc->aroundCells.length; k++)
            {
                Cell *sc = fc->aroundCells.getItem(k);
                Td_way_data *sc_thwd = sc->thwd.getItemPtr(td->num);
                if (sc_thwd->createCountData != td->createCount &&
                    sc->mc == son &&
                    unit->isNewCellOnGetWayValide(sc, iter))
                {
                    sc_thwd->createCountData = td->createCount;
                    son->validCellsToFather.push(sc);
                }
            }
        }
    }

    // contactToSonCells->forEach([unit, td, son](Cell *fc)
    //                            {
    //                                        if (fc->thwd.getItemPtr(td->num)->createCountData == td->createCount)
    //                                        {
    //                                            fc->aroundCells.forEach([unit, td, son](Cell *sc)
    //                                                                    {
    //             Td_way_data * sc_thwd = sc->thwd.getItemPtr(td->num);
    //                 if (sc_thwd->createCountData != td->createCount &&
    //                     sc->mc == son &&
    //                     unit->isNewCellOnGetWayValide(sc, iter)) {
    //                         sc_thwd->createCountData = td->createCount;
    //                         son->validCellsToFather.push(sc);
    //                     } });
    //                                        }
    //                                     });
}

void ThData::exploreNewMagClasterAndAddToOpenArr(Unit *unit, MagistralClaster *son)
{

    MagistralClaster *mcFather = this->min_F_mc;

    Array<Cell *> *contactToSonCells = nullptr;

    if (son == mcFather->left)
    {
        contactToSonCells = &mcFather->leftVer;
    }
    else if (son == mcFather->right)
    {
        contactToSonCells = &mcFather->rightVer;
    }
    else if (son == mcFather->up)
    {
        contactToSonCells = &mcFather->upHor;
    }
    else if (son == mcFather->down)
    {
        contactToSonCells = &mcFather->downHor;
    }

    Td_way_data_magistral *thwd_mag_father = mcFather->thwd_mag.getItemPtr(this->num);
    Td_way_data_magistral *thwd_mag_son = son->thwd_mag.getItemPtr(this->num);

    if (thwd_mag_son->explored != this->createCount)
    {
        if (thwd_mag_son->createCountData != this->createCount)
        {
            getVCTF(son, contactToSonCells, unit, this);

            if (son->validCellsToFather.length)
            {
                thwd_mag_son->wayFather = mcFather;
                thwd_mag_son->createCountData = this->createCount;
                addToSonValidCellsToFather(unit, this, son);
                // int G = 10.F;
                // int H =
                thwd_mag_son->F = this->get_HMagistral(son, unit->targetData.clicckedCell->mc);

                //  thwd_mag_son->G = G + thwd_mag_father->G;
                //  thwd_mag_son->H = H;
                //  thwd_mag_son->F = G + H; // F = G + H (1)
                this->openArrMag.push(son);
            }
        }
        else
        {
        }
    }
    else
    {
    }
}