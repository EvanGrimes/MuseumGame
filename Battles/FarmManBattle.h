#ifndef MUSEUMGAME_FARMMANBATTLE_H
#define MUSEUMGAME_FARMMANBATTLE_H

#include "../Assets.h"

class FarmManBattle {
public:

    const char FightMsg1[255] = "You ask where his face begins and the farm ends and this makes him scared";
    const char FightMsg2[255] = "You ask where the farm begins and his face ends and this makes him confused";;
    const char FightMsg3[255] = "You ask if he's balding. While he looks for his hair, you attack him";

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


#endif //MUSEUMGAME_FARMMANBATTLE_H
