#include "Player.h"
#include "iostream"

using namespace std;

Player::Player(string n, int h) : Character(n,h){}

Player::~Player(){
    cout<<"\nDestructor Player"<<endl;
}

void Player::getAttack(Character *target){
    int damage = rand() % 20 + 1;
    int targetHealth = target->getHealth();
    target->setHealth(targetHealth - damage);
    cout<<name<<" attack "<<target->getName()<<" and takes "<<damage<<" life"<<endl;
    displayHealth();
    target->displayHealth();
}




