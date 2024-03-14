#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Character.h"
#include "Combat.h"

int main() {
    string player1, enemy1, enemy11;
    cout<<"\nEnter the name of the participants.";
    cout<<"\nPlayer 1: ";
    cin>>player1;

    cout<<"Enemy 1: ";
    cin>>enemy11;
    cout<<"Enemy 2: ";
    cin>>enemy11;
    cout<<endl;

    cout<<"\tWELCOME TO MY GAME\n"<<endl;
    system("pause");

                                //name   vida atack defensa speed
    Player *player = new Player(player1, 15, 5, 3, 10);
    Enemy *enemy = new Enemy(enemy11, 20, 5, 3, 7);
    Enemy *enemy2 = new Enemy(enemy11, 30, 8, 4, 2);

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