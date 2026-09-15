#include "createMagistralWay.cpp"
//=>get_GMagistral

void ThData::exploreNewMagClasterAndAddToOpenArr(Unit *unit, MagistralClaster *mcFather)
{
    // mcFather->thwd_mag.getItemPtr(this->num)->explored = this->createCount; => Here or not ???

    MagistralClaster *left = mcFather->left &&
                                     mcFather->left->thwd_mag.getItemPtr(this->num)->createCountData != this->createCount &&
                                     mcFather->left->thwd_mag.getItemPtr(this->num)->explored != this->createCount
                                 ? mcFather->left
                                 : nullptr;
    if (left)
    {
        Td_way_data_magistral *thwd_magLeft = left->thwd_mag.getItemPtr(this->num);

        thwd_magLeft->validCellsForWayFather.clear();

        mcFather->leftVer.forEach([this, left, thwd_magLeft](Cell *c)
                                  {           
            if (c && c->thwd.getItemPtr(this->num)->createCountData == this->createCount ) {
                
                 c->aroundCells.forEach([&left, this, thwd_magLeft](Cell *ac){
                    if (ac->mc == left &&
                        !ac->groundUnit &&
                        ac->thwd.getItemPtr(this->num)->createCountData != this->createCount
                    ) {
                        thwd_magLeft->validCellsForWayFather.push(ac);
                        ac->thwd.getItemPtr(this->num)->createCountData = this->createCount;
                    }
                 });
            } });

        if (thwd_magLeft->validCellsForWayFather.length)
        {
            thwd_magLeft->wayFather = mcFather;
            thwd_magLeft->createCountData = this->createCount;
            veerArr(thwd_magLeft->validCellsForWayFather, this->createCount, this->num);
            this->openArrMag.push(left);

            //////////////////////////////////////

            int G = this->get_GMagistral();
            int H = this->get_HMagistral(left, unit->targetData.clicckedCell->mc);

            thwd_magLeft->G = mcFather ? G + mcFather->left->thwd_mag.getItemPtr(this->num)->G : G;
            thwd_magLeft->H = H;
            thwd_magLeft->F = thwd_magLeft->G + thwd_magLeft->H;

            /////////////////////////////////////
        }
    }
    ////////////////////////////////////////////////////////////////////////

    MagistralClaster *right = mcFather->right &&
                                      mcFather->right->thwd_mag.getItemPtr(this->num)->createCountData != this->createCount &&
                                      mcFather->right->thwd_mag.getItemPtr(this->num)->explored != this->createCount
                                  ? mcFather->right
                                  : nullptr;
    if (right)
    {
        Td_way_data_magistral *thwd_magRight = right->thwd_mag.getItemPtr(this->num);
        thwd_magRight->validCellsForWayFather.clear();

        mcFather->rightVer.forEach([this, right, thwd_magRight](Cell *c)
                                   {           
            if (c && c->thwd.getItemPtr(this->num)->createCountData == this->createCount ) {
                
                 c->aroundCells.forEach([&right, this, thwd_magRight](Cell *ac){
                    if (ac->mc == right &&
                        !ac->groundUnit &&
                        ac->thwd.getItemPtr(this->num)->createCountData != this->createCount
                    ) {
                        thwd_magRight->validCellsForWayFather.push(ac);
                        ac->thwd.getItemPtr(this->num)->createCountData = this->createCount;
                    }
                 });
            } });

        if (thwd_magRight->validCellsForWayFather.length)
        {
            thwd_magRight->wayFather = mcFather;
            thwd_magRight->createCountData = this->createCount;
            veerArr(thwd_magRight->validCellsForWayFather, this->createCount, this->num);
            this->openArrMag.push(right);
            //////////////////////////////////////

            int G = this->get_GMagistral();
            int H = this->get_HMagistral(right, unit->targetData.clicckedCell->mc);

            thwd_magRight->G = mcFather ? G + mcFather->right->thwd_mag.getItemPtr(this->num)->G : G;
            thwd_magRight->H = H;
            thwd_magRight->F = thwd_magRight->G + thwd_magRight->H;

            /////////////////////////////////////
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////

    MagistralClaster *up = mcFather->up &&
                                   mcFather->up->thwd_mag.getItemPtr(this->num)->createCountData != this->createCount &&
                                   mcFather->up->thwd_mag.getItemPtr(this->num)->explored != this->createCount
                               ? mcFather->up
                               : nullptr;
    if (up)
    {
        Td_way_data_magistral *thwd_magUp = up->thwd_mag.getItemPtr(this->num);
        thwd_magUp->validCellsForWayFather.clear();

        mcFather->upHor.forEach([this, up, thwd_magUp](Cell *c)
                                {           
            if (c && c->thwd.getItemPtr(this->num)->createCountData == this->createCount ) {
                
                 c->aroundCells.forEach([&up, this, thwd_magUp](Cell *ac){
                    if (ac->mc == up &&
                        !ac->groundUnit &&
                        ac->thwd.getItemPtr(this->num)->createCountData != this->createCount
                    ) {
                        thwd_magUp->validCellsForWayFather.push(ac);
                        ac->thwd.getItemPtr(this->num)->createCountData = this->createCount;
                    }
                 });
            } });

        if (thwd_magUp->validCellsForWayFather.length)
        {
            thwd_magUp->wayFather = mcFather;
            thwd_magUp->createCountData = this->createCount;
            veerArr(thwd_magUp->validCellsForWayFather, this->createCount, this->num);
            this->openArrMag.push(up);
            //////////////////////////////////////

            int G = this->get_GMagistral();
            int H = this->get_HMagistral(up, unit->targetData.clicckedCell->mc);

            thwd_magUp->G = mcFather ? G + mcFather->up->thwd_mag.getItemPtr(this->num)->G : G;
            thwd_magUp->H = H;
            thwd_magUp->F = thwd_magUp->G + thwd_magUp->H;

            /////////////////////////////////////
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////
    MagistralClaster *down = mcFather->down &&
                                     mcFather->down->thwd_mag.getItemPtr(this->num)->createCountData != this->createCount &&
                                     mcFather->down->thwd_mag.getItemPtr(this->num)->explored != this->createCount
                                 ? mcFather->down
                                 : nullptr;
    if (down)
    {
        Td_way_data_magistral *thwd_magDown = down->thwd_mag.getItemPtr(this->num);
        thwd_magDown->validCellsForWayFather.clear();

        mcFather->downHor.forEach([this, down, thwd_magDown](Cell *c)
                                  {           
            if (c && c->thwd.getItemPtr(this->num)->createCountData == this->createCount ) {
                
                 c->aroundCells.forEach([&down, this, thwd_magDown](Cell *ac){
                    if (ac->mc == down &&
                        !ac->groundUnit &&
                        ac->thwd.getItemPtr(this->num)->createCountData != this->createCount
                    ) {
                        thwd_magDown->validCellsForWayFather.push(ac);
                        ac->thwd.getItemPtr(this->num)->createCountData = this->createCount;
                    }
                 });
            } });

        if (thwd_magDown->validCellsForWayFather.length)
        {
            thwd_magDown->wayFather = mcFather;
            thwd_magDown->createCountData = this->createCount;
            veerArr(thwd_magDown->validCellsForWayFather, this->createCount, this->num);
            this->openArrMag.push(down);
                        //////////////////////////////////////

            int G = this->get_GMagistral();
            int H = this->get_HMagistral(down, unit->targetData.clicckedCell->mc);

            thwd_magDown->G = mcFather ? G + mcFather->down->thwd_mag.getItemPtr(this->num)->G : G;
            thwd_magDown->H = H;
            thwd_magDown->F = thwd_magDown->G + thwd_magDown->H;

            /////////////////////////////////////
        }
    }
}