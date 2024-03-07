#ifndef JUEGO3_ACTIONRESULT_H
#define JUEGO3_ACTIONRESULT_H

#include <functional>
#include "Character.h"

using namespace std;

struct Action{
    int speed=0;
    function<void(void)> action = nullptr;

    Action(function<void(void)> _action, int _speed){
        action = _action;
        speed = _speed;
    }
    Action(){};

    bool operator<(const Action &p) const{
        return this->speed < p.speed;
    }
};

#endif //JUEGO3_ACTIONRESULT_H