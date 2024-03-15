#ifndef JUEGO3_CHARACTER_H
#define JUEGO3_CHARACTER_H
#include <string>
#include <memory>
#include "Action.h"
#include <vector>
using namespace std;

class Character{
protected:
    string name;
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;
    bool fleedEnemy;
public:
    Character(string , int , int , int , int , bool );

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;


    string getName();
    void setName(string);

    int getHealth();
    void setHealth(int);

    int getAttack();
    void setAttack(int);

    int getDefense();
    void setDefense(int);

    int getSpeed();
    void setSpeed(int);

    bool getIsPlayer();

    string toString();

    bool hasFleed();
};


#endif //JUEGO3_CHARACTER_H