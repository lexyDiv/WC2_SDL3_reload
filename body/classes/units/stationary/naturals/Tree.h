#include "in.h"
//=>Mount

class Tree : public Unit
{
public:
    Tree() {};
    ~Tree() {};
    void create(Cell *cell, bool isComplite, bool isNew) override;
    void getContactCells() override;
    void draw() override;
    void stressControl() override;
    void trupCreate() override;
    void drawTrup() override;
    void takeDamageByPeon(int) override;
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