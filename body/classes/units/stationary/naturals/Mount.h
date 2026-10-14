#include "Tree.h"
//=>Shaht

class Mount : public Unit {
    public:
    Mount(){};
    ~Mount(){};
    void create(Cell* cell, bool isComplite) override;
    void draw() override;
};