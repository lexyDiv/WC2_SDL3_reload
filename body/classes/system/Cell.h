#include "in.h"
//=> Fraction

class GameField;
class Fraction;
class ObjMenu;
class Unit;
class Plane;
class Order;
class UnitMenu;
struct FieldClick;
struct Water;
struct AnimLines;
class Game;

struct UnitPack
{
    Unit *unit = nullptr;
    int bornCount = 0;
};

// class MoveCase
// { 
//     public:
//     MoveCase(ProtoObj *cell) {
//         this->cell = cell;
//     }; 
//     ProtoObj *cell = nullptr;
//     bool isComplite = false;
//     function<void()> moveCase = []() {};
// };

class Cell
{
public:
    bool closedOnCase = false;

    bool isPotentialWayComplite = true;
     bool isActiveCheck() { return false; };
   // std::mutex mute_case;

    

    int G = 0;
    int F = 0;
    int H = 0;
    Cell *wayFather = nullptr;
     void getCurrentTargetCell();
    double createCountData = 0.0;
    double explored = 0.0;
    double procCurr = 0;

    int G2 = 0;
    int F2 = 0;
    int H2 = 0;
    Cell *wayFather2 = nullptr;
    double createCountData2 = 0.0;
     void getCurrentTargetCell2() {};
    double explored2 = 0.0;
    double procCurr2 = 0;

    int G3 = 0;
    int F3 = 0;
    int H3 = 0;
    Cell *wayFather3 = nullptr;
    double createCountData3 = 0.0;
     void getCurrentTargetCell3() {};
    double explored3 = 0.0;
    double procCurr3 = 0;

    int G4 = 0;
    int F4 = 0;
    int H4 = 0;
    Cell *wayFather4 = nullptr;
    double createCountData4 = 0.0;
     void getCurrentTargetCell4() {};
    double explored4 = 0.0;
    double procCurr4 = 0;

    /////////////////////////////////////////////////////////////////////////////////////////////////

    bool isClosed = false;
    Cell(){};
     ~Cell();
     void draw();
     Color getMapColor();

    /////////
     void create(Cell *cell);
    // void createInside(ProtoObj *c) {}; // !
     int getLevel();
     void createUnitMenu();
     void getHandTarget(Cell *cell);
     void activeProg();
     void stendOnCell();
     void stendOnCellWait();
     void selectAnAction();
    //  ProtoObj *getAnyTree() // !
    // {
    //     return nullptr;
    // };
    //  ProtoObj *getAnyShaht() // !
    // {
    //     return nullptr;
    // };
    int persNum = 0;
    ////////
    // int deleteTimer = 0;
    // all

    GameField *gf = nullptr;
    Game *game = nullptr;
    Plane *plane = nullptr;
    UnitMenu *unitMenu = nullptr;

    bool isDelete = false;
    // bool inUse = false;

    string type;
    float x = 0.0f;
    float y = 0.0f;
    float drawX = 0.0f;
    float drawY = 0.0f;
    int ver = 0;
    int hor = 0;

    int drawIndexY = 0;
    int animTakt = 0;
    int animX = 0;
    int animY = 0;
    int animGabX = 0;
    int animGabY = 0;
    int animStepX = 0;
    int animStepY = 0;
    double animMashtab = 1;
    int gabX = 0;
    int gabY = 0;
    int drawGabaritX = 120;
    int drawGabaritY = 120;
    int centerX = 0;
    int centerY = 0;

    int getGabX = 0;
    int getGabY = 0;

    Image *image = nullptr;
    Image *image2 = nullptr;
    Image *image3 = nullptr;

    // neitral & buildfings
    int gold = -1;
    int wood = 0;
    int oil = 0;
    Array<AnimLines *> lines;    // oil anim line
    float linePusherY = 0.0f;    // oil anim
    float linePullerY = -100.0f; // oil anim
    int linesCount = 20;
    bool inZone = false;
    // Array<ProtoObj *> clients; // !
    // Array<ProtoObj *> potentialClients; // !
    // Array<ProtoObj *> outClients; // !
    void get4x4myCells(Cell *cell);
    void get3x3myCells(Cell *cell);
    void get2x2myCells(Cell *cell);
    void getContactAndExitCells(Cell *cell, Cell *exitCell, Cell *centerCell);
    void getContactCells();
   //  ProtoObj *getTreeNear() { return nullptr; };
    // units
     void updateCurrentTarget() {};
    Image *menuImage = nullptr;
    string titleName = "";

    bool isWarrior = false;
    bool isFlying = false;
    bool isSweeming = false;

    string name = "";

