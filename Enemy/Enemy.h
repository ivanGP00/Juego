#ifndef JUEGO2_ENEMY_H
#define JUEGO2_ENEMY_H
#include "../Character/Character.h"

class Enemy : public Character{
    public:
        Enemy(string, int);
        void getAttack(Enemy &);
};

#endif //JUEGO2_ENEMY_H
