#ifndef JUEGO3_CHARACTER_H
#define JUEGO3_CHARACTER_H
#include <string>
#include <memory>
#include "Action.h"
#include <vector>
using namespace std;

class Character{
protected:
    char name[30];
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;
    int experience;
    int level;

public:
    Character(char*, int , int , int , int , bool, int, int );

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;


    char* getName();
    void setName(char*);

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

    int getXP();
    void setXP(int _xp);

    int getLevel();
    void setLevel(int _level);
};


#endif //JUEGO3_CHARACTER_H