    bool isActive = false;
    bool isAddOnDraw = false;
    int speed = 0;
    int hp = 0;
    int hpMax = 0;
    int attack = 0;
    int armor = 0;
    int mana = 0;
    int sight = 1;
    int animTimer = 0;
    float alpha = 255;
    double startAnimMashtab = 0.456000;

    int stress = 0;                  // for tree
     void stressControl() {}; // tree
    int saveX = 0;                   // tree

    /////////////////// => handTarget
    Cell *preTargetCell = nullptr;
    Cell *targetCell = nullptr;
    int handTargetTimer = 0;
    int handTargetMaxTime = 0;

    UnitPack targetObj;
    Unit *lesorub = nullptr;
    string profession = "";
     void fightControl() {};
    ////////////////////////// <= handTarget
    Cell *cell = nullptr;
    // Array<ProtoObj *> enemys; // !
    // Array<ProtoObj *> way; // !
    // Array<ProtoObj *> potentialWay; // !
    // Array<ProtoObj *> pw; // !
    //////////////////// =>  way

    bool isNeedReturnGetPotentialWay = false; // ???
                                              //  bool isOnGetPotentialWayGetTarget(ProtoObj *cell);
                                              //   bool isNewCellOnGetWayValide(ProtoObj *cell);
    function<bool(Cell *cell)> isOnGetPotentialWayGetTarget = [](Cell *cel)
    {
        return false;
    };
    function<bool(Cell *cell)> isNewCellOnGetWayValide = [](Cell *cell)
    {
        return false;
    };
    int wayIndex = 0;
    bool isGetMyCell = true;
    int ordersOnWayCurrent = 0;
    Order *orderOnWay = nullptr;
    function<void(Unit *unit)> targetObjControl = [](Unit *unit) {};
    bool iNeedFreeWay = false;
     bool isIValideOnWay(Unit *unit)
    {
        return true;
    };
    ////////////////////////// <= way
    // Array<ProtoObj *> cells2X2;
    ////////////////////// =>  buildings
    Array<Cell *> contactCells;
    Array<Cell *> exitCells;
    bool isComplite = false;
     void wellCome(Unit *peon) {};
    //////////////////////  <= buildings
    Fraction *fraction = nullptr;
    //  bool isBlocked(ProtoObj* unit);
     bool isBlockedd(Unit *unit);
    bool isIgetMyTarget = false;
    // cells

    Unit *groundUnit = nullptr;
    Unit *flyUnit = nullptr;
    Array<Cell *> aroundCells;
    Array<Cell *> maxAroundCells;
    Array<double> maxAroundCellsDis;
    Array<Cell *> drawCells;
    Array<Array<Cell *>> cellsOnDraw;
    Array<Unit *> orderedTrees;
    Array<Unit *> orderedShahts;
    int createTimer = 0;
    int createTimerMax = 100;
    int updateTimer = 0;
    int updateTimerMax = 1000;
  //  int level = 1;
    /////// => trupy
    Array<Unit *> ripUnits; // trupy
     void trupCreate() {};
    int deleteTimer = 0;
     void drawTrup() { console.log("trup draw"); };
   //  void takeDamage(int damage) {};
    /////// <= trupy
   // Array<MinData> wellComeCells;
     void getWellComeCells();
    double inOutCount = 0;
    double inOutMashtabCount = 0;
    double inOutMashtabMin = 0.456000;
   // Array<ProtoObj *> landDecorationObjs;

    Cell *left = nullptr;
    Cell *right = nullptr;
    Cell *top = nullptr;
    Cell *bottom = nullptr;
    Cell *top_left = nullptr;
    Cell *top_right = nullptr;
    Cell *bottom_left = nullptr;
    Cell *bottom_right = nullptr;

    ///////////////////////// go way =>
    int wayTakts = 0;
    double speedTale = 0;
    double wayDeltaX = 0;
    double wayDeltaY = 0;
    double conor = 0;
    int holdWayCount = 0;
    int outHoldTimer = 0;
    //////////////////////// <= go way
    // ProtoObj *gettingTarget = nullptr;

    // Array<ProtoObj *> guardCells;
   // Array<ProtoObj *> booms;
   // Array<ProtoObj *> bullets;
  //  ProtoObj *continent = nullptr;// !
    Color mapColor = {R : 0, G : 0, B : 0};
    char litera;
    int lineToOtherPlaneNumber = 0;
    int lineToTreeNumber = 0;
    int LineToMountNumber = 0;
    int lineToDarckGround = 0;
    int cellDrawIndex = 0;
    Array<Water *> waters;
    Image *cellImage = nullptr;
    Image *cellImage2 = nullptr;
    Image *cellImage3 = nullptr;

