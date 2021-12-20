#include "Map.h"

int temp;

Map::Map(){
    mapReader.readMapData();
    sourceRec.x = 0;
    sourceRec.y = 0;
    sourceRec.width = destRect.width = 32;
    sourceRec.height = destRect.height = 32;
    destRect.x = destRect.y = 0;

}

void Map::DrawMap() {
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
                case 'p':
                    DrawTextureRec(Assets::painting, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '5':
                    //DrawTextureRec(Assets::bushSecret, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '6':
                    //DrawTextureRec(Assets::sign, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;

                default:
                    break;
            }
        }
    }
}