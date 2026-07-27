#include "Th.h"
//=>system out

class Unit
{
public:
     Unit(){};
    ~Unit() {};
    
    Cell *cell = nullptr;

   virtual void create(Cell*){};
   virtual void getContactCells();
   virtual void draw(){};
   virtual void get2x2myCells(Cell *cell);
   virtual void get3x3myCells(Cell *cell);
   virtual void getContactAndExitCells(Cell *cell, Cell *exitCell, Cell *centerCell);
   virtual void getWellComeCells();

     int deleteTimer = 50;
    Array<Cell *> myCells;
    Array<Cell *> contactCells;
    Array<Cell *> exitCells;
    Array<Unit *> clients;
    Array<MinData> wellComeCells;
    
    string name = "tree";
    string type = "building";
    Color mapColor = {R: 0, G: 150, B: 0};
    double drawGabaritX = 0;
    double drawGabaritY = 0;
    int randX = intRand(0, 15);
    int randXVec = intRand(0, 2);
    int randY = intRand(0, 15);
    int randYVec = intRand(0, 2);
    double x = randXVec = 0; 
    double y = randYVec = 0; 
    double saveX = 0;   
    double drawIndexY = 0;
    int hp = 50;
    int hpMax = 0;
    bool isComplite = false;
    int animGabX = 0;
    int animGabY = 0;
    int animStepX = 0;
    int animStepY = 0;
    Image *image = nullptr;
    Image *image2 = nullptr;
    int animX = 0;
    int animY = 0;
    int animTakt = 0;
    GameField *gf = nullptr;
    bool isAddOnDraw = false;
    int alpha = 255;
    int getGabX = 0;
    int getGabY = 0;
    int gold = 0;
    
};