    //////////////// fight
    bool inFight = false;
    int inFightTimer = 0;
    ///////////////

    // bullets

    // flying units
    float z = 0.0f;

    // sea units

    // buildings
  //  Array<Cell *> myCells;
  //  Cell *bornCell = nullptr;
  //  int bornCount = 0;
    // land objects
    //
  //  int inOutTimer = 0;
  //  bool inSave = false;
    ////////////////// => remove
    // void reMove() {};
    // int reMoveTimer = 0;
    ///////////////// <= remove
    //  void orderOnWayControl() {};
    //  void goWayAnimation() {};
    //  void inFightAnimation() {};
    //  void goWay() {};
    //  bool isNextCellFreeToGoWay(Cell *nextCell) { return true; };
    //  bool isNeedHoldGoWay(Cell *nextCell) { return true; };
    //  bool isGetTarget() { return true; };
    //  bool isTargetObjValide() { return true; };
    //  Unit *getBaseForUnloading() { return nullptr; };
    //  Unit *getBaseForUnloadingGold() { return nullptr; };
    //  void preDraw() {};
    //  void getTrees() {};
    //  void getShahts() {};

   // Array<Unit *> interUnits;

    // wall
    ///// test
    // bool focus = false;
    // int noIsCompliteTimer = 0;
    // bool frashWay = false;
    // bool isAnimyCheckNeeded = true;
    //  void iAmHere() {};
    //  void iSeeYou(Unit *unit) {};

private:
};

struct AnimLines
{
    int y = 0;
    int animX = 0;
    int animY = 0;
    int animGabX = 100;
    int animGabY = 5;
    float deltaX = 0;
    int gabY = 5;
    float alpha = 255;

    void draw(Unit *oil)
    {
        // float drawDeltaX = oil->gf->drawDeltaX;
        // float drawDeltaY = oil->gf->drawDeltaY;
        // ctx.DrawImage(oil->image,
        //               this->animX,
        //               this->animY,
        //               this->animGabX, this->animGabY,
        //               oil->x + this->deltaX + drawDeltaX, oil->y + this->y + drawDeltaY,
        //               oil->getGabX, this->gabY, SDL_FLIP_NONE, 0, this->alpha);
    };
};

struct Water
{
    int animX = 0;
    int animY = 0;
    int alpha = 255;
    bool alphaVector = true;
    double conor = 0.0f;
    int conorVector = intRand(0, 2);
    int takt = 0;
    int checkTakt = 0;
    int drawGabPro = intRand(1, 20);
    bool drawGabProVector = true;
    void drawControlBasic(int i)
    {

        if (!i)
        {

            if (this->takt % (this->checkTakt + 5) == 0)
            {
                if (this->drawGabPro <= 0 || this->drawGabPro >= 20)
                {
                    this->drawGabProVector = !this->drawGabProVector;
                }
                if (this->drawGabProVector)
                {
                    this->drawGabPro++;
                }
                else
                {
                    this->drawGabPro--;
                }
            }
        }
        else
        {
            if (this->conorVector)
            {
                this->conor += 0.05;
            }
            else
            {
                this->conor -= 0.05;
            }
            if (this->conor >= 360 || this->conor <= -360)
            {
                this->conor = 0;
                conorVector = intRand(0, 2);
            }
        }
        if (this->takt % this->checkTakt == 0)
        {
            if (this->alpha == 255 || !this->alpha)
            {
                this->alphaVector = !this->alphaVector;
                if (!this->alpha)
                {
                    this->animX = 100 * intRand(0, 8);
                    // this->conor = (double)intRand(0, 360);
                }
            }

            if (!this->alphaVector)
            {
                this->alpha++;
            }
            else
            {
                this->alpha--;
            }
        }
        this->takt++;
        if (this->takt == 1000)
        {
            this->takt = 0;
        }
    };

    void draw(Cell *cell, int i);
    // {
    //     float drawDeltaX = cell->gf->drawDeltaX;
    //     float drawDeltaY = cell->gf->drawDeltaY;

    //     ctx.DrawImage(
    //         cell->cellImage, this->animX, this->animY,
    //         cell->animGabX, cell->animGabY,
    //         cell->x + drawDeltaX - 40, cell->y + drawDeltaY - 40,
    //         cell->drawGabaritX + this->drawGabPro, cell->drawGabaritY + this->drawGabPro,
    //         SDL_FLIP_NONE, this->conor, this->alpha);
    // };
};

struct CellDis
{
    Cell *cell = nullptr;
    double dis = 0.0;
};