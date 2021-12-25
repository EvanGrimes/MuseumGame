#ifndef MUSEUMGAME_GAME_H
#define MUSEUMGAME_GAME_H
#include <raylib.h>
#include "Assets.h"
#include "BattleManager.h"

#include "TitleScreen.h"
#include "GameState.h"

#include "Battles/MonaBattle.h"


class Game {
public:
    void loop();

    int gameStart = 0;
    int gameInit = 0;

    int IntroCount = 0;

    Map map;
    BattleManager battleManager;

    MonaBattle MonaObj;



    TitleScreen titleScreen;
    GameState gameState;


};


#endif //MUSEUMGAME_GAME_H
