#include "GameField.cpp"
//=> mapInit

void GameField::create()
{
   Array<string> array = readMap(&this->path);
   // console.log(to_string(array.length));
   this->gabarit = array.length;
   this->fieldMidIndex = array.length / 2;
   // ///////////////////////
   // this->threadStep = array.length / 7;
   // this->thread_1_postIndex = 0;
   // this->thread_2_postIndex = this->thread_1_postIndex + this->threadStep;
   // this->thread_3_postIndex = this->thread_2_postIndex + this->threadStep;
   // this->thread_4_postIndex = this->thread_3_postIndex + this->threadStep;
   // this->thread_5_postIndex = this->thread_4_postIndex + this->threadStep;
   // this->thread_6_postIndex = this->thread_5_postIndex + this->threadStep;
   // this->thread_7_postIndex = this->thread_6_postIndex + this->threadStep;
   // /////////////////////////
   // this->deeps.push(500);
   // this->deeps.push(1000);
   // this->deeps.push(2000);
   // this->deeps.push(3000);
   // this->deeps.push(5000);
   ///////////////////////// => json
   //  json j;
   //  j["name"] = "test_bigest_500";
   //  j["oil"].push_back(100);
   //  j["oil"].push_back(200);
   //  j["gold"].push_back(10000);
   //  j["gold"].push_back(20000);
   //  array.forEach([&j](string line){
   //    j["field"].push_back(line);
   //  });
   //  string sPath = "strings/test_bigest_500.txt";
   //  writeStr(&sPath, to_string(j));
   /////////////////////////// <= json

   this->gabarit = array.getItem(0).size();
   this->height = this->gabarit * this->cellSize;
   this->width = this->height;

   ///////////////////////////////// get oil data
   string oilData = array.getItem(array.length - 1);
   string oilDtataItem = "";
   this->oilData.push(oilDtataItem);
   int oilIndex = 0;
   for (int i = 0; i < oilData.length(); i++)
   {
      string lit{oilData[i]};
      if (lit == ",")
      {
         oilIndex++;
         string odi = "";
         this->oilData.push(odi);
      }
      else
      {
         string &str = this->oilData.getItemLnk(oilIndex);
         str += lit;
      }
   }
   array.pop();

   ///////////////////////////////

   ///////////////////////////////// get gold data
   string shahtData = array.getItem(array.length - 1);
   string goldDtataItem = "";
   this->goldData.push(goldDtataItem);
   int goldIndex = 0;
   for (int i = 0; i < shahtData.length(); i++)
   {
      string lit{shahtData[i]};
      if (lit == ",")
      {
         goldIndex++;
         string gdi = "";
         this->goldData.push(gdi);
      }
      else
      {
         string *str = this->goldData.getItemPtr(goldIndex);
         *str += lit;
      }
   }
   array.pop();

   ///////////////////////////////

   this->mcs = this->miniMapGab / this->gabarit;
   this->miniMapWinGab = ceil(this->mcs * 15);

   this->mapInit(array);

   this->getAroundCells(1, false, [](Cell *focusCell, Cell *pushedCell)
                        { focusCell->aroundCells.push(pushedCell); });
   this->getAroundCells(9, true, [](Cell *focusCell, Cell *pushedCell)
                        { focusCell->drawCells.push(pushedCell); });
   this->getAroundCells(11, false, [](Cell *focusCell, Cell *pushedCell)
                        { focusCell->maxAroundCells.push(pushedCell); });

   this->getAroundCells(3, false, [](Cell *focusCell, Cell *pushedCell)
                        { focusCell->panicCells.push(pushedCell); });
   this->getContinents();

   this->getMaxAroundCellsDis();
   this->getToOtherPlaneCellsNumber();
   this->getToTreeCellLineNumber();
   this->getCellImageCellDrawIndexCellUnitInit();

////////////////////////////////////////////////////////////////// => magistral create
        for (int ver = 1; ver < this->field.length; ver += 3) {
            Array<Cell *> &vertical = this->field.getItemLnk(ver);
            Array<MagistralClaster> mca;
            this->game->allMagistralClasters.push(mca);
            int index = this->game->allMagistralClasters.length - 1;
            for (int hor = 1; hor < this->field.length; hor += 3) {
                Cell *cell = vertical.getItem(hor);
                MagistralClaster mc(cell);
               // mca.push(mc);
               this->game->allMagistralClasters.getItemLnk(index).push(mc);
            }
        }

        
       this->game->allMagistralClasters.forEach([this](Array<MagistralClaster> &mca, int ver){
           mca.forEach([&ver, this, &mca](MagistralClaster &mc, int hor){
              int currentVerUp = ver - 1;
              int currentHorLeft = hor - 1;
              int currentVerDown = ver + 1;
              int currentHorRight = hor + 1;
              mc.up = currentVerUp >= 0 ? this->game->allMagistralClasters.getItemLnk(currentVerUp).getItemPtr(hor) : nullptr;
              mc.down = currentVerDown <= mca.length - 1 ? this->game->allMagistralClasters.getItemLnk(currentVerDown).getItemPtr(hor) : nullptr;
              mc.left = currentHorLeft >= 0 ? this->game->allMagistralClasters.getItemLnk(ver).getItemPtr(currentHorLeft) : nullptr;
              mc.right = currentHorRight <= mca.length - 1 ? this->game->allMagistralClasters.getItemLnk(ver).getItemPtr(currentHorRight) : nullptr;
             mc.cells.forEach([&mc](Cell *c){
               c->mc = &mc;
             });
           });
       });


   this->init = true;
};