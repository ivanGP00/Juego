#ifndef JUEGO3_ACTIONRESULT_H
#define JUEGO3_ACTIONRESULT_H

#include <functional>
#include "Character.h"

using namespace std;

struct Action{
    Character *target = nullptr;
    bool fleed = false;
    int speed=0;
    //-Se crea la variable *action* que lo que hara sera guardar una funcion.

    //-Por asi decirlo, seria de la siguiente manera:
    // action(){
    //   aqui se ejecutaria lo que deba hacer la funcion(huir, atacar..)
    // }

    //-CADA QUE ESCRIBAS O LLAMES *ACTION()*, SE EJECUTARA LA FUNCION

    //-el primer void se refiere a que no recibira nada y el segundo a que no retorna nada
    std::function<void(void)> action = nullptr;

    Action(Character *_target, bool _fleed, int _speed){
        target = _target;
        fleed = _fleed;
        speed = _speed;
    }

    Action(){};

    //Esto ordenara la priority queue de mayor velocidad a menor, compara velocidades
    //y ordena.
    bool operator<(const Action &p) const{
        return this->speed < p.speed;
    }
};

#endif //JUEGO3_ACTIONRESULT_H