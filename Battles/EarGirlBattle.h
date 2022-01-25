#ifndef MUSEUMGAME_EARGIRLBATTLE_H
#define MUSEUMGAME_EARGIRLBATTLE_H

#include "../Assets.h"

class EarGirlBattle {
public:

    const char FightMsg1[255] = "You ask why her earring aren't diamond and she gets mad at you.";
    const char FightMsg2[255] = "You tell her that her earrings came from dirty oysters and she becomes \n visibly repulsed";
    const char FightMsg3[255] = "You ask if she has two earrings and she looks and you attack.";

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


#endif //MUSEUMGAME_EARGIRLBATTLE_H
