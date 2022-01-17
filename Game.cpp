/* Command for web-dev
 * em++ -o WebBuild/game.html Assets.cpp BattleManager.cpp Game.cpp GameState.cpp Map.cpp
 * MapReader.cpp TitleScreen.cpp Battles/MonaBattle.cpp Battles/AGothicBattle.cpp -Os -Wall
 * ./libraylib.a -I. -I C:/raylib/raylib/src/raylib.h -L. -LC:/raylib/raylib/src/libraylib.a
 * --preload-file res --shell-file shell.html -s ASYNCIFY -s USE_GLFW=3 -DPLATFORM_WEB
*/




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
                        DrawTextBox("You have defeated the Mona Lisa and have won the game\n Congratulations!");
                        if(IsKeyPressed(KEY_L)){
                           textFrame = 0;
                           Assets::gameState = "title";
                           MonaObj.IsBossDead = false;
                            MonaObj.CurrHealth.width = MonaObj.HeathBack.width;
                            MonaObj.PlayerCurrHealth.width = MonaObj.HeathBack.width;
                           break;
                        }
                        else{
                            DrawTextBox("You have defeated the Mona Lisa and have won the game\n Congratulations!");
                        }
                    }
                    if(MonaObj.IsPlayerDead){
                        DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        if(IsKeyPressed(KEY_L)){
                            textFrame = 0;
                            Assets::gameState = "game";
                            MonaObj.IsPlayerDead = false;
                            MonaObj.CurrHealth.width = MonaObj.HeathBack.width;
                            MonaObj.PlayerCurrHealth.width = MonaObj.HeathBack.width;
                            StopMusicStream(Assets::BattleMusic);
                            break;
                        }
                        else{
                            DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        }
                    }
                    break;
                case 'S':
                    if(!starryBattleObj.IsBossDead){
                        starryBattleObj.tick();
                    }
                    if(starryBattleObj.IsBossDead) {
                        DrawTextBox(
                                "You have defeated the Starry Night!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        if (IsKeyPressed(KEY_L)) {
                            textFrame = 0;
                            Assets::gameState = "game";
                            break;
                        } else {
                            DrawTextBox(
                                    "You have defeated the Starry Night!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        }
                    }
                        if(starryBattleObj.IsPlayerDead){
                            DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                            if(IsKeyPressed(KEY_L)){
                                textFrame = 0;
                                Assets::gameState = "game";
                                starryBattleObj.IsPlayerDead = false;
                                starryBattleObj.CurrHealth.width = MonaObj.HeathBack.width;
                                starryBattleObj.PlayerCurrHealth.width = MonaObj.HeathBack.width;
                                StopMusicStream(Assets::BattleMusic);
                                break;
                            }
                            else{
                                DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                            }
                        }
                    break;
                case 's':
                    if(!screamBattleObj.IsBossDead){
                        screamBattleObj.tick();
                    }
                    if(screamBattleObj.IsBossDead) {
                        DrawTextBox(
                                "You have defeated the Random Screaming Man!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        if (IsKeyPressed(KEY_L)) {
                            textFrame = 0;
                            Assets::gameState = "game";
                            break;
                        } else {
                            DrawTextBox(
                                    "You have defeated the Random Screaming!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        }
                    }
                        if(screamBattleObj.IsPlayerDead){
                            DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                            if(IsKeyPressed(KEY_L)){
                                textFrame = 0;
                                Assets::gameState = "game";
                                screamBattleObj.IsPlayerDead = false;
                                screamBattleObj.CurrHealth.width = MonaObj.HeathBack.width;
                                screamBattleObj.PlayerCurrHealth.width = MonaObj.HeathBack.width;
                                StopMusicStream(Assets::BattleMusic);
                                break;
                            }
                            else{
                                DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                            }
                        }
                    break;
                case 'p':
                    if(!pipeBattleObj.IsBossDead){
                        pipeBattleObj.tick();
                    }
                        if(pipeBattleObj.IsBossDead) {
                            DrawTextBox(
                                    "You have defeated the Pipe(?)!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                            if (IsKeyPressed(KEY_L)) {
                                textFrame = 0;
                                Assets::gameState = "game";
                                break;
                            } else {
                                DrawTextBox(
                                        "You have defeated the Pipe(?)!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                            }
                        }
                            if(pipeBattleObj.IsPlayerDead){
                                DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                                if(IsKeyPressed(KEY_L)){
                                    textFrame = 0;
                                    Assets::gameState = "game";
                                    pipeBattleObj.IsPlayerDead = false;
                                    pipeBattleObj.CurrHealth.width = MonaObj.HeathBack.width;
                                    pipeBattleObj.PlayerCurrHealth.width = MonaObj.HeathBack.width;
                                    StopMusicStream(Assets::BattleMusic);
                                    break;
                                }
                                else{
                                    DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                                }
                            }
                    break;
                case 'f':
                    if(!aGothicBattleObj.IsBossDead){
                        aGothicBattleObj.tick();
                    }
                    if(aGothicBattleObj.IsBossDead){
                        DrawTextBox("You have defeated the American Gothic Farmers!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        if(IsKeyPressed(KEY_L)){
                            textFrame = 0;
                            Assets::gameState = "game";
                            break;
                        }
                        else{
                            DrawTextBox("You have defeated the American Gothic Farmers!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        }
                    }
                    if(aGothicBattleObj.IsPlayerDead){
                        DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        if(IsKeyPressed(KEY_L)){
                            textFrame = 0;
                            Assets::gameState = "game";
                            aGothicBattleObj.IsPlayerDead = false;
                            aGothicBattleObj.CurrHealth.width = aGothicBattleObj.HeathBack.width;
                            aGothicBattleObj.PlayerCurrHealth.width = aGothicBattleObj.HeathBack.width;
                            StopMusicStream(Assets::BattleMusic);
                            break;
                        }
                        else{
                            DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        }
                    }
                    break;
                case 'G':
                    if(!earGirlBattleObj.IsBossDead){
                        earGirlBattleObj.tick();
                    }
                    if(earGirlBattleObj.IsBossDead) {
                        DrawTextBox("You have defeated the Girl With A Pearl Earring!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        if (IsKeyPressed(KEY_L)) {
                            textFrame = 0;
                            Assets::gameState = "game";
                            break;
                        } else {
                            DrawTextBox("You have defeated the Girl With A Pearl Earring!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        }
                    }
                    if(earGirlBattleObj.IsPlayerDead){
                        DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        if(IsKeyPressed(KEY_L)){
                            textFrame = 0;
                            Assets::gameState = "game";
                            earGirlBattleObj.IsPlayerDead = false;
                            earGirlBattleObj.CurrHealth.width = MonaObj.HeathBack.width;
                            earGirlBattleObj.PlayerCurrHealth.width = MonaObj.HeathBack.width;
                            StopMusicStream(Assets::BattleMusic);
                            break;
                        }
                        else{
                            DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        }
                    }
                case 'w':
                    if(!waveBattleObj.IsBossDead){
                        waveBattleObj.tick();
                    }
                    if(waveBattleObj.IsBossDead) {
                        DrawTextBox(
                                "You have defeated the Great Wave Off Kanagawa!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        if (IsKeyPressed(KEY_L)) {
                            textFrame = 0;
                            Assets::gameState = "game";
                            break;
                        } else {
                            DrawTextBox(
                                    "You have defeated the Great Wave Off Kanagawa!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        }
                    }
                    if(waveBattleObj.IsPlayerDead){
                        DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        if(IsKeyPressed(KEY_L)){
                            textFrame = 0;
                            Assets::gameState = "game";
                            waveBattleObj.IsPlayerDead = false;
                            waveBattleObj.CurrHealth.width = MonaObj.HeathBack.width;
                            waveBattleObj.PlayerCurrHealth.width = MonaObj.HeathBack.width;
                            StopMusicStream(Assets::BattleMusic);
                            break;
                        }
                        else{
                            DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        }
                    }
                    break;
                case 'a':
                    if(!appleBattleObj.IsBossDead){
                        appleBattleObj.tick();
                    }
                    if(appleBattleObj.IsBossDead) {
                        DrawTextBox(
                                "You have defeated the Son Of Man!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        if (IsKeyPressed(KEY_L)) {
                            textFrame = 0;
                            Assets::gameState = "game";
                            break;
                        } else {
                            DrawTextBox(
                                    "You have defeated the Son Of Man!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        }
                    }
                    if(appleBattleObj.IsPlayerDead){
                        DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        if(IsKeyPressed(KEY_L)){
                            textFrame = 0;
                            Assets::gameState = "game";
                            appleBattleObj.IsPlayerDead = false;
                            appleBattleObj.CurrHealth.width = MonaObj.HeathBack.width;
                            appleBattleObj.PlayerCurrHealth.width = MonaObj.HeathBack.width;
                            StopMusicStream(Assets::BattleMusic);
                            break;
                        }
                        else{
                            DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        }
                    }
                    break;
                case 'g':
                    if(!georgeBattleObj.IsBossDead){
                        georgeBattleObj.tick();
                    }
                    if(georgeBattleObj.IsBossDead) {
                        DrawTextBox(
                                "You have defeated George Washington!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        if (IsKeyPressed(KEY_L)) {
                            textFrame = 0;
                            Assets::gameState = "game";
                            break;
                        } else {
                            DrawTextBox(
                                    "You have defeated George Washington!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        }
                    }
                    if(georgeBattleObj.IsPlayerDead){
                        DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        if(IsKeyPressed(KEY_L)){
                            textFrame = 0;
                            Assets::gameState = "game";
                            georgeBattleObj.IsPlayerDead = false;
                            georgeBattleObj.CurrHealth.width = MonaObj.HeathBack.width;
                            georgeBattleObj.PlayerCurrHealth.width = MonaObj.HeathBack.width;
                            StopMusicStream(Assets::BattleMusic);
                            break;
                        }
                        else{
                            DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        }
                    }
                    break;
                case 'h':
                    if(!farmManBattleObj.IsBossDead){
                        farmManBattleObj.tick();
                    }
                    if(farmManBattleObj.IsBossDead) {
                        DrawTextBox(
                                "You have defeated the Farm Man!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        if (IsKeyPressed(KEY_L)) {
                            textFrame = 0;
                            Assets::gameState = "game";
                            break;
                        } else {
                            DrawTextBox(
                                    "You have defeated the Farm Man!\n Congratulations! However, your fight is not yet over. Continue onwards!");
                        }
                    }
                    if(farmManBattleObj.IsPlayerDead){
                        DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        if(IsKeyPressed(KEY_L)){
                            textFrame = 0;
                            Assets::gameState = "game";
                            farmManBattleObj.IsPlayerDead = false;
                            farmManBattleObj.CurrHealth.width = MonaObj.HeathBack.width;
                            farmManBattleObj.PlayerCurrHealth.width = MonaObj.HeathBack.width;
                            StopMusicStream(Assets::BattleMusic);
                            break;
                        }
                        else{
                            DrawTextBox("You have died whilst in battle. Do not give up!\n Try Again!");
                        }
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

void Game::DrawTextBox(const char *Message){
        DrawRectangle(0, 450, 1000, 150, WHITE);
        DrawRectangle(10, 460, 980, 130, BLACK);
        DrawText(TextSubtext(Message, 0, (int) textFrame/10 ), 15, 470, 20, WHITE);
        textFrame += 2.3;
}
