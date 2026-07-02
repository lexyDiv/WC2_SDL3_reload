#include "getToOtherPlaneCellsNumber.cpp"
//=>getVectorCells

void GameField::getToTreeCellLineNumber()
{
    console.log("getToTreeCellLineNumber");

    this->field.forEach([this](Array<Cell *> &line)
                        { line.forEach([this](Cell *cell)
                                       { this->getVectorCells(cell); }); });

    this->planes.forEach([this](Plane *plane)
                         {
                           
                             if (plane->type == "ground")
                            {

                                Array<Cell *> arr;
                                Array<Cell *> arrAroundDarck;
                                Array<Cell *> arrStones;
                                Array<Cell *> shahts;
                                
                                 
                                  plane->cells.forEach([plane, &arr, &arrStones, &arrAroundDarck, &shahts](Cell *cell)
                                                      {  
                               
                if (cell->litera == 't') {
                    Unit *tree = new Tree;
                    tree->create(cell);
                    cell->aroundCells.forEach([plane, &arr](Cell* ac){
                        if (ac->plane == plane &&
                        ac->litera != 't' && ac->litera != '1' &&
                        !ac->lineToTreeNumber) {
                            ac->lineToTreeNumber = 1;
                            arr.push(ac);  
                        }
                    }); 
                } 
    //            if (cell->litera == 'S') {
    //                 shahts.push(cell);
    //            }
                                   if (cell->litera == 'g') {
                        arrStones.push(cell);
                        Unit *mount = new Mount();
                        mount->create(cell);
                    }
                    if (cell->litera == 'e') {
                        cell->lineToDarckGround = 1;
                         arrAroundDarck.push(cell);
                    }  
    //            });
                    arr.forEach([](Cell *firstCell)
                    {
                        
                         firstCell->aroundCells.forEach([](Cell *secondCell)
                                                                              {
                    if (secondCell->litera != 't' && 
                    !secondCell->lineToTreeNumber) {
                        int rand = intRand(0, 5);
                        if (!rand) {secondCell->lineToTreeNumber = 2;}
                    } }); });


                    arrAroundDarck.forEach([](Cell* cell){
                        cell->maxAroundCells.forEach([cell](Cell* ac, int i){
                            int dis = cell->maxAroundCellsDis.getItem(i);
                           if (dis <= 150 && (!ac->lineToDarckGround || (
                            ac->lineToDarckGround > 1
                           ))) {
                                  ac->lineToDarckGround = 1;
                           } else if (dis <= 250 && (!ac->lineToDarckGround || (
                            ac->lineToDarckGround > 2
                           ))) {
                            ac->lineToDarckGround = 2;
                           }
                        });
                    });

                    arrStones.forEach([](Cell* as){
                        as->maxAroundCells.forEach([as](Cell* ac){
                        Delta delta = getDeltas(
                        {as->x + as->gabX, as->y + as->gabY},
                        {ac->x + as->gabX / 2, ac->y + as->gabY /2}
                        ); 
                        double dis = getDis(delta); 
                        if (dis <= 100) {
                            ac->LineToMountNumber = 1;
                        } else if (dis <= 200 && !ac->LineToMountNumber) {
                            ac->LineToMountNumber = 2;
                        }
                        });

                     });

    //         shahts.forEach([this](ProtoObj *cell, int i){
    //             ProtoObj *shaht = new Shaht;
    //             shaht->create(cell);
    //             shaht->gold = stoi(this->goldData.getItem(i));
    //         });

            

    // } else {
    //  Array<ProtoObj *> oils;
    //  plane->cells.forEach([&oils, this](ProtoObj * cell){
    //     if (cell->litera == '9') {
    //         oils.push(cell);
    //     }
    //  });
    //     oils.forEach([this](ProtoObj * cell, int i){
    //             ProtoObj *oil = new Oil;
    //             oil->create(cell);
    //             oil->oil = stoi(this->oilData.getItem(i));

        });
                             } });
};