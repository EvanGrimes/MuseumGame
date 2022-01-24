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
    UpdateEnemy(GothicGuy);


    if(IsKeyPressed(KEY_F) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        if(bulletCounter >= 10){
            bulletCounter = 0;
        }
        bullets[bulletCounter].bulletRec = {player.position.x + playerRect.width, player.position.y + playerRect.height / 2, 20, 5};
        bulletCounter++;
    }
    if((IsKeyPressed(KEY_Q) || IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) && !grenadeInAir){
        grenades.grenadeRec = {player.position.x + playerRect.width, player.position.y + 2, 10, 10};
        grenadeInAir = true;
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

   for(int i = 0; i < 10; i++){
       bullets[i].bulletRec.x += bullets[i].speed;
       Bullet::Draw(bullets[i]);
   }

   if(grenadeInAir){
       if(CheckCollisionRecs((Rectangle) {grenades.grenadeRec.x, grenades.grenadeRec.y + 5, grenades.grenadeRec.width, grenades.grenadeRec.height}, MapCollision)){
           grenades.Explode(grenades);
           grenades.airTime = 75;
           grenadeInAir = false;
       }
       else{
           Grenade::Draw(grenades);
           if(grenades.airTime >= 2){
               grenades.grenadeRec.x++;
               grenades.grenadeRec.y -= 2.578;
               grenades.airTime--;
               std::cout << grenades.airTime << "\n";
           }
           else{
               grenades.grenadeRec.x++;
               grenades.grenadeRec.y += 1.4;
           }

       }
   }


   DrawRectangleRec(playerRect, BLUE);
   DrawRectangleRec(GothicGuy.BodyRec, YELLOW);
}

void AGothicKnight::tickFight() {

}

/*void AGothicKnight::tickItem() {
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
}*/

void AGothicKnight::DrawTextBox(const char *Message) {
    DrawRectangle(0, 450, 1000, 150, WHITE);
    DrawRectangle(10, 460, 980, 130, BLACK);
    DrawText(TextSubtext(Message, 0, (int) textFrame/10 ), 15, 470, 20, WHITE);
    textFrame += 2.3;
}


