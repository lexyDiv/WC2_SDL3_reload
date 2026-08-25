#include "createPotentialWay.cpp"
//=>getCurrentTargetCell

// Если клетка находится в открытом списке,
// то сравниваем её значение G со значением G таким,
// что если бы к ней пришли через текущую клетку.
// Если сохранённое в проверяемой клетке значение G больше нового,
// то меняем её значение G на новое,
// пересчитываем её значение F и изменяем указатель на родителя так,
// чтобы она указывала на текущую клетку.

// [3, 1] уже находится в открытом списке,
// поэтому сравниваем её значение F со значением F таким,
// что если бы мы пришли на неё через текущую клетку.
// Это значения 60 и 64, соответственно, а значит, данные проверяемой клетки не нужно обновлять.
// Клетки с индексами [4, 1] и [4, 2] добавляем в открытый список,
// предварительно вычислив их значения величин G, H и F,
// а также установив указатель на родительскую клетку

void ThData::exploreNewCellAndAddToOpenArr(Unit *unit, Cell *fatherCell, Cell *potentialCell)
{
   
    Td_way_data *potentialCell_thwd = potentialCell->thwd.getItemPtr(this->num);
    Td_way_data *fatherCell_thwd = fatherCell->thwd.getItemPtr(this->num);

  if (potentialCell_thwd->explored != this->createCount)
  {
    if (potentialCell_thwd->createCountData == this->createCount)
    {
      int G = this->get_G(fatherCell, potentialCell) + fatherCell_thwd->G;
      int F = G + potentialCell_thwd->H;
      if (potentialCell_thwd->F > F)
      {
        potentialCell_thwd->wayFather = fatherCell;
        potentialCell_thwd->G = G;
        potentialCell_thwd->F = F;
      }
    }
    else if (
        unit->isNewCellOnGetWayValide(potentialCell))
    {
      potentialCell_thwd->wayFather = fatherCell;

      potentialCell_thwd->createCountData = this->createCount;
      int G = this->get_G(fatherCell, potentialCell);
      int H = this->get_H(potentialCell, unit->targetCell);

      potentialCell_thwd->G = fatherCell ? G + fatherCell_thwd->G : G;
      potentialCell_thwd->H = H;
      potentialCell_thwd->F = potentialCell_thwd->G + potentialCell_thwd->H;

      this->openArr.push(potentialCell);
    }
  }
}