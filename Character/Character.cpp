#include "Character.h"
#include <cstring>

Character::Character(char n[30], int h, int a, int d, int s, bool i) {
    strcpy_s(name, n);
    health=h;
    attack=a;
    defense=d;
    speed=s;
    isPlayer=i;
    fleed=false;
}

char* Character::getName(){
    return name;
}
void Character::setName(char n[30]){
    strcpy_s(name, n);
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

