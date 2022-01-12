#ifndef MUSEUMGAME_ASSETS_H
#define MUSEUMGAME_ASSETS_H

#include <raylib.h>
#include <iostream>

namespace Assets {
    extern int screenWidth, screenHeight;
    extern std::string gameState;
    extern int BattleNum;

    extern Texture2D titleBG;
    extern Texture2D startBtn;
    extern Texture2D startHover;
    extern Texture2D settBtn;
    extern Texture2D exitBtn;

    extern Texture2D playerTemp;
    extern Texture2D pillar;
    extern Texture2D floor;
    extern Texture2D wall;
    extern Texture2D wallTop;
    extern Texture2D rope;
    extern Texture2D painting;
    extern Music MainBGM;

    extern Texture2D FightBtn;
    extern Texture2D ItemBtn;
    extern Texture2D LeaveBtn;
    extern Texture2D MonaL;


    void LoadTitle();
    void LoadGame();
}


#endif //MUSEUMGAME_ASSETS_H
