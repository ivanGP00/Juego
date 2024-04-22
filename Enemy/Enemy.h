#ifndef JUEGO3_ENEMY_H
#define JUEGO3_ENEMY_H
#include "Character.h"
#include "Player.h"
#include <vector>
#include "Action.h"

struct Action;
class Player;

class Enemy: public Character {
private:
    //bandera para saber si enemy huyo.
    bool hasEscaped;
public:
    Enemy(char[30], int, int, int, int);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* getTarget(vector<Player*> enemies);
    Action takeAction(vector<Player*> player);
    int getRandomNumber();


//Para obtener el estado de salud de mi enemigo
    int MaxHealth;

    void flee(vector <Player*> teamMembers);

    void failScapeEnemy(vector<Player *> player);


};


#endif //JUEGO3_ENEMY_H