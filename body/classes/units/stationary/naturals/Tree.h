#include "in.h"
//=>Mount

class Tree : public Unit
{
public:
    Tree() {};
    ~Tree() {};
    void create(Cell *cell) override;
    void getContactCells() override;
    void draw() override;
    void stressControl() override;
    void trupCreate() override;
    void drawTrup() override;
    BlockedData blockedCheck(Unit* unit) override;
};

// BlockedData Tree::blockedCheck(Unit *unit) {

//    BlockedData bd;

//    for (int i = 0; i < this->cell->aroundCells.length; i++) {
//     Cell *ac = this->cell->aroundCells.getItem(i);
//      if (ac->plane == this->cell->plane && (!ac->groundUnit || ac->groundUnit == unit)) {
//         break;
//      }
//    }

 
//     return bd;
// }