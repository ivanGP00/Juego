#include "Enemy.h"
#include <iostream>

Enemy::Enemy(string n, int h) : Character(n,h){}

Enemy::~Enemy() {
    cout<<"\nDestructor Enemy"<<endl;
}

void Enemy::getAttack(Character *target){
    int damage = rand() % 20 + 1;
    int targetHealth = target->getHealth();
    target->setHealth(targetHealth - damage);
    cout<<name<<" attack "<<target->getName()<<" and takes "<<damage<<" life"<<endl;
    displayHealth();
    target->displayHealth();
}
