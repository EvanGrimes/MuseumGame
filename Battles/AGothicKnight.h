#ifndef MUSEUMGAME_AGOTHICKNIGHT_H
#define MUSEUMGAME_AGOTHICKNIGHT_H

#define SIDE_PLAYER_HOR_SPD 200.0f

#include "../Assets.h"

typedef struct SidePlayer {
    Vector2 position;
} SidePlayer;

typedef struct Enemy{
    Rectangle BodyRec = {700, 460, 20, 20};
} Enemy;

typedef struct Bullet {
    Rectangle bulletRec = {0, 0, 0 ,0};
    float speed = 10;
    static void Draw(const Bullet& bullet){
        DrawRectangleRec(bullet.bulletRec, RED);
    }
} Bullet;



typedef struct Grenade {
    Rectangle grenadeRec = {0, 0, 0 ,0};
    int explosionTime = 20;
    int airTime = 75;
    int explodeTime = 50;
    static void Draw(Grenade grenade){
        DrawRectangleRec(grenade.grenadeRec, BLACK);
    }
    void Explode(Grenade grenade){
        if(explodeTime >= 1){
            if(explosionTime >= 2){
                DrawRectangleRec(grenade.grenadeRec, YELLOW);
                explodeTime--;
            }
        }
        else grenade.grenadeRec.x = 1002;
    };
} Grenade;



class AGothicKnight {
public:

    const char FightMsg1[255] = "You ask her who she was modeled after during her painting and send her through an\nexistential crisis";
    const char FightMsg2[255] = "You ask her if she has any legs below the frame. She looks down and you attack while she's\ndistracted";
    const char FightMsg3[255] = "You tell her that she might not be a finished painting, and this sends her into shock.";

    int BullshitCritCount = 0;

    int frameCounter = 0;
    double textFrame = 0;

    int FightMsg = 0;
    int tempCount = 0;

    Bullet bullets[19];
    Grenade grenades;

    int bulletCounter = 0;
    bool grenadeInAir;

    bool temp = false;

    bool IsBossDead = false;
    bool IsPlayerDead = false;

    float deltaTime;
    Rectangle MapCollision = {0, 500, 1000, 150};
    SidePlayer player = {{500, 460}};
    Enemy GothicGuy = {{700, 460, 20, 20}};
    std::string lastAnim;
    Rectangle playerRect = {  player.position.x , player.position.y + 20, 20, 20};

    bool airBorne = false;
    int jumpHeight;

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


    void UpdatePlayer(SidePlayer *playerP, float delta)
    {
        playerRect.x = player.position.x;
        playerRect.y = player.position.y;

        if(CheckCollisionRecs(MapCollision, (Rectangle){playerRect.x + 1, playerRect.y + (float) 0.1, playerRect.width, playerRect.height})) {
            player.position.y -= 1;
        }
        if(!airBorne && !CheckCollisionRecs(MapCollision, (Rectangle){playerRect.x + 1, playerRect.y + (float) 0.1, playerRect.width, playerRect.height})) {
            player.position.y += 1;
        }

        if (IsKeyDown(KEY_A)) {
            if(!IsKeyDown(KEY_D)) {
                playerP->position.x -= SIDE_PLAYER_HOR_SPD * delta;
                lastAnim = "left";
            }
        }
        if (IsKeyDown(KEY_D)) {
            if(!IsKeyDown(KEY_A)) {
                playerP->position.x += SIDE_PLAYER_HOR_SPD * delta;
                lastAnim = "right";
            }
        }

        if(IsKeyDown(KEY_SPACE)){
            airBorne = true;
        }

        if(airBorne){
            if(jumpHeight >= 50){
                player.position.y += 2.3;
            }
            else{
                player.position.y -= 2.1;
                jumpHeight+= 2;
            }
            if(jumpHeight > 5){
                if(CheckCollisionRecs(MapCollision, (Rectangle){playerRect.x, playerRect.y + (float) 0.1, playerRect.width,playerRect.height})){
                    airBorne = false;
                    jumpHeight = 0;
                }
            }
        }

        if(IsGamepadAvailable(0)){
            if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {

                if(!IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {

                    playerP->position.x -= SIDE_PLAYER_HOR_SPD * delta;
                    lastAnim = "left";
                    playerP->position.x += SIDE_PLAYER_HOR_SPD * delta;

                    lastAnim = "left";
                }
            }
            if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
                if(!IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
                    playerP->position.x += SIDE_PLAYER_HOR_SPD * delta;
                    lastAnim = "right";
                    playerP->position.x -= SIDE_PLAYER_HOR_SPD * delta;
                    lastAnim = "right";
                }
            }
        }


    }

    void UpdateEnemy(Enemy enemy){

        enemy.BodyRec.x -= 200;
    }
};


#endif //MUSEUMGAME_AGOTHICKNIGHT_H
