#include "isNeedHoldGoWay.cpp"
//=>drawTrup

void Peon_peasant::takeDamage(int damage)
{
    mutex mt;
    mt.lock();
    if (this->hp > 0 && !this->inSave)
    {
        this->hp -= damage;
        if (this->hp <= 0) {
            this->hp = 0;
            this->iNeedFreeWay = false;
            Trace *t = this->fraction->nation->getTraceFromBuffer(this->bufferIndex) ;
            if (!t)
            {
               t = new PeonTrace;
               this->game->addToAllTracesPtr(t);
            }
            // else {
            //     console.log("this trace from buffer = ", t->readyToOut);
            // }

            t->create(0, 0, 0, 0, this);
            this->gf->addToTraces(t);
            // console.log("======================");
            // console.log("length = ", this->gf->traces.length);
            // console.log("readyToOut = ", this->gf->traces.getItem(0)->readyToOut);


           // Trace t = PeonTrace();
           // t.create(0, 0, 0, 0, this);
           // this->gf->addToTraces(t);
          //  Trace *t_ptr = this->gf->traces.getItemPtr(this->gf->traces.length - 1);
           // t_ptr->create(0, 0, 0, 0, this);
            //this->gf->addToTrupsOnDelete(this);
        }
        else if (this->hp > this->hpMax) {
            this->hp = this->hpMax;
        }
    }
    mt.unlock();
}