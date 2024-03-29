#ifndef JUEGO3_PLAYER_H
#define JUEGO3_PLAYER_H
#include "Character.h"
#include "Enemy.h"
#include <vector>
#include "Action.h"

struct Action;
class Enemy;

class Player : public Character{
protected:
    int experience;
    int level;
public:
    Player(string, int, int, int, int);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;

    Character* getTarget(vector<Enemy *> enemies);


    void flee(vector <Enemy*> enemies);
    void emote();
    void levelUp();
    void gainExperience(int);

    Action takeAction(vector<Enemy*>enemies);
    bool canFlee();

};





#endif //JUEGO3_PLAYER_H