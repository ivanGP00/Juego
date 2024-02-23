#include "Enemy.h"
#include <iostream>

Enemy::Enemy(string n, int h) : Character(n,h){}

void Enemy::getAttack(Enemy &target){
    int damage = rand() % 11 + 10;
    target.health -= damage;
    cout<<name<<" attack "<<target.getName()<<" and takes "<<damage<<" life"<<endl;
    displayHealth();
    target.displayHealth();
}
