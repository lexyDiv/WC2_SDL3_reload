#include "drawTrup.cpp"
//=>out

void Tree::takeDamageByPeon(int damage)
{
    damage_mt.lock();
    this->stress = 6;
    this->hp -= damage;
    if (this->hp <= 0)
    {
       // this->gf->savePushOnTrups(this);
       this->gf->trupsOnDelete.push(this);
    }
    damage_mt.unlock();
}