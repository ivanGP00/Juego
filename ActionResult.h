#ifndef JUEGO3_ACTIONRESULT_H
#define JUEGO3_ACTIONRESULT_H
#include "C:\Users\Alex\OneDrive\Escritorio\Juego2\Character/Character.h"

struct ActionResult{
    Character *target = nullptr;
    bool fleed = false;

    ActionResult(Character *_target, bool _fleed){
        target = _target;
        fleed = _fleed;
    }
};

#endif //JUEGO3_ACTIONRESULT_H