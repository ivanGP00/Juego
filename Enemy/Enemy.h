#ifndef JUEGO3_ENEMY_H
#define JUEGO3_ENEMY_H
#include "Character.h"
#include "Player.h"
#include <vector>
#include "Action.h"

struct Action;

class Player;

class Enemy: public Character {
public:
    Enemy(string, int, int, int, int);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* getTarget(vector<Player*> enemies);
    Action takeAction(vector<Player*> player);
};




#endif //JUEGO3_ENEMY_H