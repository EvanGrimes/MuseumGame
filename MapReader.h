#ifndef GAME1_MAPREADER_H
#define GAME1_MAPREADER_H

#include <raylib.h>
#include <iostream>

class MapReader {
public:

    static const int mapSize = 66 * 23;

    char mapTileData[mapSize] = {0};

    bool IsPainting[mapSize] = {false};
    int PaintingType[mapSize] = {0};

    Rectangle collision[mapSize] = {{0, 0, 35, 35}};

    int count = 0;

    void readMapData();
    void setMapCollision();

private:

     Rectangle destRect = {0, 0, 0, 0};

};
#endif //GAME1_MAPREADER_H
