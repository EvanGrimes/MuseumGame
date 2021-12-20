//
// Created by 18149 on 12/14/2021.
//

#ifndef MUSEUMGAME_GAMESTATE_H
#define MUSEUMGAME_GAMESTATE_H

#define PLAYER_HOR_SPD 200.0f

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

    Rectangle playerRect = {  player.position.x , player.position.y + 20, 20, 20};

    void startPlayer() {
        player = {{0, 0}, 0};

        player.position = (Vector2) {(float)Assets::screenWidth/2, (float)Assets::screenHeight/2};

        player.speed = 0;
    }

    bool Moving;

    void UpdatePlayer(Player *playerP, float delta)
    {
        Moving = false;

        //Checks for up first
        if (IsKeyDown(KEY_W)){


            if(!IsKeyDown(KEY_S)) {

                //if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.y -= PLAYER_HOR_SPD * delta;
                    printf("move up");

                //    lastAnim = "up";
                //}

                //if(checkCollisionFuture()) {
                    //Moving = true;
                    //playerP->position.y += PLAYER_HOR_SPD * delta;
                //}

                //lastAnim = "up";
            }
        }

        if (IsKeyDown(KEY_S)) {

            if(!IsKeyDown(KEY_W)) {

                //if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.y += PLAYER_HOR_SPD * delta;
                //    lastAnim = "down";
                //}

                //if(checkCollisionFuture()) {
                    //Moving = true;
                    //playerP->position.y -= PLAYER_HOR_SPD * delta;
                //}

                //lastAnim = "down";
            }
        }

        //Checks for movement left
        if (IsKeyDown(KEY_A)) {

            if(!IsKeyDown(KEY_D)) {

                //if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.x -= PLAYER_HOR_SPD * delta;
                //    lastAnim = "left";
                //}

                //If it returns true, it moves the player backward so that you don't go into the tile
                //if(checkCollisionFuture()) {
                    //Moving = true;
                    //playerP->position.x += PLAYER_HOR_SPD * delta;
                //}

                //lastAnim = "left";
            }
        }

        //Checks for movement right
        if (IsKeyDown(KEY_D)) {

            if(!IsKeyDown(KEY_A)) {
                //if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.x += PLAYER_HOR_SPD * delta;

                //    lastAnim = "right";
                //}
                //if(checkCollisionFuture()) {
                    //Moving = true;
                    //playerP->position.x -= PLAYER_HOR_SPD * delta;
                //}
                //lastAnim = "right";
            }
        }

    }

};

#endif //MUSEUMGAME_GAMESTATE_H
