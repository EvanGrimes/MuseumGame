#include "Map.h"

Map::Map(){
    mapReader.readMapData();
    sourceRec.x = 0;
    sourceRec.y = 0;
    sourceRec.width = destRect.width = 16;
    sourceRec.height = destRect.height = 16;
    destRect.x = destRect.y = 0;
}

void Map::DrawMap() {
    destRect.x = destRect.y = 0;
    for (int x = 0; x < 23; ++x) {
        for (int y = 0; y < 66; y++) {
            destRect.x = (float)y * 16;
            destRect.y = (float)x * 16;
            switch (mapReader.mapTileData[x * 66 + y]) {
                case '0':
                    DrawTextureRec(Assets::floor, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '1':
                    DrawTextureRec(Assets::wall, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '2':
                    DrawTextureRec(Assets::pillar, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '3':
                    DrawTextureRec(Assets::wallTop, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '4':
                    DrawTextureRec(Assets::rope, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 'm':
                    //Mona Lisa
                    DrawTextureRec(Assets::painting, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 'S':
                    //Starr Night
                    DrawTextureRec(Assets::painting, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 's':
                    //Scream
                    DrawTextureRec(Assets::painting, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 'p':
                    //Pipe
                    DrawTextureRec(Assets::painting, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 'f':
                    //Farm
                    DrawTextureRec(Assets::painting, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 'G':
                    //Girl
                    DrawTextureRec(Assets::painting, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 'w':
                    //Wave
                    DrawTextureRec(Assets::painting, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 'a':
                    //Apple Man
                    DrawTextureRec(Assets::painting, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 'g':
                    //George Washington
                    DrawTextureRec(Assets::painting, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 'h':
                    //House Man
                    DrawTextureRec(Assets::painting, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;

                default:
                    break;
            }
        }
    }
}