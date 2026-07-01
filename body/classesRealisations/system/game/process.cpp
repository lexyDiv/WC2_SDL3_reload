#include "preDraw.cpp"
//=>uot

void Game::process()
{
    if (this->isGFComplite)
    {
       // this->objMenu->getCandidateCells();

       // needReturn = true;
        // while (!goWorkReady || !hardReady || !dop_1Ready)
        // {
        // }

       // this->fractionsControl();
       // this->gf->activeShahtsControl();
       // this->isUnitsActiveComplite2 = false;
       // this->isUnitsActiveComplite3 = false;
       // this->isUnitsActiveComplite4 = false;
       // this->unitsActiveZone(this->gf->thread_1_postIndex, false);
        // while (!this->isUnitsActiveComplite2 ||
        //        !this->isUnitsActiveComplite3 ||
        //        !this->isUnitsActiveComplite4)
        // {
        // };
        /////////////////////////////////   => zones 2

        // this->isUnitsActiveComplite5 = false;
        // this->isUnitsActiveComplite6 = false;
        // this->unitsActiveZone(this->gf->thread_2_postIndex, false);
        // while (!this->isUnitsActiveComplite5 ||
        //        !this->isUnitsActiveComplite6)
        // {
        // };

       // this->gf->trupsControl();

        needReturn = false;
       // this->getPotentialWayControl4(startTick, optimalDeltaTime);

       // Uint64 finishTick = SDL_GetTicks();
       // float basicDeltaTime = float(finishTick) - float(*startTick);
        // console.log("delta : " + to_string(basicDeltaTime));
        // tiks.push(basicDeltaTime);
        // if (tiks.length >= 10000) {
        //     tiks.shift();
        // }
        this->preDraw();
      
    }
}