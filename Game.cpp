#include "Game.h"

void Game::loop() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        if (Assets::gameState == "title") {
            gameInit = 0;
            titleScreen.tick();
        }

        if (Assets::gameState == "game") {
            if(gameStart == 0){
                //ClearBackground(BLACK);
                //DrawText(TextSubtext(gameState.message, 0, (int) gameState.IntroFrames/10 ), 40, 60, 20, WHITE);
                //gameState.IntroFrames += 1.5;
                //gameState.IntroTimeCount++;
                //IntroCount++;
             }

            //if(IntroCount >= 1560){
                if(gameInit == 0){

                    gameState.IntroFrames = 0;
                    gameStart = 1;

                    Assets::LoadGame();

                    gameState.camera = { {0, 0}, {0, 0}, 0.0f, 0 };
                    gameState.camera.target = (Vector2){ gameState.player.position.x + 20, gameState.player.position.y + 20 };
                    gameState.camera.offset = (Vector2){ 1000/2.0, 600/2.0 };
                    gameState.camera.zoom = 1.5f;

                    gameState.map.mapReader.setMapCollision();

                    gameState.startPlayer();

                    printf("Game assets inited\n");

                    gameInit++;
                }

                BeginMode2D(gameState.camera);
                gameState.tick();
                EndMode2D();
            //}
        }

        if(Assets::gameState == "exit"){
            break;
        }

        EndDrawing();
    }
}
