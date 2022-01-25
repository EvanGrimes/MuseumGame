#ifndef MUSEUMGAME_STARRYBATTLE_H
#define MUSEUMGAME_STARRYBATTLE_H

#include "../Assets.h"

class StarryBattle {
public:

    const char FightMsg1[255] = "You turn on a flashlight and contribute to light pollution";
    const char FightMsg2[255] = "You turn on the gas stove and contribute to pollution";
    const char FightMsg3[255] = "You wish for the sun to rise and hurt it's feelings";

    int BullshitCritCount = 0;

    int frameCounter = 0;
    double textFrame = 0;

    int FightMsg = 0;
    int tempCount = 0;
    bool temp = false;

    bool IsBossDead = false;
    bool IsPlayerDead = false;

    Rectangle FightBtn = {20,475,257, 97 };
    Rectangle ItemBtn = {370,475,257, 97 };
    Rectangle LeaveBtn = {720,475,257, 97 };
    Rectangle HeathBack = {370, 420, 235, 16};
    Rectangle CurrHealth = HeathBack;

    Rectangle PlayerHealthBack = {370, 455, 235, 16};
    Rectangle PlayerCurrHealth = PlayerHealthBack;

    void tick();
    void render();

    void DrawTextBox(const char* Message);

    bool FightBtnAction = false;
    bool ItemBtnAction = false;
    bool LeaveBtnAction = false;

    Vector2 mousePoint = { 0.0f, 0.0f };

    void TickPlatformer();

    void tickFight();
    void tickItem();
    void tickLeave();

};


#endif //MUSEUMGAME_STARRYBATTLE_H
