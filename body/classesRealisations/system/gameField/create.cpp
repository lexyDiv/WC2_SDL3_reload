#include "GameField.cpp"
//=> mapInit

void GameField::create()
{
    Array<string> array = readMap(&this->path);
    console.log(to_string(array.length));
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
        for (int i = 0; i < shahtData.length(); i++) {
          string lit{shahtData[i]};
          if (lit == ",") {
             goldIndex ++;
             string gdi = "";
             this->goldData.push(gdi);
          } else {
             string *str = this->goldData.getItemPtr(goldIndex);
             *str += lit;
          }
        }
       array.pop();

    ///////////////////////////////

    this->mcs = this->miniMapGab / this->gabarit;
    this->miniMapWinGab = ceil(this->mcs * 15);

     this->mapInit(array);

    this->getAroundCells(1, false, [](Cell *focusCell, Cell *pushedCell){
       focusCell->aroundCells.push(pushedCell);
    });
    this->getAroundCells(9, true, [](Cell *focusCell, Cell *pushedCell){
       focusCell->drawCells.push(pushedCell);
    });
    this->getAroundCells(11, false, [](Cell *focusCell, Cell *pushedCell){
       focusCell->maxAroundCells.push(pushedCell);
    });
     this->getContinents();

     this->getMaxAroundCellsDis();
     this->getToOtherPlaneCellsNumber();
     this->getToTreeCellLineNumber();
     this->getCellImageCellDrawIndexCellUnitInit();
     this->init = true;
};