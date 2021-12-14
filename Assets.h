#ifndef MUSEUMGAME_ASSETS_H
#define MUSEUMGAME_ASSETS_H

#include <raylib.h>
#include <iostream>

namespace Assets {
    extern int screenWidth, screenHeight;
    extern std::string gameState;

    extern Texture2D titleBG;
    extern Texture2D startBtn;
    extern Texture2D startHover;

    void LoadTitle();
}


#endif //MUSEUMGAME_ASSETS_H
