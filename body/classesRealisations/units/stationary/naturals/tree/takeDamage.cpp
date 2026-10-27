#include "drawTrup.cpp"
//=>out

void Tree::takeDamage(int damage)
{
    this->stress = 6;
    this->hp -= damage;
    if (this->hp <= 0)
    {
        this->gf->savePushOnTrups(this);
    }
}