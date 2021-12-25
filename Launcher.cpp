#include <raylib.h>

#include "Assets.h"
#include "Game.h"

Game gameObj;

int main(){
    std::cout << "This is a test message you absolute nonce";
    SetTargetFPS(60);
    InitWindow(Assets::screenWidth, Assets::screenHeight, "Pressing Paintings (W.I.P)");
    Assets::gameState = "title";
    Assets::LoadTitle();

    gameObj.loop();

    return  0;
}