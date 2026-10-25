#include "getTrees.cpp"
//=>out

void TownHall::takeDamage(int damage)
{
    mutex mt;
    mt.lock();
    this->checkStateNeed = true;
    if (this->hp > 0)
    {
       this->hp -= damage;
       if (this->hp > this->hpMax)
       {
        this->hp = this->hpMax;
       }
      // console.log(this->hp);
    }
    mt.unlock();
}