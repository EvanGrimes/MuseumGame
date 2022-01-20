#include "AGothicKnight.h"

//TODO: Hollow knight?????

void AGothicKnight::tick() {
    frameCounter++;
    if(frameCounter >= 60){
        frameCounter = 0;
    }

    deltaTime = GetFrameTime();

    mousePoint = GetMousePosition();

    FightBtnAction = false;
    ItemBtnAction = false;
    LeaveBtnAction = false;

   // tickFight();
   // tickLeave();
   // tickItem();

    UpdatePlayer(&player, deltaTime);


    if(IsKeyPressed(KEY_F) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        if(bulletCounter > 4){
            bulletCounter = 0;
        }
        bullets[bulletCounter].bulletRec = {player.position.x + playerRect.width, player.position.y + playerRect.height / 2, 20, 5};
        bulletCounter++;
    }

    BullshitCritCount++;
    if(BullshitCritCount <= 1002){
        BullshitCritCount = 0;
    }


    UpdateMusicStream(Assets::BattleMusic);

    render();
}

void AGothicKnight::render() {
   ClearBackground(SKYBLUE);
   DrawTexture(Assets::AGothicBG, 0, 0, WHITE);
   DrawRectangleRec(MapCollision, GREEN);

   for(int i = 0; i < 5; i++){
       bullets[i].bulletRec.x += bullets[i].speed;
       bullets[i].Draw(bullets[i]);
   }


   DrawRectangleRec(playerRect, BLUE);
}

void AGothicKnight::tickFight() {

}

void AGothicKnight::tickItem() {
    if (CheckCollisionPointRec(mousePoint, ItemBtn)) {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) ItemBtnAction = true;
    }
    if (ItemBtnAction) {
        std::cout << "ITEM!\n" << std::endl;
    }
}

void AGothicKnight::tickLeave() {
    if (CheckCollisionPointRec(mousePoint, LeaveBtn)) {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) LeaveBtnAction = true;
    }
    if (LeaveBtnAction) {
        std::cout << "COWARD!\n" << std::endl;
        StopMusicStream(Assets::BattleMusic);
        Assets::gameState = "game";
    }
}

void AGothicKnight::DrawTextBox(const char *Message) {
    DrawRectangle(0, 450, 1000, 150, WHITE);
    DrawRectangle(10, 460, 980, 130, BLACK);
    DrawText(TextSubtext(Message, 0, (int) textFrame/10 ), 15, 470, 20, WHITE);
    textFrame += 2.3;
}


