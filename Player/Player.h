#ifndef JUEGO2_PLAYER_H
#define JUEGO2_PLAYER_H
#include "../Character/Character.h"


class Player : public Character{
    public:
        Player(string, int);
    void getAttack(Player &);


};

#endif //JUEGO2_PLAYER_H
