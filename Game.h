#ifndef MUSEUMGAME_GAME_H
#define MUSEUMGAME_GAME_H
#include <raylib.h>
#include "Assets.h"
#include "BattleManager.h"

#include "TitleScreen.h"
#include "GameState.h"

#include "Battles/MonaBattle.h"
#include "Battles/StarryBattle.h"
#include "Battles/ScreamBattle.h"
#include "Battles/PipeBattle.h"
#include "Battles/AGothicBattle.h"
#include "Battles/EarGirlBattle.h"
#include "Battles/WaveBattle.h"
#include "Battles/AppleBattle.h"
#include "Battles/GeorgeBattle.h"
#include "Battles/FarmManBattle.h"


class Game {
public:
    void loop();

    int gameStart = 0;
    int gameInit = 0;

    int IntroCount = 0;

    Map map;
    BattleManager battleManager;

    TitleScreen titleScreen;
    GameState gameState;

    MonaBattle MonaObj;
    StarryBattle starryBattleObj;
    ScreamBattle screamBattleObj;
    PipeBattle pipeBattleObj;
    AGothicBattle aGothicBattleObj;
    EarGirlBattle earGirlBattleObj;
    WaveBattle waveBattleObj;
    AppleBattle appleBattleObj;
    GeorgeBattle georgeBattleObj;
    FarmManBattle farmManBattleObj;
};


#endif //MUSEUMGAME_GAME_H
