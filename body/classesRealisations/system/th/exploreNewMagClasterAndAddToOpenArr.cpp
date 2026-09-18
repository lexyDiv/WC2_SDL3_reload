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
    ///////////////////
    else if (son == mcFather->upLeft)
    {
        contactToSonCells = &mcFather->upLeftConor;
    }
    else if (son == mcFather->upRight)
    {
        contactToSonCells = &mcFather->upRightConor;
    }
    else if (son == mcFather->downLeft)
    {
        contactToSonCells = &mcFather->downLeftConor;
    }
    else if (son == mcFather->downRight)
    {
        contactToSonCells = &mcFather->downRightConor;
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
                int G = this->get_GMagistral(mcFather, son);
                int H = this->get_HMagistral(son,
                                             // unit->targetCell
                                             unit->targetData.clicckedCell->mc);

                // potentialCell_thwd->last_G = G;
                thwd_mag_son->G = thwd_mag_father->G + G;
                thwd_mag_son->H = H;
                thwd_mag_son->F = thwd_mag_son->G + thwd_mag_son->H; // F = G + H
                this->openArrMag.push(son);
                addToSonValidCellsToFather(unit, this, son);
                // thwd_mag_son->wayFather = mcFather;
                // thwd_mag_son->createCountData = this->createCount;
                // addToSonValidCellsToFather(unit, this, son);

                // int G = this->get_GMagistral(mcFather, son);
                // int H = this->get_HMagistral(son,
                //                              // unit->targetCell
                //                              unit->targetData.clicckedCell->mc);

                // thwd_mag_son->G = thwd_mag_father->G + G;
                // thwd_mag_son->H = H;
                // thwd_mag_son->F = thwd_mag_son->G + thwd_mag_son->H; // F = G + H

                // this->openArrMag.push(son);
            }
        }
        else // => here !!! re way
        {
//             int G = this->get_GMagistral(mcFather, son) + thwd_mag_father->G;
//             // int F = G + potentialCell_thwd->H;
//             if (
//                 thwd_mag_son->G > G)
//             {
//                 console.log("re father");
//                 Array<Cell *> saveOldValideCellsToFather;
//                 saveOldValideCellsToFather.copy(thwd_mag_son->validCellsForWayFather);

//                 son->cells.forEach([this](Cell *cell)
//                                    {
//                     Td_way_data *c_thwd = cell->thwd.getItemPtr(this->num);
//                     c_thwd->createCountData = 0; });

//                 getVCTF(son, contactToSonCells, unit, this);

//                 if (son->validCellsToFather.length)
//                 {
// console.log("re father");
//                     int F = G + thwd_mag_son->H;
//                     thwd_mag_son->wayFather = mcFather;
//                     thwd_mag_son->G = G;
//                     thwd_mag_son->F = F;
//                     addToSonValidCellsToFather(unit, this, son);
//                 }
//                 else
//                 {
//                     console.log("continue");
//                     son->cells.forEach([this](Cell *cell)
//                                        {
//                     Td_way_data *c_thwd = cell->thwd.getItemPtr(this->num);
//                     c_thwd->createCountData = this->createCount; });
//                     thwd_mag_son->validCellsForWayFather.copy(saveOldValideCellsToFather);
//                 }

//                 // int F = G + thwd_mag_son->H;
//                 // thwd_mag_son->wayFather = mcFather;
//                 // thwd_mag_son->G = G;
//                 // thwd_mag_son->F = F;
//             }
        }
    }
    else
    {
    }
}