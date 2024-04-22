#ifndef JUEGO3_ACTIONRESULT_H
#define JUEGO3_ACTIONRESULT_H

#include <functional>
#include "Character.h"

class Character;

using namespace std;

struct Action{
    int speed=0;
    //suscriber revisa el estado de los personajes
    Character* suscriber = nullptr;
    Character* target = nullptr;

    //-Se crea la variable *action* que lo que hara sera guardar una funcion.

    //-Por asi decirlo, seria de la siguiente manera:
    // action(){
    //   aqui se ejecutaria lo que deba hacer la funcion(huir, atacar..)
    // }

    //-CADA QUE ESCRIBAS O LLAMES *ACTION()*, SE EJECUTARA LA FUNCION

    //-el primer void se refiere a que no recibira nada y el
    // segundo a que no retorna nada
    std::function<void(void)> action = nullptr;

    Action(std::function<void(void)> _action, int _speed, Character* _suscriber, Character* _target){
        action = _action;
        speed = _speed;
        suscriber = _suscriber;
        target = _target;
    }

    Action(){};

    //Esto ordenara la priority queue de mayor velocidad a menor, compara velocidades
    //y ordena.
    bool operator<(const Action &p) const{
        return this->speed < p.speed;
    }
};

#endif //JUEGO3_ACTIONRESULT_H