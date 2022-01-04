#include "MapReader.h"
#include <raylib.h>
#include <cstdio>


void MapReader::readMapData() {
    char *buffer = LoadFileText("../res/map_2.mp");
    char *p = buffer;
    int x = 0;
    while (*p != '\0') {
        if (*p != '\n') {
                if (x >= mapSize) {
                    printf("MAP TOO BIG");
                    break;
            }
            mapTileData[x++] = *p;
        }
        ++p;
    }
    UnloadFileText((unsigned char*)(buffer));
    printf("Map Data Read");
}

/*
 * Map Key:
 * m = Mona Lisa
 * S = starry night
 * s = scream
 * p = Pipe
 * f = farm
 * G = girl
 * w = Kanagawa
 * a = Son of Man
 * g = George Washington
 * h = House dude
 */
void MapReader::setMapCollision() {
    destRect.x = destRect.y = 0;
    for(int x = 0; x < 23; ++x ){
        for(int y = 0; y < 66; y++){
            destRect.x = (float)y * 16;
            destRect.y = (float)x * 16;
            switch(mapTileData[x * 66 + y]) {
                case '0':
                    break;
                case '1':
                    //WALL
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    break;
                case '2':
                    //PILLAR
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,7.3, 14};
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 5, destRect.y + 3,7.3, 14};
                    break;
                case '3':
                    //WALLTOP
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    break;
                case '4':
                    //WALLTOP
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,7.3, 5};
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 5};
                    break;
                case 'm':
                    //Mona Lisa
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        IsPainting[count] = true;
                        PaintingType[count] = 1;
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    IsPainting[count] = true;
                    PaintingType[count] = 1;
                    break;
                case 'S':
                    //Starr Night
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        IsPainting[count] = true;
                        PaintingType[count] = 2;
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    IsPainting[count] = true;
                    PaintingType[count] = 2;
                    break;
                case 's':
                    //Scream
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        IsPainting[count] = true;
                        PaintingType[count] = 3;
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    IsPainting[count] = true;
                    PaintingType[count] = 3;
                    break;
                case 'p':
                    //Pipe
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        IsPainting[count] = true;
                        PaintingType[count] = 4;
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    IsPainting[count] = true;
                    PaintingType[count] = 4;
                    break;
                case 'f':
                    //Farm
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        IsPainting[count] = true;
                        PaintingType[count] = 5;
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    IsPainting[count] = true;
                    PaintingType[count] = 5;
                    break;
                case 'G':
                    //Girl
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        IsPainting[count] = true;
                        PaintingType[count] = 6;
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    IsPainting[count] = true;
                    PaintingType[count] = 6;
                    break;
                case 'w':
                    //Wave
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        IsPainting[count] = true;
                        PaintingType[count] = 7;
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    IsPainting[count] = true;
                    PaintingType[count] = 7;
                    break;
                case 'a':
                    //Apple Man
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        IsPainting[count] = true;
                        PaintingType[count] = 8;
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    IsPainting[count] = true;
                    PaintingType[count] = 8;
                    break;
                case 'g':
                    //George Washington
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        IsPainting[count] = true;
                        PaintingType[count] = 9;
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    IsPainting[count] = true;
                    PaintingType[count] = 9;
                    break;
                case 'h':
                    //House Man
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                        IsPainting[count] = true;
                        PaintingType[count] = 10;
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,14, 14};
                    IsPainting[count] = true;
                    PaintingType[count] = 10;
                    break;
            }
        }
    }
}
