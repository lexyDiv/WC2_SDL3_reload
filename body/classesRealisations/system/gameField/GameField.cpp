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

GameField::~GameField() {
  
}