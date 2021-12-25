#ifndef MUSEUMGAME_MONABATTLE_H
#define MUSEUMGAME_MONABATTLE_H

#include "../Assets.h"

class MonaBattle {
public:
    bool IsBossDead = false;

    Rectangle FightBtn = {370,300,257, 97 };

    void tick();
    void render();
};


#endif //MUSEUMGAME_MONABATTLE_H
