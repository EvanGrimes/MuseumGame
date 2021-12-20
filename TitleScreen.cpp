#include "TitleScreen.h"

void TitleScreen::tick() {
    mousePoint = GetMousePosition();

    startBtnAction = false;
    settBtnAction = false;
    exitBtnAction = false;

    startBtnState = 0;

    tickStartBtn();
    //tickSettBtn();
    tickExitBtn();

    render();
}
void TitleScreen::render() {
    ClearBackground(WHITE);

    DrawTexture(Assets::titleBG, 0, 0, RAYWHITE);

    if (startBtnState == 0) {
        DrawTexture(Assets::startBtn, (int)startBtnBounds.x, (int)startBtnBounds.y, WHITE);
    }

    if (startBtnState == 1) {
        DrawTexture(Assets::startHover, (int)startBtnBounds.x, (int)startBtnBounds.y, WHITE);
    }

    DrawTexture(Assets::settBtn,(int)settBtnBounds.x, (int)settBtnBounds.y , WHITE);

    DrawTexture(Assets::exitBtn, -5, 550, WHITE);

}

void TitleScreen::tickStartBtn() {

    if (CheckCollisionPointRec(mousePoint, startBtnBounds)) {

        startBtnState = 1;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) startBtnAction = true;
    }
    else startBtnState = 0;

    if (startBtnAction) {

        std::cout << "Start button clicked\n" << std::endl;

        Assets::gameState = "game";
    }
}

void TitleScreen::tickSettBtn() {
    if(CheckCollisionPointRec(mousePoint, exitBtnBounds)){

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) settBtnAction = true;
    }

    if (settBtnAction) {
        Assets::gameState = "settings";
    }
}


void TitleScreen::tickExitBtn() {
    if(CheckCollisionPointRec(mousePoint, exitBtnBounds)){

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) exitBtnAction = true;
    }

    if(exitBtnAction){

        std::cout << "Exit Button Clicked\n" << std::endl;

        Assets::gameState = "exit";
    }
}
