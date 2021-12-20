#ifndef MUSEUMGAME_TITLESCREEN_H
#define MUSEUMGAME_TITLESCREEN_H

#include <raylib.h>

#include "Assets.h"

class TitleScreen {
public:

    Rectangle startBtnBounds = {370,300,257, 97 };
    Rectangle settBtnBounds = { 950,550,50, 50 };
    Rectangle exitBtnBounds = { 0,550,50, 50 };

    int startBtnState = 0;

    bool startBtnAction = false;
    bool settBtnAction = false;
    bool exitBtnAction = false;

    Vector2 mousePoint = { 0.0f, 0.0f };

    void tick();
    void render();
    void tickStartBtn();
    void tickSettBtn();
    void tickExitBtn();
};


#endif //MUSEUMGAME_TITLESCREEN_H
