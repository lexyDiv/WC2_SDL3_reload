#include "Tree.h"
//=>Shaht

class Mount : public Unit {
    public:
    Mount(){};
    ~Mount(){};
    void create(Cell* cell) override;
    void draw() override;
};