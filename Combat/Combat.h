#ifndef JUEGO3_COMBAT_H
#define JUEGO3_COMBAT_H
#include "../Character/Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Action.h"
#include <vector>
#include <queue>


class Combat{
private:
    vector<Character *> participants;
    vector<Player *> teamMembers;
    vector<Enemy *> enemies;
    //PRIORITY QUEUE DE ACCIONES
    priority_queue<Action> actions;


    void prepareCombat();
    Character* getTarget(Character*);
    void registerActions();
    void executeActions();

    void checkParticipantStatus(Character* participant);
    void checkForFlee(Character* player);
    void checkForFleeEnemy(Character *enemy);


public:
    Combat(vector<Character *> _participants);
    Combat(vector<Player *>_teamMembers, vector<Enemy*> _enemies);
    Combat();
    void addParticipants(Character *);
    void doCombat();
    string participantsToString();
    void fleeEnemy(Enemy* enemy);

};





#endif //JUEGO3_COMBAT_H






