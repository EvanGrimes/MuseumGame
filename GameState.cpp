//
// Created by 18149 on 12/14/2021.
//

#include "GameState.h"

void GameState::tick() {
    deltaTime = GetFrameTime();
    framesCounter++;
    if (framesCounter >= (60/framesSpeed))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 5) currentFrame = 0;
    }

    UpdatePlayer(&player, deltaTime);

    camera.target.x = player.position.x;
    camera.target.y = player.position.y;

    playerRect = { player.position.x, player.position.y, 8, 15 };

    render();
}

void GameState::render() {
    ClearBackground(GREEN);
    map.DrawMap();
    DrawRectangleRec(playerRect, RED);
}
