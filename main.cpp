#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "../Character/Character.h"

using namespace std;

int main(){

    Player *player1 = new Player("Ninja", 100);

    Enemy *enemy1 = new Enemy("Samurai", 100);

    int i=0;
while(player1->alive() && enemy1->alive()){
    cout<<"ROUND "<<++i<<"\n";
    player1->getAttack(enemy1);
    if(!enemy1->alive()){
        cout<<player1->getName()<<" win the match"<<endl;
        break;
    }

    cout<<"\n";

    enemy1->getAttack(player1);
    if(!player1->alive()){
        cout<<enemy1->getName()<<" win the match"<<endl;
        break;
    }

    cout<<"\n";
}

player1->~Player();
enemy1->~Enemy();


    return 0;
}
