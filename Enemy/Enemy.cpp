#include "Enemy.h"
#include "Enemy.h"
#include <iostream>

using namespace std;

int getRollAttack(int attack){
    int lowerLimit = attack * .80;
    return (rand() % (attack - lowerLimit + 1)) + lowerLimit;
}

Enemy::Enemy(string name, int health, int attack, int defense, int speed) : Character(name, health, attack, defense, speed, false) {
}

void Enemy::doAttack(Character *target) {
    int rolledAttack = getRollAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Enemy::takeDamage(int damage) {
    setHealth(health - damage);
    if(health <= 0) {
        cout<<getName()<<" has died"<<endl;
    }
    else {
        cout<<getName()<<" has taken " << damage << " damage" << endl;
    }
}

Character* Enemy::getTarget(vector<Player *> teamMembers) {
    //aqui obtiene al miembro del equipo con menos vida para atacarlo
    int targetIndex=0;
    int lowestHealth=INT_MAX;
    for(int i=0;i<teamMembers.size();i++){
        if(teamMembers[i]->getHealth() < lowestHealth){
            lowestHealth = teamMembers[i]->getHealth();
            targetIndex=i;
        }
    }
    return teamMembers[targetIndex];
}
