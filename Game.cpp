//
// Created by 18149 on 12/11/2021.
//

#include "Game.h"

void Game::loop() {
    BeginDrawing();
    if(Assets::gameState == "title"){
        titleScreen.tick();
    }
    if(Assets::gameState == "game"){
        if(IsKeyPressed(KEY_P)){
            std::cout << "mouse go brrrrrr";
            Assets::gameState = "title";
        }
        ClearBackground(YELLOW);
    }

    EndDrawing();

}
