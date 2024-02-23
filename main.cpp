#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "../Character/Character.h"

using namespace std;

int main(){

    Player player("Ninja", 100);

    Enemy enemy("Samurai", 100);

enemy.getAttack(player);

player.getAttack(enemy);



    return 0;
}
