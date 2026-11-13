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
        Unit *boo = new BuildingBoo;
        boo->create(this->x - 80, this->y - 150, 400, 400, this);
        this->gf->trupsOnDelete.push(boo);
       }
    }
    damage_mt.unlock();
}