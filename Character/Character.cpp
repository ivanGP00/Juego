#include "Character.h"
#include <cstring>

Character::Character(char* n, int h, int a, int d, int s, bool i, int xp, int lev) {
    strcpy(name, n);
    health=h;
    attack=a;
    defense=d;
    speed=s;
    isPlayer=i;
    fleed=false;
    experience=xp;
    level=lev;
}

char* Character::getName(){
    return name;
}
void Character::setName(char* n){
    strcpy(name, n);
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
    return "Name: " + string(name) + "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed) + "\n";
}

bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::hasFleed() {
    return fleed;
}

int Character::getXP(){
    return experience;
}

void Character::setXP(int _xp) {
    experience=_xp;
}

int Character::getLevel() {
    return level;
}

void Character::setLevel(int _level) {
    level=_level;
}

