#ifndef GAME1_MAPREADER_H
#define GAME1_MAPREADER_H

#include <raylib.h>
#include <iostream>
#include <vector>

class MapReader {
public:

    static const int mapSize = 64 * 7;

    char mapTileData[mapSize] = {0};

    bool solid[mapSize] = {true};

    Rectangle collision[mapSize] = {{0, 0, 35, 35}};

    int count = 0;

    void readMapData();
    void setMapCollision();
private:
     Rectangle destRect = {0, 0, 0, 0};
};
#endif //GAME1_MAPREADER_H
