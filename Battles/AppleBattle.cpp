#include "AppleBattle.h"

void AppleBattle::tick() {

}

void AppleBattle::render() {
    ClearBackground(BLACK);
    DrawTexture(Assets::AppleMan, 370, 50, WHITE);

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

void AppleBattle::tickFight() {

}

void AppleBattle::tickItem() {

}

void AppleBattle::tickLeave() {

}

void AppleBattle::DrawTextBox(const char *Message) {
    DrawRectangle(0, 450, 1000, 150, WHITE);
    DrawRectangle(10, 460, 980, 130, BLACK);
    DrawText(TextSubtext(Message, 0, (int) textFrame/10 ), 15, 470, 20, WHITE);
    textFrame += 2.3;
}
