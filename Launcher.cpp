#include <raylib.h>
#include "Assets.h"
#include "Game.h"


Game gameObj;
int main(){
    std::cout << "This is a test message you absolute nonce";
    SetTargetFPS(60);
    InitWindow(1000, 600, "test");
    Assets::gameState = "title";
    while(!WindowShouldClose()){
        gameObj.loop();
    }
    CloseWindow();
    return  0;

}