#include "Assets.h"
#include <raylib.h>

namespace Assets{
    std::string gameState;
    int BattleNum;

    int screenWidth = 1000; int screenHeight = 600;
    Texture2D titleBG;
    Texture2D startBtn;
    Texture2D startHover;
    Texture2D settBtn;
    Texture2D exitBtn;

    Texture2D playerTemp;
    Texture2D pillar;
    Texture2D floor;
    Texture2D wall;
    Texture2D wallTop;
    Texture2D rope;
    Texture2D painting;
    Music MainBGM;

    Texture2D FightBtn;
    Texture2D ItemBtn;
    Texture2D LeaveBtn;
    Music BattleMusic;

    Texture2D MonaL;
    Texture2D StarryN;
    Texture2D Scream;
    Texture2D Pipe;
    Texture2D AGothic;
    Texture2D EarGirl;
    Texture2D Wave;
    Texture2D AppleMan;
    Texture2D GeorgeW;
    Texture2D FarmMan;

    void LoadTitle(){
        titleBG = LoadTexture("../res/textures/BGPlace.png");
        startBtn = LoadTexture("../res/textures/startBtn.png");
        startHover = LoadTexture("../res/textures/startBtnHover.png");
        settBtn = LoadTexture("../res/textures/gear.png");
        exitBtn = LoadTexture("../res/textures/exitLeft.png");
    }

    void LoadGame(){
        playerTemp = LoadTexture("../res/sprites/playerTemp2.png");
        pillar = LoadTexture("../res/textures/pillar.png");
        floor = LoadTexture("../res/textures/floor.png");
        wall = LoadTexture("../res/textures/wall.png");
        wallTop = LoadTexture("../res/textures/wallTop.png");
        painting = LoadTexture("../res/textures/painting2.png");
        rope = LoadTexture("../res/textures/rope.png");
        MainBGM = LoadMusicStream("../res/music/MainMusic.ogg");

        BattleMusic = LoadMusicStream("../res/music/BattleMusic.ogg");

        FightBtn = LoadTexture("../res/textures/FightBtn.png");
        ItemBtn = LoadTexture("../res/textures/ItemBtn.png");
        LeaveBtn = LoadTexture("../res/textures/LeaveBtn.png");;

        MonaL = LoadTexture("../res/paintings/MonaLisa.png");
        StarryN = LoadTexture("../res/paintings/StarryNight.png");
        Scream = LoadTexture("../res/paintings/Scream.png");
        Pipe = LoadTexture("../res/paintings/Pipe.png");
        AGothic = LoadTexture("../res/paintings/AGothic.png");
        EarGirl = LoadTexture("../res/paintings/EarringGirl.png");
        Wave = LoadTexture("../res/paintings/Wave.png");
        AppleMan = LoadTexture("../res/paintings/AppleMan.png");
        GeorgeW = LoadTexture("../res/paintings/George.png");
        FarmMan = LoadTexture("../res/paintings/FarmMan.png");
    }




}
