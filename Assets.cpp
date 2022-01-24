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

    Texture2D playerUp[6];
    Texture2D playerDown[6];
    Texture2D playerLeft[6];
    Texture2D playerRight[6];
    Texture2D playerIdle[4];
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
    Texture2D AGothicBG;
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
        playerUp[0] = LoadTexture("../res/sprites/walk/hero-walk-back/Up1.png");
        playerUp[1] = LoadTexture("../res/sprites/walk/hero-walk-back/Up2.png");
        playerUp[2] = LoadTexture("../res/sprites/walk/hero-walk-back/Up3.png");
        playerUp[3] = LoadTexture("../res/sprites/walk/hero-walk-back/Up4.png");
        playerUp[4] = LoadTexture("../res/sprites/walk/hero-walk-back/Up5.png");
        playerUp[5] = LoadTexture("../res/sprites/walk/hero-walk-back/Up6.png");

        playerDown[0] = LoadTexture("../res/sprites/walk/hero-walk-front/hero-walk-front-1.png");
        playerDown[1] = LoadTexture("../res/sprites/walk/hero-walk-front/hero-walk-front-2.png");
        playerDown[2] = LoadTexture("../res/sprites/walk/hero-walk-front/hero-walk-front-3.png");
        playerDown[3] = LoadTexture("../res/sprites/walk/hero-walk-front/hero-walk-front-4.png");
        playerDown[4] = LoadTexture("../res/sprites/walk/hero-walk-front/hero-walk-front-5.png");
        playerDown[5] = LoadTexture("../res/sprites/walk/hero-walk-front/hero-walk-front-6.png");

        playerRight[0] = LoadTexture("../res/sprites/walk/hero-walk-side/hero-walk-side-1.png");
        playerRight[1] = LoadTexture("../res/sprites/walk/hero-walk-side/hero-walk-side-2.png");
        playerRight[2] = LoadTexture("../res/sprites/walk/hero-walk-side/hero-walk-side-3.png");
        playerRight[3] = LoadTexture("../res/sprites/walk/hero-walk-side/hero-walk-side-4.png");
        playerRight[4] = LoadTexture("../res/sprites/walk/hero-walk-side/hero-walk-side-5.png");
        playerRight[5] = LoadTexture("../res/sprites/walk/hero-walk-side/hero-walk-side-6.png");

        playerLeft[0] = LoadTexture("../res/sprites/walk/left/1.png");
        playerLeft[1] = LoadTexture("../res/sprites/walk/left/2.png");
        playerLeft[2] = LoadTexture("../res/sprites/walk/left/3.png");
        playerLeft[3] = LoadTexture("../res/sprites/walk/left/4.png");
        playerLeft[4] = LoadTexture("../res/sprites/walk/left/5.png");
        playerLeft[5] = LoadTexture("../res/sprites/walk/left/6.png");

        playerIdle[0] = LoadTexture("../res/sprites/idle/hero-idle-back/hero-idle-back.png");
        playerIdle[1] = LoadTexture("../res/sprites/idle/hero-idle-front/hero-idle-front.png");
        playerIdle[2] = LoadTexture("../res/sprites/idle/hero-idle-side/hero-idle-side.png");
        playerIdle[3] = LoadTexture("../res/sprites/idle/hero-idle-side/left.png");

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

        AGothicBG = LoadTexture("../res/textures/AGothicBG.png");

        EarGirl = LoadTexture("../res/paintings/EarringGirl.png");
        Wave = LoadTexture("../res/paintings/Wave.png");
        AppleMan = LoadTexture("../res/paintings/AppleMan.png");
        GeorgeW = LoadTexture("../res/paintings/George.png");
        FarmMan = LoadTexture("../res/paintings/FarmMan.png");
    }




}
