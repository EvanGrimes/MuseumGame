#ifndef MUSEUMGAME_PIPEBATTLE_H
#define MUSEUMGAME_PIPEBATTLE_H

#include "../Assets.h"

class PipeBattle {
public:

    const char FightMsg1[255] = "You ask if there is a pipe and the pipe billows smoke";
    const char FightMsg2[255] = "You tell the pipe that it's not a pipe and it begins to have an \nexistential crisis";
    const char FightMsg3[255] = "You throw the pipe into a paradox because it is both there and \nnot there at the same time";

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

    Vector2 PaintingPOS = {370, 50};

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


#endif //MUSEUMGAME_PIPEBATTLE_H
