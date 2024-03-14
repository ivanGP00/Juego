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

//SE DECIDE SI PLAYER PUEDE HUIR O NO
bool Player::flee(vector <Enemy*> enemies) {
    std::sort(enemies.begin(), enemies.end(), compareSpeed);
    Enemy* fastestEnemy = enemies[0];

    //SE CREA LA VARIABLE FLEED PARA SABER SI ES MAS RAPIDO PLAYER QUE ENEMY
    //SE INICIALIZA EN FALSE, PARA LUEGO SI SE CUMPLE LA CONDICION DE ESCAPAR
    //SE DECLARA COMO TRUE Y SI NO SE CUMPLE, SE QUEDA COMO FALSE DE QUE NO ESCAPO
    bool fleed = false;
    if(this->getSpeed() > fastestEnemy->getSpeed()){
        fleed = true;
    }else{
        //SI EL PLAYER ES MAS LENTO QUE EL ENEMY, SE CREA UN PORCENTAJE, PARA SABER
        //LA CHANCE QUE TIENES DE ESCAPAR
        srand(time(NULL));
        int chance = rand()%100;
        cout<<"chance: "<<chance<<endl;
        fleed = chance > 75;
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
    bool fleed = false;

    //ESTA VARIABLE GUARDA 1. QUE VOY  A HACER - 2. CON QUE VELOCIDAD/PRIORIDAD
    Action myAction;
    //------------ACTION?-----------

    myAction.speed = this->getSpeed();
    switch (option) {
        case 1:
            target = getTarget(enemies);
            //action esta guardando un evento que se ejecutara en un futuro,
            //se ejecutara ya que COMBAT lo permite o ya que sea el momento
            myAction.action = [this, &target](){
                //Aun no se ejecuta doAttack, se ejecutara cuando combat lo pida,
                // solo se esta guardando para ejecutarla despues.
                doAttack(target);
            };
            break;
        case 2:
            fleed = flee(enemies);
            if(fleed) {
                cout << "You have fled" << endl;
            }else {
                cout<<"You couldnt flee"<<endl;
            }
            break;
        default:
            cout<<"Invalid option you lost your turn"<<endl;
            break;
    }

    return Action(target, fleed, 0);
    //-----------PORQUE REGRESA ACTION-------------
}