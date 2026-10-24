#include "Tree.h"
//=>Shaht

class Mount : public Unit {
    public:
    Mount(){};
    ~Mount(){};
    void create(Cell* cell, bool isComplite, bool isNew) override;
    void draw() override;
};