#include "crox.cpp"
//=>out

bool MobileGroundUnit::isNeedFreeWay() {
    if (this->profession != "" && this->targetData.unit) {
        Cell *finalCell = this->potentialWay.length ? this->potentialWay.getItem(0) : nullptr;
        Unit *tu = finalCell ? finalCell->groundUnit : nullptr;
        if (!tu || tu != this->targetData.unit || !this->potentialWay.length || this->isBlockedd(this)){
            this->iNeedFreeWay = true;
            return true;
        }
    }
    return false;
}