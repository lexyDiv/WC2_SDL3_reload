#include "byCl_exploreNewZone.cpp"
//=>get_H

int ThData::byCl_get_G(Zone *fatherZone, int index){ // 10/ 14
    int res = fatherZone->cl->aroundClasters_G.getItem(index);
    return res;
}