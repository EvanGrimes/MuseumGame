#ifndef MUSEUMGAME_MONABATTLE_H
#define MUSEUMGAME_MONABATTLE_H

#define DARKRED  (Color){ 37, 0, 1, 255 }

#include "../Assets.h"
#include <random>

class MonaBattle {
public:

    const char FightMsg1[255] = "You ask her who she was modeled after during her painting and send her through an\nexistential crisis";
    const char FightMsg2[255] = "You ask her if she has any legs below the frame. She looks down and you attack while she's\ndistracted";
    const char FightMsg3[255] = "You tell her that she might not be a finished painting, and this sends her into shock.";

    int BullshitCritCount;

    int frameCounter = 0;
    double textFrame = 0;

    int FightMsg;
    int tempCount;
    bool temp;

    bool IsBossDead = false;
    bool IsPlayerDead = false;

    Rectangle FightBtn = {20,475,257, 97 };
    Rectangle ItemBtn = {370,475,257, 97 };
    Rectangle LeaveBtn = {720,475,257, 97 };
    Rectangle HeathBack = {370, 420, 235, 16};
    Rectangle CurrHealth = HeathBack;

    bool BossDamage = false;

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


#endif //MUSEUMGAME_MONABATTLE_H
