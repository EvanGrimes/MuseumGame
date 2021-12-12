#ifndef MUSEUMGAME_ASSETS_H
#define MUSEUMGAME_ASSETS_H

#include <raylib.h>
#include <iostream>

namespace Assets {
    extern std::string gameState;

    extern Texture2D titleBG;

    void LoadTitle();
}


#endif //MUSEUMGAME_ASSETS_H
