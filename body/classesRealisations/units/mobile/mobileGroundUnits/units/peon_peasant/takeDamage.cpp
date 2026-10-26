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
            Trace t = PeonTrace();
           // t.create(0, 0, 0, 0, this);
            this->gf->addToTraces(t);
            Trace *t_ptr = this->gf->traces.getItemPtr(this->gf->traces.length - 1);
            t_ptr->create(0, 0, 0, 0, this);
            //this->gf->addToTrupsOnDelete(this);
        }
        else if (this->hp > this->hpMax) {
            this->hp = this->hpMax;
        }
    }
    mt.unlock();
}