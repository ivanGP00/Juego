#include <algorithm>
#include "Player.h"
#include "iostream"
#include "../Utils.h"



using namespace std;
using namespace combat_utils;

//COMPARA VELOCIDADES ENTRE LOS ENEMYS, Y LOS ACOMODA DE MAYOR A MENOR
bool compareSpeed(Enemy *a, Enemy *b){
    return a->getSpeed() > b->getSpeed();
}

Player::Player(char* n, int h, int a, int d, int s, int xp, int lev) : Character(n,h,a,d,s,true,xp,lev){
    experience = 0;
    level=1;
}

/*Player::Player(char* n, int h, int a, int d, int s, bool is, int exp, int le) : Character(n,h,a,d,s,is){
    experience = exp;
    level = le;
}*/


void Player::doAttack(Character *target) {
    int rolledAttack = getRollAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Player::takeDamage(int damage) {
    setHealth(health - damage);
    cout<<"You have taken "<<damage<<" damage"<<endl;
    if(health <= 0){
        cout<<"You have die."<<endl;
    }
}

//SE DECIDE SI PLAYER PUEDE HUIR O NO
void Player::flee(vector <Enemy*> enemies) {
    std::sort(enemies.begin(), enemies.end(), compareSpeed);
    Enemy* fastestEnemy = enemies[0];


    bool fleed = false;
    if(this->getSpeed() > fastestEnemy->getSpeed()){
        fleed = true;
    }else{
        //SI EL PLAYER ES MAS LENTO QUE EL ENEMY, SE CREA UN PORCENTAJE, PARA SABER
        //LA CHANCE QUE TIENES DE ESCAPAR
        srand(time(NULL));
        int chance = rand()%100;
        cout<<"chance to flee: "<<chance<<endl;
        fleed = chance > 75;
        if(fleed){
            fleed = true;
        }else{
            cout<<this->getName()<<" YOU CANT FLEE, FIGHT"<<endl;
        }
    }

    this->fleed = fleed;
}

void Player::emote() {
    cout<<"Jokes on you"<<endl;
}

//EL PLAYER ELIGE A QUE ENEMIGO ATACAR
Character* Player::getTarget(vector<Enemy *> enemies) {
    cout<<"Choose a target"<<endl;
    int targetIndex=0;
    for(int i=0;i<enemies.size();i++){
        cout<<i<<". "<<enemies[i]->getName()<<endl;
    }
    cin>>targetIndex;

    return enemies[targetIndex];
}


Action Player::takeAction( vector<Enemy*>enemies) {
    int option =0;
    cout<<"Choose an action"<<endl;
    cout<<"1. Attack"<<endl;
    cout<<"2. Flee"<<endl;
    cin>>option;
    Character* target = nullptr;

    //ESTA VARIABLE GUARDA
    // 1. QUE VOY  A HACER.
    //2. CON QUE VELOCIDAD/PRIORIDAD.
    Action myAction;
    //2
    myAction.speed = this->getSpeed();
    myAction.suscriber = this;

    switch (option) {
        case 1:
            target = getTarget(enemies);
            myAction.target=target;
            //action esta guardando un evento que se ejecutara en un futuro,
            //1
            myAction.action = [this, target](){
                //Aun no se ejecuta doAttack, se ejecutara cuando combat lo pida,
                // solo se esta guardando para ejecutarla despues.
                doAttack(target);
            };
            break;
        case 2:
            myAction.action = [this, enemies]{
                flee(enemies);
            };
            break;
        default:
            cout<<"Invalid option you lost your turn"<<endl;
            break;
    }

    return myAction;
}

void Player::gainExperience(Enemy *enemy) {
    if(enemy->getHealth() <= 0){
        experience += enemy->getXP();
    }

    levelUp();
}

void Player::levelUp() {
    if(experience >= 100){
        level++;
        experience=0;

        health +=5;
        attack += 5;
        defense += 5;
        speed += 5;

        cout<<"NICE!! now your are level: "<<level<<endl;
    }
}

/*char* Player::serialize() {
    char* iterator = buffer;
    memcpy(iterator, &name, sizeof name);
    iterator += sizeof name;

    memcpy(iterator, &health, sizeof health);
    iterator += sizeof health;

    memcpy(iterator, &attack, sizeof attack);
    iterator += sizeof attack;

    memcpy(iterator, &defense, sizeof defense);
    iterator += sizeof defense;

    memcpy(iterator, &speed, sizeof speed);
    iterator += sizeof speed;

    memcpy(iterator, &isPlayer, sizeof isPlayer);
    iterator += sizeof isPlayer;

    memcpy(iterator, &experience, sizeof experience);
    iterator += sizeof experience;

    memcpy(iterator, &level, sizeof level);
    iterator += sizeof level;

    return buffer;
} */

/*Player* Player::unserialize(char *_buffer) {
    char* iterator = _buffer;
    char _name[30];
    int _health;
    int _attack;
    int _defense;
    int _speed;
    bool _isPlayer;
    int _experience;
    int _level;

    memcpy(&_name, iterator, sizeof _name);
    iterator += sizeof _name;

    memcpy(&_health, iterator, sizeof _health);
    iterator += sizeof _health;

    memcpy(&_attack, iterator, sizeof _attack);
    iterator += sizeof _attack;

    memcpy(&_defense, iterator, sizeof _defense);
    iterator += sizeof _defense;

    memcpy(&_speed, iterator, sizeof _speed);
    iterator += sizeof _speed;

    memcpy(&_isPlayer, iterator, sizeof _isPlayer);
    iterator += sizeof _isPlayer;

    memcpy(&_experience, iterator, sizeof _experience);
    iterator += sizeof _experience;

    memcpy(&_level, iterator, sizeof _level);
    iterator += sizeof _level;

    return new Player(_name, _health, _attack, _defense, _speed, _isPlayer, _experience, _level);


}

 */