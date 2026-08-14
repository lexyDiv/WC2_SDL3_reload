#include "Nation.h"
//=> Game




class Upgrade {
    public:
    int current = 0;
    int complite = 0;
    string name = "";
    Upgrade(int complite, string name) {
       this->complite = complite;
       this->name = name;
    };
};

struct FractionTownHall {
    Array<Unit *> townHolls;
    int level_1_townHollsCount = 0;
    int level_2_townHollsCount = 0;
    int level_3_townHollsCount = 0;
};

struct FractionLamberMill {
    Array<Unit *> lamberMills;
    Array<Upgrade> seengUpgrades;
    Array<Upgrade> damageUpgrades;
    Array<Upgrade> regenerationUpgrades;
    int seengLevel = 0;
    int damageLevel = 0;
    int regenerationLevel = 0;

};



class Fraction {
    public:
     Fraction(){};
   virtual ~Fraction(){};
    virtual void create(Game* game, Nation *nation, string color);

   virtual void orderControl(){};
   virtual void controller();
   virtual void activeUnitsControl(){};

   ////////////////////// => new system
   UnitData peon;
   UnitData townHall;
   ////////////////////// <= new system

   /////////////////////  union buildings
    FractionTownHall fTownHoll;
    FractionLamberMill fLamberMill;
   ////////////////////

    string name = "";
    string control = "";
    string color = "";
    Color mapColor = { R: 255, G: 0, B: 0 };
    int level = 0;
    Array<Unit *> units;
    Array<Unit *> AllLifeUnits;
    Array<Unit *> allBuildings;

    Game *game = nullptr;
    Array<Unit *> peons;
    Array<Unit *> peonsOnWood;
    Array<Unit *> peonsOnGold;

    ///////////////////  reserv
    Array<Unit *> reservPeons;
    Array<Unit *> reservTownHolls;
    //////////////////

    Nation *nation = nullptr;

    int unionCase = 0;
    int gold = 0;
    int oil = 0;
    int wood = 0;
    int controlTimer = 0;
    int unitCount = 0;
    int hold = 0;

};