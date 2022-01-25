#ifndef MUSEUMGAME_AGOTHICBATTLE_H
#define MUSEUMGAME_AGOTHICBATTLE_H

#include "../Assets.h"

class AGothicBattle {
public:

    const char FightMsg1[255] = "You 'plow' the Old Man and his Wife";
    const char FightMsg2[255] = "You say, 'American Gothic? More like American Not It!' and they they take Physcic Damage";
    const char FightMsg3[255] = "You wish them a bad crop yeild this year.";

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

    void tickFight();
    void tickItem();
    void tickLeave();
};


#endif //MUSEUMGAME_AGOTHICBATTLE_H
