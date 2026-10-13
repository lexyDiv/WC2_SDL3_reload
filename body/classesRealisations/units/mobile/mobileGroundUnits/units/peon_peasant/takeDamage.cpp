#include "isNeedHoldGoWay.cpp"
//=>drawTrup

void Peon_peasant::takeDamage(int damage)
{
    mutex mt;
    mt.lock();
    if (this->hp > 0)
    {
        this->hp -= damage;
        if (this->hp <= 0) {
            this->hp = 0;
            this->gf->addToTrupsOnDelete(this);
        }
    }
    mt.unlock();
}