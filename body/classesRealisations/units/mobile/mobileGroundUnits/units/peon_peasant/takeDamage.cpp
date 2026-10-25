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
            this->gf->addToTrupsOnDelete(this);
        }
        else if (this->hp > this->hpMax) {
            this->hp = this->hpMax;
        }
    }
    mt.unlock();
}