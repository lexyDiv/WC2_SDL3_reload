#include "Game.h"
//=>Imager

class GameField
{
public:

int deep = 30000;
int deep2 = 30000;
int deep3 = 30000;
int deep4 = 30000;
int maxDeep = 30000;
int minDeep = 1000;
int fieldMidIndex = 0;
//////
int threadStep = 0;
int thread_1_postIndex = 0;
int thread_2_postIndex = 0;
int thread_3_postIndex = 0;
int thread_4_postIndex = 0;
int thread_5_postIndex = 0;
int thread_6_postIndex = 0;
int thread_7_postIndex = 0;


Array<int> deeps;

     void exploreNewCellAndAddToOpenArr(Unit *unit, Cell *fatherCell, Cell *potentialCell) {};
     void getPotentialWay(Unit *unit) {};
     int get_G(Cell *cell, Cell *potentialCell) { return 0; };
     int get_H(Cell *potentialCell, Cell *finishCell) { return 0; };
     void potentialWayCreate(Unit *unit, Unit *finalCell) {};
    Cell *min_F_cell = nullptr;
    Cell *globalMin_H_cell = nullptr;

     void exploreNewCellAndAddToOpenArr2(Unit *unit, Cell *fatherCell, Cell *potentialCell) {};
     void getPotentialWay2(Unit *unit) {};
     int get_G2(Cell *cell, Cell *potentialCell) { return 0; };
     int get_H2(Cell *potentialCell, Cell *finishCell) { return 0; };
     void potentialWayCreate2(Unit *unit, Cell *finalCell) {};
    Cell *min_F_cell2 = nullptr;
    Cell *globalMin_H_cell2 = nullptr;

     void exploreNewCellAndAddToOpenArr3(Unit *unit, Cell *fatherCell, Cell *potentialCell) {};
     void getPotentialWay3(Unit *unit) {};
     int get_G3(Cell *cell, Cell *potentialCell) { return 0; };
     int get_H3(Cell *potentialCell, Cell *finishCell) { return 0; };
     void potentialWayCreate3(Unit *unit, Cell *finalCell) {};
    Cell *min_F_cell3 = nullptr;
    Cell *globalMin_H_cell3 = nullptr;


     void exploreNewCellAndAddToOpenArr4(Unit *unit, Cell *fatherCell, Cell *potentialCell) {};
     void getPotentialWay4(Unit *unit) {};
     int get_G4(Cell *cell, Cell *potentialCell) { return 0; };
     int get_H4(Cell *potentialCell, Cell *finishCell) { return 0; };
     void potentialWayCreate4(Unit *unit, Cell *finalCell) {};
    Cell *min_F_cell4 = nullptr;
    Cell *globalMin_H_cell4 = nullptr;

    ///////////////////////////////////////////////////////////////////////////////
    GameField(){};
   // GameField(string *path, int type);
     ~GameField();
     void create();
     void mapInit(Array<string> &array);
     void getFieldImage();
     void miniMapUpdate();
     void miniMapDraw();
     void cellsIteration(function<void(Cell *cell)> fn);
     void getAroundCells(int wing, bool selfCell, function<void(Cell *focusCell, Cell *cellToPush)> fn);
     void offsetControl();
     void miniMapMouseControl();
     void miniMapHoldLeftMouseKey();
     void getContinents();
     void getMaxAroundCellsDis();
     void getToOtherPlaneCellsNumber();
     void getToTreeCellLineNumber();
     void getCellImageCellDrawIndexCellUnitInit();
     void getVectorCells(Cell *cell);
     void fieldClick();
     void fieldClickRight();
     void getPathes(string *path, int type);

    double getMinCellsDis(Cell *cell, Cell *cell2);

     Color getDefaultColor(char lit);

    // ProtoObjMenu* objMenu = nullptr;
    Game *game = nullptr;
    Array<Fraction *> fractions;

    Array<Array<Cell *>> field;

    Array<Plane *> planes;
    Array<string> goldData;
    Array<string> oilData;
    Array<Unit *> activeShahts;

    Array<Unit *> trupsOnDelete;
     void trupsControl() {};
     void activeShahtsControl() {};

    Image *miniMap = nullptr;
    Cell *drawCell = nullptr;
    string path;
    int type;
    int miniMapUpdateVer = 0;
    float gabarit = 0;
    float screenWidth = 720;
    float screenHeight = 720;
    float cellSize = this->screenHeight / 15;
    float x = 0;
    float y = 48;
    float centerX = this->screenWidth / 2;  //+ this->x;
    float centerY = this->screenHeight / 2; //+ this->y;
    float offsetX = 0;
    float offsetY = 0;
    float drawDeltaX = 0;
    float drawDeltaY = 0;
    float drawOffsetX = 0;
    float drawOffsetY = 0;
    float width = 0;
    float height = 0;
    float offsetStep = 20;
    bool init = false;
    double createCount = 0.0;
    double createCount2 = 0.0;
    double createCount3 = 0.0;
    double createCount4 = 0.0;
    double procCurr = 0.0;
    double procCurr2 = 0.0;
    double procCurr3 = 0.0;
    double procCurr4 = 0.0;

    // this->miniMap, 0, 0, this->gabarit, this->gabarit, 732, 100, 285, 285
    ////////////////////////////// => miniMap
    float miniMapX = 732;
    float miniMapY = 5;
    float miniMapGab = 200;
    float miniMapClickX = 0;
    float miniMapClickY = 0;
    bool miniMapClick = false;
    float miniMapWinGab = 0;
    float mcs = 0.0f;
    double dx = 0;
    double dy = 0;
    //////////////////////////// <= miniMap

    ///////////////// => fieldClick
    bool isFieldClickHold = false;
    //////////////// <= fieldClick

    FieldClick *fieldClickPoint = nullptr;

    Array<Cell *> openArr;
    Array<Cell *> openArr2;
    Array<Cell *> openArr3;
    Array<Cell *> openArr4;
    Array<Array<Cell *>> exp;

    // bool isQuick = false;
    //   void potentialWayCreate2(ProtoObj *unit, ProtoObj *finalCell) {};

private:
};

struct FieldClick
{
    Point clickPoint;
    int time = 10;
    bool up = false;
    float firstX, firstY, secX, secY, gabX, gabY;
    void moveControl(int cursorX, int cursorY)
    {

        float X = this->clickPoint.x;
        float Y = this->clickPoint.y;
        if (X <= cursorX)
        {
            this->firstX = X;
            this->secX = cursorX;
        }
        else
        {
            this->firstX = cursorX;
            this->secX = X;
        }

        if (Y <= cursorY)
        {
            this->firstY = Y;
            this->secY = cursorY;
        }
        else
        {
            this->firstY = cursorY;
            this->secY = Y;
        }
        this->gabX = this->secX - this->firstX;
        this->gabY = this->secY - this->firstY;
    };
};