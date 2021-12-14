//
// Created by 18149 on 12/11/2021.
//

#include "Assets.h"

namespace Assets{
    std::string gameState;

    int screenWidth = 1000; int screenHeight = 600;
    Texture2D titleBG;
    Texture2D startBtn;
    Texture2D startHover;

    void LoadTitle(){
        titleBG = LoadTexture("../res/textures/BGPlace.png");
        startBtn = LoadTexture("../res/textures/startBtn.png");
        startHover = LoadTexture("../res/textures/startBtnHover.png");
    }
}
