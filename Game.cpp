#include "Game.h"

void Game::loop() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        if (Assets::gameState == "title") {
            gameInit = 0;
            titleScreen.tick();
        }

        if (Assets::gameState == "game") {
            //if(gameStart == 0){
            //    ClearBackground(BLACK);
            //    DrawText(TextSubtext(gameState.message, 0, (int) gameState.IntroFrames/10 ), 40, 60, 20, WHITE);
            //    gameState.IntroFrames += 1.5;
            //    gameState.IntroTimeCount++;
            //    IntroCount++;
            // }

            //if(IntroCount >= 1560){
                if(gameInit == 0){
                    Assets::LoadGame();

                    gameState.IntroFrames = 0;
                    gameStart = 1;

                    gameState.camera = { {0, 0}, {0, 0}, 0.0f, 0 };
                    gameState.camera.target = (Vector2){ gameState.player.position.x + 20, gameState.player.position.y + 20 };
                    gameState.camera.offset = (Vector2){ 1000/2.0, 600/2.0 };
                    gameState.camera.zoom = 2.5f;

                    gameState.map.mapReader.setMapCollision();

                    gameState.startPlayer();

                    printf("Game assets inited\n");
                    SetMusicVolume(Assets::MainBGM, 0.1f);
                    PlayMusicStream(Assets::MainBGM);
                    gameInit++;
                }
                //}
                BeginMode2D(gameState.camera);
                gameState.tick();
                EndMode2D();
        }

        if(Assets::gameState == "battle"){
            SetMusicVolume(Assets::BattleMusic, 0.1f);
            PlayMusicStream(Assets::BattleMusic);
            switch(BattleManager::BattlePicker(Assets::BattleNum)){
                case 'M':
                    if(!MonaObj.IsBossDead){
                        MonaObj.tick();
                    }
                    if(MonaObj.IsBossDead){
                        Assets::gameState = "game";
                    }
                    break;
                case 'S':
                    if(!starryBattleObj.IsBossDead){
                        starryBattleObj.tick();
                    }
                    if(starryBattleObj.IsBossDead){
                        Assets::gameState = "game";
                    }
                    break;
                case 's':
                    if(!screamBattleObj.IsBossDead){
                        screamBattleObj.tick();
                    }
                    if(screamBattleObj.IsBossDead){
                        Assets::gameState = "game";
                    }
                    break;
                case 'p':
                    if(!pipeBattleObj.IsBossDead){
                        pipeBattleObj.tick();
                    }
                    if(pipeBattleObj.IsBossDead){
                        Assets::gameState = "game";
                    }
                    break;
                case 'f':
                    if(!aGothicBattleObj.IsBossDead){
                        aGothicBattleObj.tick();
                    }
                    if(aGothicBattleObj.IsBossDead){
                        Assets::gameState = "game";
                    }
                    break;
                case 'G':
                    if(!earGirlBattleObj.IsBossDead){
                        earGirlBattleObj.tick();
                    }
                    if(earGirlBattleObj.IsBossDead){
                        Assets::gameState = "game";
                    }
                case 'w':
                    if(!waveBattleObj.IsBossDead){
                        waveBattleObj.tick();
                    }
                    if(waveBattleObj.IsBossDead){
                        Assets::gameState = "game";
                    }
                    break;
                case 'a':
                    if(!appleBattleObj.IsBossDead){
                        appleBattleObj.tick();
                    }
                    if(appleBattleObj.IsBossDead){
                        Assets::gameState = "game";
                    }
                    break;
                case 'g':
                    if(!georgeBattleObj.IsBossDead){
                        georgeBattleObj.tick();
                    }
                    if(georgeBattleObj.IsBossDead){
                        Assets::gameState = "game";
                    }
                    break;
                case 'h':
                    if(!farmManBattleObj.IsBossDead){
                        farmManBattleObj.tick();
                    }
                    if(farmManBattleObj.IsBossDead){
                        Assets::gameState = "game";
                    }
                    break;
                default:
                    printf("ERROR: NO MATCHING BATTLE. CLOSING GAME");
                    Assets::gameState = "exit";
                    break;
            }
        }

        if(Assets::gameState == "exit"){
            break;
        }

        EndDrawing();
    }
}
