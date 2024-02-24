#include "Character.h"
#include "iostream"

using namespace std;

Character::Character(string n, int h) {
    name=n;
    health=h;
}

Character::~Character() {
    cout<<"\nDestructor Character"<<endl;
}

void Character::setName(string n) {
    name=n;
}

string Character::getName() {
    return name;
}

void Character::setHealth(int h) {
    health=h;
}

int Character::getHealth(){
    return health;
}

void Character::getAttack(Character *target){
    int damage = rand() % 20 + 1;
    target->health -= damage;
    cout<<name<<" attack "<<target->getName()<<" and takes "<<damage<<" life"<<endl;
    displayHealth();
    target->displayHealth();
}

void Character::displayHealth() {
    cout<<name<<" have "<<health<<" life"<<endl;
}

bool Character::alive() {
    return health > 0;
}