#include "Tree.h"
//=>out

class Mount : public Unit {
    public:
    Mount(){};
    ~Mount(){};
    void create(Cell* cell) override;
    void draw() override;
};