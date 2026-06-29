#include "in.h"
//=>out

class Tree : public Unit
{
public:
    Tree() {};
    ~Tree() {};
    void create(Cell *cell) override;
    void getContactCells() override;
    void draw() override;
};