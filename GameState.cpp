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
    PaintingPress();

    camera.target.x = player.position.x;
    camera.target.y = player.position.y;

    playerRect = { player.position.x, player.position.y, 8, 15 };

    render();
}

void GameState::render() {
    ClearBackground(BACKGROUND);
    map.DrawMap();
    //DrawRectangleRec(playerRect, BLUE);
    DrawTexture(GetLastAnim(), (int)player.position.x - 10, (int)player.position.y - 10, WHITE);
    //DrawTexture(Assets::playerTemp, (int) player.position.x, (int) player.position.y, WHITE);
}

Texture2D GameState::GetLastAnim() const {
    if(Moving) {
        if (lastAnim == "up") {
            return Assets::playerUp[currentFrame];
        }
        if (lastAnim == "down") {
            return Assets::playerDown[currentFrame];
        }
        if (lastAnim == "left") {
            return Assets::playerLeft[currentFrame];
        }
        if (lastAnim == "right") {
            return Assets::playerRight[currentFrame];
        }
    }

    else {
        if (lastAnim == "up") {
            return Assets::playerIdle[0];
        }
        if (lastAnim == "down") {
            return Assets::playerIdle[1];
        }
        if (lastAnim == "left") {
            return Assets::playerIdle[2];
        }
        if (lastAnim == "right") {
            return Assets::playerIdle[3];
        }
        else{
            return Assets::playerIdle[1];
        }
    }
    return Assets::playerIdle[1];
}
