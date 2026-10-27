#include "isNeedHoldGoWay.cpp"
//=>drawTrup

void Peon_peasant::takeDamage(int damage)
{
    damage_mt.lock();
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
               this->game->tracesCount++;
            }


            t->create(0, 0, 0, 0, this);
            this->gf->addToTraces(t);




        }
        else if (this->hp > this->hpMax) {
            this->hp = this->hpMax;
        }
    }
    damage_mt.unlock();
}