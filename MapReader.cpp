#include "MapReader.h"
#include <raylib.h>
#include <cstdio>


void MapReader::readMapData() {
    char *buffer = LoadFileText("../res/map.mp");
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
                        collision[count] = {destRect.x + 5.5f, destRect.y + 3,7.3, 14};
                        count++;
                        break;
                    }
                    if(count > mapSize){
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 5.5f, destRect.y + 3,7.3, 14};
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
                case 'p':
                    //PAINTING
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

            }
        }
    }
}
