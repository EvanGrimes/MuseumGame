#include "MonaBattle.h"

void MonaBattle::tick() {
    mousePoint = GetMousePosition();

    FightBtnAction = false;
    ItemBtnAction = false;
    LeaveBtnAction = false;

    tickFight();
    tickLeave();
    tickItem();

    render();
}

void MonaBattle::render() {
    ClearBackground(BLACK);
    DrawRectangleRec(FightBtn, RED);
    DrawRectangleRec(ItemBtn, BLUE);
    DrawRectangleRec(LeaveBtn, GREEN);
}

void MonaBattle::tickFight() {
    if (CheckCollisionPointRec(mousePoint, FightBtn)) {

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) FightBtnAction = true;
    }
    if (FightBtnAction) {

        std::cout << "FIGHT!\n" << std::endl;

    }
}

void MonaBattle::tickItem() {
    if (CheckCollisionPointRec(mousePoint, ItemBtn)) {

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) ItemBtnAction = true;
    }
    if (ItemBtnAction) {

        std::cout << "ITEM!\n" << std::endl;

    }
}

void MonaBattle::tickLeave() {
    if (CheckCollisionPointRec(mousePoint, LeaveBtn)) {

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) LeaveBtnAction = true;
    }
    if (LeaveBtnAction) {

        std::cout << "COWARD!\n" << std::endl;

        Assets::gameState = "game";

    }
}
