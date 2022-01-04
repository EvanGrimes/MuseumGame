#ifndef MUSEUMGAME_MONABATTLE_H
#define MUSEUMGAME_MONABATTLE_H

#include "../Assets.h"

class MonaBattle {
public:
    bool IsBossDead = false;

    Rectangle FightBtn = {20,475,257, 97 };
    Rectangle ItemBtn = {370,475,257, 97 };
    Rectangle LeaveBtn = {720,475,257, 97 };

    void tick();
    void render();

    bool FightBtnAction = false;
    bool ItemBtnAction = false;
    bool LeaveBtnAction = false;

    Vector2 mousePoint = { 0.0f, 0.0f };

    void tickFight();
    void tickItem();
    void tickLeave();
};


#endif //MUSEUMGAME_MONABATTLE_H
