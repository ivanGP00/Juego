#include "Player.h"
#include "iostream"

using namespace std;

Player::Player(string n, int h) : Character(n,h){}

void Player::getAttack(Player &target){
    int damage = rand() % 11 + 10;
    target.health -= damage;
    cout<<name<<" attack "<<target.getName()<<" and takes "<<damage<<" life"<<endl;
    displayHealth();
    target.displayHealth();
}




