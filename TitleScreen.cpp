#include "TitleScreen.h"
//#include "Game.h"


void TitleScreen::tick() {
    mousePoint = GetMousePosition();

    startBtnAction = false;
    settBtnAction = false;
    controlBtnAction = false;
    exitBtnAction = false;

    startBtnState = 0;
    settBtnState = 0;

    tickStartBtn();
    tickSettBtn();
    tickControlsBtn();
    tickExitBtn();

    render();
}
void TitleScreen::render() {

    ClearBackground(RAYWHITE);

    DrawTexture(Assets::titleBG, 0, 0, WHITE);

    DrawFPS(10, 10);

    /*if (startBtnState == 0) {
        DrawTexture(Assets::startBtn, (int)startBtnBounds.x, (int)startBtnBounds.y, WHITE);
    }

    //If startBtnState is 1, it draws the hovered  start button image
    if (startBtnState == 1) {
        DrawTexture(Assets::startHover, (int)startBtnBounds.x, (int)startBtnBounds.y, WHITE);
    }

    if (settBtnState == 0) {
        DrawTexture(Assets::settBtn,(int)settBtnBounds.x, (int)settBtnBounds.y , WHITE);
    }
    //If settBtnState is 1, it draws the hovered settings button image
    if (settBtnState == 1) {
        DrawTexture(Assets::settHover,(int)settBtnBounds.x, (int)settBtnBounds.y, WHITE);
    }

    DrawTexture(Assets::controlsBtn, 950, 550, WHITE);

    DrawTexture(Assets::exitBtn, -5, 550, WHITE);*/

}

void TitleScreen::tickStartBtn() {

    if (CheckCollisionPointRec(mousePoint, startBtnBounds)) {

        startBtnState = 1;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) startBtnAction = true;
    }
    else startBtnState = 0;

    if (startBtnAction) {

       // SetSoundVolume(Assets::buttonclick1, 0.6);

        //PlaySound(Assets::buttonclick1);

        std::cout << "Start button clicked\n" << std::endl;

       // StopMusicStream(Assets::titleSong);

        Assets::gameState = "game";
    }
}

void TitleScreen::tickSettBtn() {

    if (CheckCollisionPointRec(mousePoint, settBtnBounds)) {

        settBtnState = 1;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) settBtnAction = true;
    }
    else settBtnState = 0;

    if (settBtnAction) {

        Assets::gameState = "settings";
    }
}

void TitleScreen::tickControlsBtn() {

    if(CheckCollisionPointRec(mousePoint, controlBtnBounds)){

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) controlBtnAction = true;
    }

    if(controlBtnAction){

        //SetSoundVolume(Assets::buttonclick2, 0.06);

        //PlaySound(Assets::buttonclick2);

        std::cout << "Control Button Clicked\n" << std::endl;

        Assets::gameState = "controls";
    }
}
void TitleScreen::tickExitBtn() {
    if(CheckCollisionPointRec(mousePoint, exitBtnBounds)){

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) exitBtnAction = true;
    }

    if(exitBtnAction){

        //SetSoundVolume(Assets::buttonclick3, 0.06);

        //PlaySound(Assets::buttonclick3);

        std::cout << "Exit Button Clicked\n" << std::endl;

        //Assets::unloadTitle();

        Assets::gameState = "exit";
    }
}
