#ifndef MUSEUMGAME_GAME_H
#define MUSEUMGAME_GAME_H
#include <raylib.h>
#include "Assets.h"

#include "TitleScreen.h"

class Game {
public:
    void loop();

    TitleScreen titleScreen;

};


#endif //MUSEUMGAME_GAME_H
