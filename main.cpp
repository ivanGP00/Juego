#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Character.h"
#include "Combat.h"

int main() {                    //name   vida atack defensa speed

    Player *player = new Player("Victor", 20, 2, 3, 7);
    Enemy *enemy = new Enemy("Goblin", 20, 5, 3, 7);
    Enemy *enemy2 = new Enemy("Orco", 30, 8, 5, 2);

    vector<Character *> participants;
    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat *combat = new Combat(participants);

    combat->doCombat();




    delete player;
    delete enemy;
    delete combat;

    return 0;
}