#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Character.h"
#include "Combat.h"

int main() {
    cout<<"\n";
    cout<<"\tWELCOME TO MY GAME\n"<<endl;

                                //name   vida atack defensa speed  xp  level
    Player *player = new Player("Canelo", 20, 10, 2, 5, 10, 2);
    Enemy *enemy = new Enemy("Mcgregor", 17, 5, 3, 7, 5, 1);
    Enemy *enemy2 = new Enemy("Jones", 30, 4, 4, 3, 15, 2);

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