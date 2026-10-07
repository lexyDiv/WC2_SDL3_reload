#include "getDefaultColor.cpp"
//=>cellsIteration

void GameField::getAroundCells(int wing, bool selfCell, function<void(Cell *focusCell, Cell *cellToPush)> fn)
{
    this->cellsIteration([this, wing, selfCell, fn](Cell *cell)
                         {
      int minVer = cell->ver - wing;
      int maxVer = cell->ver + wing;
      for (int ver = minVer; ver <= maxVer; ver++) {
        int minHor = cell->hor - wing;
        int maxHor = cell->hor + wing;
        for (int hor = minHor; hor <= maxHor; hor++) {
                    if (
            ver >= 0 && 
            ver < this->gabarit &&
            hor >= 0 &&
            hor < this->gabarit) {
                Cell *pushedCell = this->field.getItemLnk(ver).getItem(hor);
                if (!selfCell) {
                    if (cell != pushedCell) {
                    fn(cell, pushedCell);
                    }
                } else {
                   fn(cell, pushedCell);
                }
            }
        }
      } });
}

// void GameField::getAroundClasters(int wing, bool selfCell, function<void(Claster *focusClaster, Claster *clasterToPush)> fn)
// {

//         this->clasterIteration([this, wing, selfCell, fn](Claster *cl)
//                            {
//       int minVer = cl->ver - wing;
//       int maxVer = cl->ver + wing;
//       for (int ver = minVer; ver <= maxVer; ver++) {
//         int minHor = cl->hor - wing;
//         int maxHor = cl->hor + wing;
//         for (int hor = minHor; hor <= maxHor; hor++) {
//                     if (
//             ver >= 0 && 
//             ver < this->clasters.length &&
//             hor >= 0 &&
//             hor < this->clasters.length) {
//                 bool isPush = false;
//                 Claster *pushedClaster = this->clasters.getItemLnk(ver).getItemPtr(hor);
//                 if (!selfCell) {
//                     if (cl != pushedClaster) {
//                       fn(cl, pushedClaster);
//                       isPush = true;
//                     }
//                 } else {
//                    fn(cl, pushedClaster);
//                    isPush = true;
//                 }
//                 if (isPush) {
//                       if (pushedClaster->ver == cl->ver || pushedClaster->hor == cl->hor) 
//                        {
//                          cl->aroundClasters_G.push(10);
//                        } else 
//                        {
//                          cl->aroundClasters_G.push(14);
//                        }
//                 }
//             }
//         }
//       } });
// }