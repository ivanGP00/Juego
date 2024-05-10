#include "Enemy.h"
#include <iostream>

using namespace std;
int Enemy::getRandomNumber(){
    srand(time(NULL));
    int getChance = rand() % 100;
    return getChance;
}

int getRollAttack(int attack){
    int lowerLimit = attack * .80;
    return (rand() % (attack - lowerLimit + 1)) + lowerLimit;
}

Enemy::Enemy(char* name, int health, int attack, int defense, int speed, int xp, int lev) : Character(name, health, attack, defense, speed, false, xp, lev) {
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

//EL ENEMIGO ATACA AL PLAYER CON MENOS VIDA
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

void Enemy::failScapeEnemy(){
    if(this->getHealth() < 15){
        cout<<this->getName()<<" ----triying to scape----"<<endl;
        cout << "Chance: " << getRandomNumber() << endl;
        cout<<this->getName()<<" YOU CANT FLEE, FIGHT"<<endl;
    }
}


Action Enemy::takeAction(vector<Player *> player) {
    Action myAction;
    myAction.speed = getSpeed();
    myAction.suscriber = this;
    Character* target = getTarget(player);

    if (this->getHealth() < 15 && getRandomNumber() > 80) {
        cout << "Chance: " << getRandomNumber() << endl;
        myAction.action = [this, target]() {
            this->fleed = true;
        };
    } else {
        myAction.target = target;
        myAction.action = [this, target]() {
            failScapeEnemy();
            doAttack(target);
        };
    }

    return myAction;
}



