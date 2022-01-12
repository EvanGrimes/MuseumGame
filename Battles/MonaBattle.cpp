#include "MonaBattle.h"

void MonaBattle::tick() {
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

    if(IsKeyPressed(KEY_L)){
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
    }

    render();
}

void MonaBattle::render() {
    ClearBackground(BLACK);
    DrawTexture(Assets::MonaL, 370, 50, WHITE);

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

    DrawText( "47 HP", (int) PlayerHealthBack.x, (int) PlayerHealthBack.y, 16, WHITE);

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

void MonaBattle::tickFight() {
    if (CheckCollisionPointRec(mousePoint, FightBtn)) {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) FightBtnAction = true;
    }
    if (FightBtnAction) {
        std::cout << "FIGHT!\n" << std::endl;
        if(BullshitCritCount == 240){
            CurrHealth.width = 0;
        }
        else{
                CurrHealth.width -= rand() % 25 + 18;
        }
        if(CurrHealth.width <= 0){
            IsBossDead = true;
        }
        PlayerCurrHealth.width -= rand() % 25 + 10;
    }
}

void MonaBattle::tickItem() {
    if (CheckCollisionPointRec(mousePoint, ItemBtn)) {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) ItemBtnAction = true;
    }
    if (ItemBtnAction) {
        std::cout << "ITEM!\n" << std::endl;
    }
}

void MonaBattle::tickLeave() {
    if (CheckCollisionPointRec(mousePoint, LeaveBtn)) {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) LeaveBtnAction = true;
    }
    if (LeaveBtnAction) {
        std::cout << "COWARD!\n" << std::endl;
        Assets::gameState = "game";
    }
}

void MonaBattle::DrawTextBox(const char* Message){
    DrawRectangle(0, 450, 1000, 150, WHITE);
    DrawRectangle(10, 460, 980, 130, BLACK);
    DrawText(TextSubtext(Message, 0, (int) textFrame/10 ), 15, 470, 20, WHITE);
    textFrame += 2.3;
}
