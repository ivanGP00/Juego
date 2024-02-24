
#ifndef JUEGO2_CHARACTER_H
#define JUEGO2_CHARACTER_H
#include <string>
#include <ctime>

using namespace std;

class Character{
protected:
    string name;
    int health;
public:
    Character(string, int);
    ~Character();
    void setName(string);
    string getName();
    void setHealth(int);
    int getHealth();
    void setDamage(int);
    int getDamage();

    virtual void getAttack(Character *target);

    void displayHealth();

    bool alive();
};


#endif //JUEGO2_CHARACTER_H
