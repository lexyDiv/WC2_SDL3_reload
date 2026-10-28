#include "getTrees.cpp"
//=>trupCreate

void TownHall::takeDamage(int damage)
{
    damage_mt.lock();
    this->checkStateNeed = true;
    if (this->hp > 0)
    {
       this->hp -= damage;
       if (this->hp > this->hpMax)
       {
        this->hp = this->hpMax;
       }
       else if (this->hp <= 0)
       {
        this->hp = 0;
        this->gf->trupsOnDelete.push(this);
        //this->gf->addToTrupsOnDelete(this);
       }
    }
    damage_mt.unlock();
}