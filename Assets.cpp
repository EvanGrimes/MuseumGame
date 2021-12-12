//
// Created by 18149 on 12/11/2021.
//

#include "Assets.h"

namespace Assets{
    std::string gameState;

    Texture2D titleBG;

    void LoadTitle(){
        titleBG = LoadTexture("../res/textures/BGPlace.png");
    }
}
