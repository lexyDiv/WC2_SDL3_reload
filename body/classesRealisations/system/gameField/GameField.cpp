#include "in.h"
//=> create

// GameField::GameField(string *path, int type)
// {
//     this->path = *path;
//     this->type = type;
// };

void GameField::getPathes(string *path, int type)
{
    this->path = *path;
    this->type = type;
}

GameField::~GameField()
{
    this->planes.forEach([](Plane *plane)
                         {
        delete plane;
        plane = nullptr; });

    this->trupsOnDelete.forEach([this](Unit *u)
                                    {
        if (!u->canGiveTree)
        {
            if (u->canBuild)
            {
               this->game->peonsDelete++;
            }
            delete u;
          //  u = nullptr;
        } });
}