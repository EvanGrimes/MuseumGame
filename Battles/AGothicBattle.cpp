#include "AGothicBattle.h"

void AGothicBattle::tick() {
    frameCounter++;
    if(frameCounter >= 60){
        frameCounter = 0;
    }

    mousePoint = GetMousePosition();

    FightBtnAction = false;
    ItemBtnAction = false;
    LeaveBtnAction = false;

    tickFight();
    tickLeave();
    tickItem();

    BullshitCritCount++;
    if(BullshitCritCount <= 1002){
        BullshitCritCount = 0;
    }

    UpdateMusicStream(Assets::BattleMusic);

    render();
}

void AGothicBattle::render() {
    ClearBackground(BLACK);
    DrawTexture(Assets::AGothic, 370, 50, WHITE);

    DrawRectangleRec(FightBtn, RED);
    DrawTexture(Assets::FightBtn, (int) FightBtn.x, (int) FightBtn.y, WHITE);
    DrawRectangleRec(ItemBtn, BLUE);
    DrawTexture(Assets::ItemBtn, (int) ItemBtn.x, (int) ItemBtn.y, WHITE);
    DrawRectangleRec(LeaveBtn, GREEN);
    DrawTexture(Assets::LeaveBtn, (int) LeaveBtn.x, (int) LeaveBtn.y, WHITE);

    DrawText("Boss HP:", 465, 405, 15, WHITE);
    DrawText("HP:", 485, 440, 15, WHITE);

    DrawRectangleRec(HeathBack, RED);
    DrawRectangleRec(CurrHealth, GREEN);

    DrawRectangleRec(PlayerHealthBack, RED);
    DrawRectangleRec(PlayerCurrHealth, GREEN);

    DrawText( "63 HP", (int) PlayerHealthBack.x, (int) PlayerHealthBack.y, 16, WHITE);

    if(temp){
        tempCount++;
        printf("L PRESSED\n");
        printf("%i", FightMsg);
        if(FightMsg == 1){
            DrawTextBox(FightMsg1);
        }
        if(FightMsg == 2){
            DrawTextBox(FightMsg2);
        }
        if(FightMsg == 3){
            DrawTextBox(FightMsg3);
        }
        if(tempCount >= 10){
            if(IsKeyPressed(KEY_L)){
                printf("L PRESS AGAIN \n");
                textFrame = 0;
                tempCount = 0;
                FightMsg = 0;
                temp = false;
            }
        }
    }
}

void AGothicBattle::tickFight() {
    if (CheckCollisionPointRec(mousePoint, FightBtn)) {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) FightBtnAction = true;
    }
    if (FightBtnAction) {
        std::cout << "FIGHT!\n" << std::endl;

        //Boss taking Damage
        if(BullshitCritCount == 240){
            CurrHealth.width = 0;
        }
        else{
            CurrHealth.width -= rand() % 21 + 10;
        }
        if(CurrHealth.width <= 0){
            printf("boss killed\n");
            IsBossDead = true;
        }

        //Battle message
        temp = true;
        if(frameCounter <= 20){
            FightMsg = 1;
        }
        if(frameCounter <= 40 && frameCounter > 20){
            FightMsg = 2;
        }
        if(frameCounter <= 60 && frameCounter > 40){
            FightMsg = 3;
        }

        //Player taking damage
        if(CurrHealth.width <= CurrHealth.width/2){
            PlayerCurrHealth.width -= (rand() % 24 + 15) * 1.05;
        }
        else{
            PlayerCurrHealth.width -= rand() % 19 + 12;
        }

        if(PlayerCurrHealth.width <= 0){
            IsPlayerDead = true;
        }
    }
}

void AGothicBattle::tickItem() {
    if (CheckCollisionPointRec(mousePoint, ItemBtn)) {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) ItemBtnAction = true;
    }
    if (ItemBtnAction) {
        std::cout << "ITEM!\n" << std::endl;
    }
}

void AGothicBattle::tickLeave() {
    if (CheckCollisionPointRec(mousePoint, LeaveBtn)) {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) LeaveBtnAction = true;
    }
    if (LeaveBtnAction) {
        std::cout << "COWARD!\n" << std::endl;
        StopMusicStream(Assets::BattleMusic);
        Assets::gameState = "game";
    }
}

void AGothicBattle::DrawTextBox(const char *Message) {
    DrawRectangle(0, 450, 1000, 150, WHITE);
    DrawRectangle(10, 460, 980, 130, BLACK);
    DrawText(TextSubtext(Message, 0, (int) textFrame/10 ), 15, 470, 20, WHITE);
    textFrame += 2.3;
}
