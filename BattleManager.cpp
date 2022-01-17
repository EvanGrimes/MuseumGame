#include "BattleManager.h"

char BattleManager::BattlePicker(int PaintingType) {
    switch (PaintingType){
        case 1:
            return 'M';
        case 2:
            return 'S';
        case 3:
            return 's';
        case 4:
            return 'p';
        case 5:
            return 'f';
        case 6:
            return 'G';
        case 7:
            return 'w';
        case 8:
            return 'a';
        case 9:
            return 'g';
        case 10:
            return 'h';
        default:
            return '/';
    }
}