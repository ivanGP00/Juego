#include "Character.h"

Character::Character(string n, int h, int a, int d, int s, bool i) {
    name=n;
    health=h;
    attack=a;
    defense=d;
    speed=s;
    isPlayer=i;
    fleed=false;
}

string Character::getName(){
    return name;
}
void Character::setName(string n){
    name=n;
}

int Character::getHealth(){
    return health;
}
void Character::setHealth(int h){
    health=h;
}

int Character::getAttack(){
    return attack;
}
void Character::setAttack(int a){
    attack=a;
}

int Character::getDefense(){
    return defense;
}
void Character::setDefense(int d){
    defense=d;
}

int Character::getSpeed(){
    return speed;
}
void Character::setSpeed(int s){
    speed=s;
}

string Character::toString() {
    return "Name: " + name + "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed) + "\n";
}

bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::hasFleed() {
    return fleed;
}