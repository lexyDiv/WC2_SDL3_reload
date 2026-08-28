#include "classesRealisations/out.h"
// => main


thread *th_create_game = nullptr;

void th_create()
{
    game->create();
    game->gf->field.forEach([](Array<Cell *> cells)
                            { cells.forEach([](Cell *cell)
                                            {
                     for (int i = 0; i < thDatas.length; i++) {
                        Td_way_data twd;
                        cell->thwd.push(twd);
                     } }); });
};