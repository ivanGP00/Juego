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
    Player(char*, int, int, int, int, int, int);
    //Player(char*, int, int, int, int, bool, int, int);

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    char* serialize();
    //static const unsigned int BUFFER_SIZE = sizeof (name) + sizeof (health) + sizeof (attack) + sizeof (defense) + sizeof (speed) + sizeof (isPlayer) + sizeof (experience) + sizeof (level);

    //static Player* unserialize(char* buffer);

    Character* getTarget(vector<Enemy *> enemies);


    void flee(vector <Enemy*> enemies);
    void emote();
    void levelUp();
    void gainExperience(Enemy* enemy);

    Action takeAction(vector<Enemy*>enemies);


//private:
  //  char buffer[Player::BUFFER_SIZE];


};





#endif //JUEGO3_PLAYER_H