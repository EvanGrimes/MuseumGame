#include "Assets.h"

namespace Assets{
    std::string gameState;
    int BattleNum;

    int screenWidth = 1000; int screenHeight = 600;
    Texture2D titleBG;
    Texture2D startBtn;
    Texture2D startHover;
    Texture2D settBtn;
    Texture2D exitBtn;

    Texture2D pillar;
    Texture2D floor;
    Texture2D wall;
    Texture2D wallTop;
    Texture2D rope;
    Texture2D painting;

    void LoadTitle(){
        titleBG = LoadTexture("../res/textures/BGPlace.png");
        startBtn = LoadTexture("../res/textures/startBtn.png");
        startHover = LoadTexture("../res/textures/startBtnHover.png");
        settBtn = LoadTexture("../res/textures/gear.png");
        exitBtn = LoadTexture("../res/textures/exitLeft.png");
    }

    void LoadGame(){
        pillar = LoadTexture("../res/textures/pillar.png");
        floor = LoadTexture("../res/textures/floor.png");
        wall = LoadTexture("../res/textures/wall.png");
        wallTop = LoadTexture("../res/textures/wallTop.png");
        painting = LoadTexture("../res/textures/painting2.png");
        rope = LoadTexture("../res/textures/rope.png");

    }
}
