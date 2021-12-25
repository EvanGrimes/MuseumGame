#include "MonaBattle.h"

void MonaBattle::tick() {
    render();
}

void MonaBattle::render() {
    ClearBackground(BLACK);
    DrawRectangleRec(FightBtn, RED);
}
