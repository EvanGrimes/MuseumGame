#ifndef MUSEUMGAME_GAMESTATE_H
#define MUSEUMGAME_GAMESTATE_H

#define PLAYER_HOR_SPD 150.0f
#define BACKGROUND  (Color){ 42, 42, 47, 255 }

#define XBOX360_LEGACY_NAME_ID  "Xbox Controller"
#if defined(PLATFORM_RPI)
#define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else
#define XBOX360_NAME_ID     "Xbox 360 Controller"
#define PS3_NAME_ID         "PLAYSTATION(R)4 Controller"
#endif

#include <raylib.h>

#include "Assets.h"
#include "Map.h"

typedef struct Player {
    Vector2 position;
    float speed;
} Player;


class GameState {
public:

    const char message[255] = "This text will one day be replaced by some kind of dope-ass intro sequence explaining the\nstory of the game. When that is introduced, this text shall cease to exist, so savour it\nwhile you still can!";


    Camera2D camera;

    void tick();
    void render();

    float deltaTime = 0;

    int framesCounter = 0;

    int framesSpeed = 8;

    int currentFrame = 0;

    int IntroTimeCount = 0;
    double IntroFrames = 0;

    Map map;

    Player player;

    Rectangle playerRect = {  player.position.x , player.position.y + 20, 21, 20};

    void startPlayer() {
        player = {{0, 0}, 0};

        player.position = (Vector2) {(float)Assets::screenWidth/2, (float)Assets::screenHeight/2};

        player.speed = 0;
    }
    std::string lastAnim;
    Texture2D GetLastAnim() const;
    bool Moving = false;

    int count = 0;


    bool checkCollisionFuture() {
        for(count = 0; count < MapReader::mapSize; count++){
            playerRect = { player.position.x + 5, player.position.y + 14, 8, 15 };
            if(lastAnim == "left" || "down") {
                if (CheckCollisionRecs(map.mapReader.collision[count],
                                       (Rectangle) {playerRect.x + 1, playerRect.y - 1, playerRect.width,
                                                    playerRect.height})) {
                    printf("COLLISION\n");
                    return true;
                }
            }

            if(lastAnim == "right" || "up"){
                if(CheckCollisionRecs(map.mapReader.collision[count],
                                      (Rectangle){playerRect.x + 1, playerRect.y + (float) 0.1, playerRect.width,
                                                  playerRect.height})){
                    printf("COLLISION\n");
                    return true;
                }
            }
            //DrawRectangleRec(map.mapReader.collision[count], RED);
        }
        return false;
    }

    void UpdatePlayer(Player *playerP, float delta)
    {
        Moving = false;

        if (IsKeyDown(KEY_W)){
            if(!IsKeyDown(KEY_S)) {
                if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.y -= PLAYER_HOR_SPD * delta;
                    lastAnim = "up";
                }
                if(checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.y += PLAYER_HOR_SPD * delta;
                    lastAnim = "up";
                }

            }
        }
        if (IsKeyDown(KEY_S)) {
            if(!IsKeyDown(KEY_W)) {
                if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.y += PLAYER_HOR_SPD * delta;
                    lastAnim = "down";
                }
                if(checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.y -= PLAYER_HOR_SPD * delta;
                    lastAnim = "down";
                }
            }
        }
        if (IsKeyDown(KEY_A)) {

            if(!IsKeyDown(KEY_D)) {

                if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.x -= PLAYER_HOR_SPD * delta;
                    lastAnim = "left";
                }
                if(checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.x += PLAYER_HOR_SPD * delta;
                    lastAnim = "left";
                }
            }
        }
        if (IsKeyDown(KEY_D)) {
            if(!IsKeyDown(KEY_A)) {
                if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.x += PLAYER_HOR_SPD * delta;
                    lastAnim = "right";
                }
                if(checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.x -= PLAYER_HOR_SPD * delta;
                    lastAnim = "right";
                }
            }
        }

        if(IsGamepadAvailable(0)){
            if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP)){
                if(!IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) {
                    if(!checkCollisionFuture()) {
                        Moving = true;
                        playerP->position.y -= PLAYER_HOR_SPD * delta;
                        lastAnim = "up";
                    }
                    if(checkCollisionFuture()) {
                        Moving = true;
                        playerP->position.y += PLAYER_HOR_SPD * delta;
                        lastAnim = "up";
                    }

                }
            }
            if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) {
                if(!IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) {
                    if(!checkCollisionFuture()) {
                        Moving = true;
                        playerP->position.y += PLAYER_HOR_SPD * delta;
                        lastAnim = "down";
                    }
                    if(checkCollisionFuture()) {
                        Moving = true;
                        playerP->position.y -= PLAYER_HOR_SPD * delta;
                        lastAnim = "down";
                    }
                }
            }
            if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {

                if(!IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {

                    if(!checkCollisionFuture()) {
                        Moving = true;
                        playerP->position.x -= PLAYER_HOR_SPD * delta;
                        lastAnim = "left";
                    }
                    if(checkCollisionFuture()) {
                        Moving = true;
                        playerP->position.x += PLAYER_HOR_SPD * delta;
                        lastAnim = "left";
                    }
                }
            }
            if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
                if(!IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
                    if(!checkCollisionFuture()) {
                        Moving = true;
                        playerP->position.x += PLAYER_HOR_SPD * delta;
                        lastAnim = "right";
                    }
                    if(checkCollisionFuture()) {
                        Moving = true;
                        playerP->position.x -= PLAYER_HOR_SPD * delta;
                        lastAnim = "right";
                    }
                }
            }
        }


    }

    void PaintingPress(){
            if (CheckCollisionRecs(map.mapReader.collision[count],
                                   (Rectangle) {playerRect.x + 1, playerRect.y + 0.5f, playerRect.width,
                                                playerRect.height})) {
                if(CheckForPainting()){
                    if(IsKeyPressed(KEY_E)){
                        printf("Painting Pressed\n");
                        std::cout << map.mapReader.PaintingType[count] << "\n";
                        Assets::BattleNum = map.mapReader.PaintingType[count];
                        Assets::gameState = "battle";
                    }
                    if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
                        printf("Painting Pressed\n");
                        std::cout << map.mapReader.PaintingType[count] << "\n";
                        Assets::BattleNum = map.mapReader.PaintingType[count];
                        Assets::gameState = "battle";
                    }
                }
            }
    }

    bool CheckForPainting(){
        if(map.mapReader.IsPainting[count]){
            return true;
        }
        else
            return false;
    }
};
#endif
