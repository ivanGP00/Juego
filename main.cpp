#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Character.h"
#include "Combat.h"

int main() {
    cout<<"\n";
    cout<<"\tWELCOME TO MY GAME\n"<<endl;

                                //name   vida atack defensa speed
    Player *player = new Player("Canelo", 50, 10, 7, 8);
    Enemy *enemy = new Enemy("Mcgregor", 16, 5, 3, 7);
    Enemy *enemy2 = new Enemy("Jones", 30, 5, 4, 2);

    vector<Character *> participants;
    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat *combat = new Combat(participants);

    combat->doCombat();




    delete player;
    delete enemy;
    delete enemy2;
    delete combat;

    return 0;
}