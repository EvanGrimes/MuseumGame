//
// Created by 18149 on 1/17/2021.
//

#ifndef GAME1_MAP_H
#define GAME1_MAP_H
#include "Assets.h"
#include <fstream>
#include <raylib.h>
#include <string>
#include <sstream>
#include "MapReader.h"

class Map{
public:

    Map();

    MapReader mapReader;

    void DrawMap();
private:

    Rectangle sourceRec = {0, 0, 0, 0}, destRect = {0, 0, 0, 0};

};
#endif //GAME1_MAP_H
