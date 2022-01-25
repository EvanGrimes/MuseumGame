#ifndef MUSEUMGAME_APPLEBATTLE_H
#define MUSEUMGAME_APPLEBATTLE_H

#include "../Assets.h"

class AppleBattle {
public:

    const char FightMsg1[255] = "You say you prefer oranges and a single tear rolls down his face";
    const char FightMsg2[255] = "You tell him his suit has a wrinkle and you attack whilst he's distracted";
    const char FightMsg3[255] = "You ask how he's the son of man yet has an apple for the face. \nThis makes him wonder how he was conceived";

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


#endif //MUSEUMGAME_APPLEBATTLE_H
