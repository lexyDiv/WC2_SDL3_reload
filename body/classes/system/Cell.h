#include "in.h"
//=> Order

class GameField;
class Fraction;
class ObjMenu;
// class Unit;
class Plane;
class Order;
class UnitMenu;
struct FieldClick;
struct Water;
struct AnimLines;
class Game;
class ToOtherPlane;
class Nation;
class Claster;
class Zone;

class TargetData
{
public:
    Unit *unit = nullptr;
    int unitPersNum = 0;
    Cell *clicckedCell = nullptr;
    Cell *unitOldCell = nullptr;
    string profession = "";
    bool isActual = false;
    bool specialFreeG0 = false;
    int forNeedFreeWayCount = 0;
    
    /////////////////////////////////// => magistral
    Array<Cell *> magistral;
    bool checkMagistral = false;
    Cell *prevCell = nullptr;
    Cell *nextCell = nullptr;
    int nextCellIndex = 0;
    int magistrlLoop = 0;
   // bool saveTargetIsBlocked = false; // not cleard
    bool isNeedMagistralFinish = false;
   // Cell *saveNextCell = nullptr;

    void clear()
    {
        
        unit = nullptr;
        unitPersNum = 0;
        clicckedCell = nullptr;
        unitOldCell = nullptr;
        profession = "";
        isActual = false;
        specialFreeG0 = false;
        
        /////////////////////////////////// => magistral
        checkMagistral = false;
        magistral.clear();
        prevCell = nullptr;
        nextCell = nullptr;
        nextCellIndex = 0;
        magistrlLoop = 0;
        isNeedMagistralFinish = false;
        //saveNextCell = nullptr;
    };
};


class Td_way_data
{
public:
    double createCountData = 0;
    int F = 0.0F;
    int H = 0.0F;
    int G = 0.0F;
    double explored = 0;
    double procCurr = 0;
    Cell *wayFather = nullptr;
    int magistralIndex = 0;
};

class Cell
{
public:
    Array<Td_way_data> thwd;

    int activeZoneIndex = 0;

    double createCountData = 0.0;

    bool isClosed = false;

    Cell() {};
    ~Cell() {};
    void draw();
    Color getMapColor();
    int persNum = 0;
    GameField *gf = nullptr;
    Game *game = nullptr;
    Plane *plane = nullptr;

    float x = 0.0f;
    float y = 0.0f;
    int ver = 0;
    int hor = 0;
    int animX = 0;
    int animY = 0;
    int animGabX = 0;
    int animGabY = 0;

    int gabX = 0;
    int gabY = 0;
    int drawGabaritX = 120;
    int drawGabaritY = 120;
    int centerX = 0;
    int centerY = 0;

    Unit *groundUnit = nullptr;
    Unit *flyUnit = nullptr;
    Array<Cell *> aroundCells;
    Array<Cell *> maxAroundCells;
    Array<double> maxAroundCellsDis;
    Array<Cell *> panicCells;
    Array<Cell *> drawCells;
    Array<Array<Cell *>> cellsOnDraw;

    Array<Unit *> ripUnits; // trupy

    void drawTrup() { console.log("trup draw"); };

    Cell *left = nullptr;
    Cell *right = nullptr;
    Cell *top = nullptr;
    Cell *bottom = nullptr;
    Cell *top_left = nullptr;
    Cell *top_right = nullptr;
    Cell *bottom_left = nullptr;
    Cell *bottom_right = nullptr;

    Color mapColor = {R : 0, G : 0, B : 0};
    char litera;
    int lineToOtherPlaneNumber = 0;
    int lineToTreeNumber = 0;
    int LineToMountNumber = 0;
    int lineToDarckGround = 0;
    int cellDrawIndex = 0;
    Array<Water> waters;
    Image *cellImage = nullptr;
    ////////////////////////////////=> clasters
    Claster * claster = nullptr;
    Zone *zone = nullptr;
    Array<Cell *> clasterCells;

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

    void draw(Unit *oil);
    // {
    //  float drawDeltaX = oil->gf->drawDeltaX;
    // float drawDeltaY = oil->gf->drawDeltaY;
    // ctx.DrawImage(oil->image,
    //               this->animX,
    //               this->animY,
    //               this->animGabX, this->animGabY,
    //               oil->x + this->deltaX + drawDeltaX, oil->y + this->y + drawDeltaY,
    //               oil->getGabX, this->gabY, SDL_FLIP_NONE, 0, this->alpha);
    //  };
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
    Unit *unit = nullptr;
    Cell *cell = nullptr;
    double dis = 0.0;
};