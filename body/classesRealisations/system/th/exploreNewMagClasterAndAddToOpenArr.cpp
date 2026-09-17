#include "createMagistralWay.cpp"
//=>get_GMagistral

void getVCTF(MagistralClaster *son, Array<Cell *> *contactToSonCells, Unit *unit, ThData *td)
{
    son->validCellsToFather.clear();
    contactToSonCells->forEach([unit, td, son](Cell *fc)
                               {
                                           if (fc->thwd.getItemPtr(td->num)->createCountData == td->createCount)
                                           {
                                               fc->aroundCells.forEach([unit, td, son](Cell *sc)
                                                                       {
                Td_way_data * sc_thwd = sc->thwd.getItemPtr(td->num);
                    if (sc_thwd->createCountData != td->createCount &&
                        sc->mc == son &&
                        unit->isNewCellOnGetWayValide(sc, iter)) {
                            sc_thwd->createCountData = td->createCount;
                            son->validCellsToFather.push(sc);
                        } });
                                           } });
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
                int G = 10.F;
                int H = this->get_HMagistral(son, unit->targetData.clicckedCell->mc);

                thwd_mag_son->G = mcFather ? G + mcFather->left->thwd_mag.getItemPtr(this->num)->G : G;
                thwd_mag_son->H = H;
                thwd_mag_son->F = thwd_mag_son->G + thwd_mag_son->H;
                this->openArrMag.push(son);
            }
        }
        else
        {
            console.log("father = " + to_string(mcFather->centralCell->persNum) + " need re father = " + to_string(son->centralCell->persNum));
        }
    }
    // else
    // {
    //     if (son == unit->cell->mc)
    //     {

    //         Array<Td_way_data *> sonCells_thwd;
    //         Array<Cell *> saveSonValidCellsToFather;
    //         saveSonValidCellsToFather.copy(son->validCellsToFather);
    //         son->validCellsToFather.forEach([this, &sonCells_thwd](Cell *c)
    //                                         {
    //             Td_way_data * sonC_thwd = c->thwd.getItemPtr(this->num);
    //             sonC_thwd->createCountData = 0;
    //             sonCells_thwd.push(sonC_thwd); });
    //         getVCTF(son, contactToSonCells, unit, this);
    //         console.log("length = " + to_string(son->validCellsToFather.length));

    //         addToSonValidCellsToFather(unit, this, son);

    //         if (this->magOK) {
    //             console.log("here");
    //         }

    //         if (!son->validCellsToFather.length || !this->magOK)
    //         {
    //             son->validCellsToFather.copy(saveSonValidCellsToFather);
    //             sonCells_thwd.forEach([this](Td_way_data *thwd)
    //                                   { thwd->createCountData = this->createCount; });
    //             console.log("continue");
    //         }

    //         //  if (son->validCellsToFather.length)
    //         // {
    //         //     addToSonValidCellsToFather(unit, this, son);
    //         //     if (this->magOK)
    //         //     {
    //         //         console.log("FINISH HERE 2");
    //         //     }
    //         //     else
    //         //     {
    //         //         son->validCellsToFather.copy(saveSonValidCellsToFather);
    //         //         sonCells_thwd.forEach([this](Td_way_data *thwd)
    //         //                               { thwd->createCountData = this->createCount; });
    //         //         console.log("continue 1");
    //         //     }
    //         // }
    //         // else
    //         // {
    //         //     son->validCellsToFather.copy(saveSonValidCellsToFather);
    //         //     sonCells_thwd.forEach([this](Td_way_data *thwd)
    //         //                           { thwd->createCountData = this->createCount; });
    //         //     console.log("continue 2");
    //         // }
    //     }
    // }
}