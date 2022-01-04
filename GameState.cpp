#include "GameState.h"

void GameState::tick() {
    UpdateMusicStream(Assets::MainBGM);
    deltaTime = GetFrameTime();
    framesCounter++;
    if (framesCounter >= (60/framesSpeed))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 5) currentFrame = 0;
    }

    UpdatePlayer(&player, deltaTime);
    //PaintingPress();

    camera.target.x = player.position.x;
    camera.target.y = player.position.y;

    playerRect = { player.position.x, player.position.y, 8, 15 };

    render();
}

void GameState::render() {
    ClearBackground(BACKGROUND);
    //map.DrawMap();
    DrawRectangleRec(playerRect, BLUE);
    //DrawTexture(Assets::playerTemp, (int) player.position.x, (int) player.position.y, WHITE);
}
