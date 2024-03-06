#ifndef JUEGO3_ACTIONRESULT_H
#define JUEGO3_ACTIONRESULT_H
#include "Character.h"

struct Action{
    Character *target = nullptr;
    bool fleed = false;
    int speed=0;

    Action(Character *_target, bool _fleed, int _speed){
        target = _target;
        fleed = _fleed;
        speed = _speed;
    }

    bool operator<(const Action &p) const{
        return this->speed < p.speed;
    }
};

#endif //JUEGO3_ACTIONRESULT_H