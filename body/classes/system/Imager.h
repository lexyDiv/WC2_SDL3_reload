#include "Cell.h"
//=>UnitData

class Imager
{
public:
    Image *groundBasic = new Image("images/grunt/summer/basic/basick.png");
    Image *groundBasic1 = new Image("images/grunt/summer/basick.png");
    Image *groundBasicDarck1 = new Image("images/grunt/summer/basick_tem1.png");
    Image *groundBasicDarck = new Image("images/grunt/summer/basick_tem.png");
    Image *underWood = new Image("images/grunt/summer/under_wood.png");
    Image *aroundWood1 = new Image("images/grunt/summer/round_wood_1.png");
    Image *aroundWood2 = new Image("images/grunt/summer/round_wood_2.png");
    Image *aroundWood3 = new Image("images/grunt/summer/round_wood_3.png");
    Image *ocean = new Image("images/images/ocean.png");
    Image *pesok1 = new Image("images/grunt/summer/round_pesok_1.png");
    Image *pesok2 = new Image("images/grunt/summer/round_pesok_2.png");

    Image *mount1 = new Image("images/grunt/summer/round_stown_1.png");
    Image *mount2 = new Image("images/grunt/summer/round_stown_2.png");

    // mount
    Image *gora1 = new Image("images/grunt/summer/gora_closed.png");
    Image *gora2 = new Image("images/grunt/summer/gora_free.png");
    Image *gora3 = new Image("images/grunt/summer/gora_left_free.png");
    Image *gora4 = new Image("images/grunt/summer/gora_right_free.png");

    // tree

    Image *tree1 = new Image("images/images/trees.png");
    Image *tree2 = new Image("images/images/trees2.png");

    Image *tree1Trup = new Image("images/images/treesTrup.png");
    Image *tree2Trup = new Image("images/images/trees2Trup.png");

    // shaht

    Image *shaht = new Image("images/images/neutral/buildings/summer/gold_mine2.png");
    // Image *shaht = new Image("images/images/altar_h_blue.png");
    Image *oilPoint = new Image("images/images/oil.png");

    Image *icons = new Image("images/icons.png");

    Image *menuFon = new Image("images/images/menuFon.jpg");
    Image *close = new Image("images/close.png");
    Image *yes = new Image("images/yes.png");
    Image *no = new Image("images/no.png");
    Image *goldIcon = new Image("images/gold.png");
    Image *oilIcon = new Image("images/oil.png");
    Image *woodIcon = new Image("images/wood.png");
    Image *peonRed = new Image("images/images/peon_new.png");
    Image *peonWithWoodRed = new Image("images/images/peon_with_wood.png");
    Image *peonWithGoldRed = new Image("images/images/peon_with_gold.png");
    Image *townHallOrcRed = new Image("images/orcs/red/buildings/great_hall.png");

    Imager() {};
    ~Imager()
    {
        delete this->townHallOrcRed;
        this->townHallOrcRed = nullptr;

        delete this->peonWithWoodRed;
        this->peonWithWoodRed = nullptr;

        delete this->peonWithGoldRed;
        this->peonWithGoldRed = nullptr;

        delete this->peonRed;
        this->peonRed = nullptr;

        delete oilIcon;
        oilIcon = nullptr;

        delete woodIcon;
        woodIcon = nullptr;

        delete goldIcon;
        goldIcon = nullptr;

        delete no;
        no = nullptr;

        delete yes;
        yes = nullptr;

        delete close;
        close = nullptr;

        delete menuFon;
        menuFon = nullptr;

        delete icons;
        icons = nullptr;

        delete groundBasic;
        groundBasic = nullptr;

        delete groundBasic1;
        groundBasic1 = nullptr;

        delete groundBasicDarck1;
        groundBasicDarck1 = nullptr;

        delete groundBasicDarck;
        groundBasicDarck = nullptr;

        delete underWood;
        underWood = nullptr;
        delete aroundWood1;
        aroundWood1 = nullptr;
        delete aroundWood2;
        aroundWood2 = nullptr;
        delete aroundWood3;
        aroundWood3 = nullptr;
        delete ocean;
        ocean = nullptr;
        delete pesok1;
        pesok1 = nullptr;
        delete pesok2;
        pesok2 = nullptr;

        delete mount1;
        mount1 = nullptr;
        delete mount2;
        mount2 = nullptr;

        // mount
        delete gora1;
        gora1 = nullptr;
        delete gora2;
        gora2 = nullptr;
        delete gora3;
        gora3 = nullptr;
        delete gora4;
        gora4 = nullptr;
        delete tree1;
        tree1 = nullptr;
        delete tree2;
        tree2 = nullptr;

        delete tree1Trup;
        tree1Trup = nullptr;
        delete tree2Trup;
        tree2Trup = nullptr;
        delete shaht;
        shaht = nullptr;
        delete oilPoint;
        oilPoint = nullptr;
        std::cout << "imager delete" << std::endl;
    };
};

Imager imager;