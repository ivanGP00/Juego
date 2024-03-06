//
// Created by Ivan on 27/02/2024.
//
#include <cstdlib>

#ifndef JUEGO3_UTILS_H
#define JUEGO3_UTILS_H

namespace combat_utils{
    int getRollAttack(int attack){
        srand(time(NULL));
        int lowerLimit = attack * .80;
        return (rand() % (attack - lowerLimit + 1)) + lowerLimit;
    }
}

#endif //JUEGO3_UTILS_H