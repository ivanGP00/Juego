#include <algorithm>
#include "Player.h"
#include "iostream"
#include "../Utils.h"

using namespace std;
using namespace combat_utils;

bool compareSpeed(Enemy *a, Enemy *b){
    return a->getSpeed() > b->getSpeed();
}

Player::Player(string n, int h, int a, int d, int s) : Character(n,h,a,d,s,true){
    experience = 0;
    level=1;
}

void Player::doAttack(Character *target) {
    int rolledAttack = getRollAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Player::takeDamage(int damage) {
    setHealth(health - damage);
    if(health <= 0){
        cout<<"You have die."<<endl;
    }else{
        cout<<"You have taken "<<damage<<" damage"<<endl;
    }
}

bool Player::flee(vector <Enemy*> enemies) {
    std::sort(enemies.begin(), enemies.end(), compareSpeed);
    Enemy* fastestEnemy = enemies[0];

    bool fleed = false;
    if(this->getSpeed() > fastestEnemy->getSpeed()){
        fleed = true;
    }else{
        srand(time(NULL));
        int chance = rand()%100;
        cout<<"chance: "<<chance<<endl;
        fleed = chance > 99;
    }

    return fleed;
}

void Player::emote() {
    cout<<"Jokes on you"<<endl;
}

void Player::levelUp() {
    level++;
    setHealth(getHealth() + 10);
    setAttack(getHealth() + 5);
    setDefense(getDefense() + 5);
    setSpeed(getSpeed() + 5);
}

Character* Player::getTarget(vector<Enemy *> enemies) {
    cout<<"Choose a target"<<endl;
    int targetIndex=0;
    for(int i=0;i<enemies.size();i++){
        cout<<i<<". "<<enemies[i]->getName()<<endl;
    }
    cin>>targetIndex;

    return enemies[targetIndex];
}

ActionResult Player::takeAction(vector<Enemy*>enemies) {
    int option =0;
    cout<<"Choose an action"<<endl;
    cout<<"1. Attack"<<endl;
    cout<<"2. Flee"<<endl;
    cin>>option;
    Character* target = nullptr;
    bool fleed = false;
    switch (option) {
        case 1:
            target = getTarget(enemies);
            doAttack(target);
            break;
        case 2:
            fleed = flee(enemies);
            if(flee(enemies)) {
                cout << "You have fled" << endl;
                exit(0);
            }else {
                cout<<"You couldnt flee"<<endl;
            }
            break;
        default:
            cout<<"Invalid option you lost your turn"<<endl;
            break;
    }

    return ActionResult(target, fleed);
}