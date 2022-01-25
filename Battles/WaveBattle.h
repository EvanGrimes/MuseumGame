#ifndef MUSEUMGAME_WAVEBATTLE_H
#define MUSEUMGAME_WAVEBATTLE_H

#include "../Assets.h"

class WaveBattle {
public:

    const char FightMsg1[255] = "You wave goodbye. It's feeling are hurt not only by you leaving, \nbut also by the bad pun";
    const char FightMsg2[255] = "You throw more salt into the ocean";
    const char FightMsg3[255] = "You drink a cup of the ocean's salt water to assert your dominance";

    int BullshitCritCount = 0;

    int frameCounter = 0;
    double textFrame = 0;

    int FightMsg = 0;
    int tempCount = 0;
    bool temp = false;

    bool IsBossDead = false;
    bool IsPlayerDead;

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


#endif //MUSEUMGAME_WAVEBATTLE_H
