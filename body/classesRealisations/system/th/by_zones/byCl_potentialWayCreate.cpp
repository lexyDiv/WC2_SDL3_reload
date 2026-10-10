#include "byCl_get_H.cpp"
//=>getSuccessLambda

void ThData::byCl_potentialWayCreate(Unit *unit, Zone *finalZone)
{

  // Cell *nextCell = finalCell;
  Zone *nextZone = finalZone;
  TargetData &td = unit->targetData;
  // unit->way.push(nextCell);
  int tt = 0;
  if (!td.unit)
  {
    td.magistral.push(td.clicckedCell);
  }
  //  else if (td.unit->canGiveTree) {
  //       td.magistral.push(td.unit->cell);
  // }

  while (true)
  {
    tt++;
    if (tt >= 3000)
    {
      console.log("create LOOP, iter = ", iter);
      // console.log("wayFather->isActive = ", nextZone->thwd.getItemPtr(this->num)->wayFather->isActive);
      // console.log("wayFather num = ", nextZone->thwd.getItemPtr(this->num)->wayFather->num);
      // console.log("wayFather claster num = ", nextZone->thwd.getItemPtr(this->num)->wayFather->cl->num);
      // console.log("wayFather cl isUpdated = ", nextZone->thwd.getItemPtr(this->num)->wayFather->cl->isUpdated);
      // console.log("wayFather cl isTouch = ", nextZone->thwd.getItemPtr(this->num)->wayFather->cl->isTouchUpdated);
      // console.log("------------------------------------------------------------------");

      // this->game->gf->focusClaster = nextZone->thwd.getItemPtr(this->num)->wayFather->cl;

      return;
    }
    //  iter++;
    if (nextZone->thwd.getItemPtr(this->num)->wayFather &&
        nextZone->thwd.getItemPtr(this->num)->wayFather != unit->cell->zone)
    {
      nextZone = nextZone->thwd.getItemPtr(this->num)->wayFather;
      // unit->way.push(nextCell);
      td.magistral.push(nextZone->cell);
    }
    else
    {
      td.magistral.push(unit->cell);
      unit->isPotentialWayComplite = true;
      break;
    }
  }

  // td.magistral.push(unit->cell);
  if (td.magistral.length >= 3)
  {
    td.prevCell = td.magistral.getItem(td.magistral.length - 1);
    td.nextCell = td.magistral.getItem(td.magistral.length - 2);
    td.nextCellIndex = td.magistral.length - 2;
    td.isZones = true;
    // td.isNeedClasterMagistral = false;
    // console.log("Create Claster = ", iter);
  }
  else
  {
    td.magistral.clear();
  }

  if (unit->focus)
  {
    console.log("in magistral ", td.magistral.length);
    console.log("zone way iter = ", iter);
    console.log("-----------------------------------------------------");
  }

  // unit->way.push(unit->cell->aroundCells.getItem(0));
  //  console.log("iter = ", iter);

  // console.log("zone way length = ", unit->targetData.magistral.length);
  // console.log("zone way iter = ", iter);
  //    console.log("------------------------------------------------------");
}