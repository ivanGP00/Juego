#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Character.h"
#include "Combat.h"

int main() {
    cout<<"\n";
    cout<<"\tWELCOME TO MY GAME\n"<<endl;

                                //name   vida atack defensa speed  xp  level
    Player *player = new Player("Canelo", 20, 10, 2, 5, 111, 2);
    Enemy *enemy = new Enemy("Mcgregor", 2, 5, 3, 7, 5, 1);

    vector<Character *> participants;
    participants.push_back(player);
    participants.push_back(enemy);

    Combat *combat = new Combat(participants);
    combat->doCombat();




    delete player;
    delete enemy;
    delete combat;

    return 0;
}