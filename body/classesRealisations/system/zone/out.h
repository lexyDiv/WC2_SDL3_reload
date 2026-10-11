#include "checkContactUnits.cpp"
//=> cell in

void Zone::checkContactUnits()
{
    this->buildingsNear.clear();
    this->isTeesNear = false;
    this->cl->td->createCount += 0.001;
    this->cells.forEach([this](Cell *c)
                        { c->aroundCells.forEach([this](Cell *ac)
                                                 {
                          if (ac->groundUnit) 
                     {
                      Td_xploredData *td_exp = ac->groundUnit->thwd.length ? 
                      ac->groundUnit->thwd.getItemPtr(this->cl->td->num)
                      : nullptr;
                      if (
                          ac->groundUnit->canGiveTree &&
                          ac->groundUnit->hp > 0
                        ) 
                      {
                        this->isTeesNear = true;  
                      } else if (td_exp &&
                                 td_exp->explored != this->cl->td->createCount) {
                              td_exp->explored = this->cl->td->createCount;
                              this->buildingsNear.push(ac->groundUnit);
                      }  
                     } }); });
}