#include "byCl_potentialWayCreate.cpp"
//=>out

void ThData::getSuccessLambda(Unit *unit)
{

    this->successWay = [](Zone *z)
    {
        return false;
    };

    TargetData *td = &unit->targetData;
    if (td->unit)
    {
        if (td->unit->name == "tree")
        {
            this->successWay = [this](Zone *z)
            {
                if (z->isTeesNear)
                {
                    return true;
                }
                return false;
            };
        } else if (td->unit->type == "building") {
            
        }
    }
}