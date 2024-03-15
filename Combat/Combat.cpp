#include "Combat.h"
#include <iostream>
#include <algorithm>
using namespace std;
bool compareSpeed(Character *a, Character *b){
    return a->getSpeed() > b->getSpeed();
}
bool compareHealth(Enemy *a, Enemy *b){
    return a->getHealth() > b->getHealth();
}

//SE SEPARAN LOS PARTICIPANTES EN SU RESPECTIVO VECTOR DEPENDIENDO SI ES
// ENEMY O PLAYER.
Combat::Combat(vector<Character *> _participants) {
    participants = std::move(_participants);
    for(auto participant : participants){
        if(participant->getIsPlayer()){
            teamMembers.push_back((Player *) participant);
        }else{
            enemies.push_back((Enemy *)participant);
        }
    }
}
Combat::Combat(vector<Player *> _teamMemebers, vector<Enemy *> _enemies) {
    teamMembers = std::move(_teamMemebers);
    enemies = std::move(_enemies);
}

//AGREGAS A LOS PERSONAJES EN EL VECTOR PARTICIPANT Y LUEGO EN SU RESPECTIVO VECTOR
void Combat::addParticipants(Character *participant) {
    participants.push_back(participant);
    if(participant->getIsPlayer()){
        teamMembers.push_back((Player *)participant);
    }else{
        enemies.push_back((Enemy *)participant);
    }
}

Combat::Combat() {
    participants = vector<Character *>();
}

//ANTES DE INICIAR EL COMBATE, SE ACOMODAN LOS PARTICIPANTES
// DE MAYOR VELOCIDAD A MENOR EN EL VECTOR PARTICIPANT
void Combat::prepareCombat() {
    sort(participants.begin(), participants.end(), compareSpeed);
}


void Combat::doCombat() {
    prepareCombat();

    //iteracion por ronda
    while(enemies.size() != 0 && teamMembers.size() != 0){
        registerActions();
        executeActions();
    }
    if(enemies.size()==0){
        cout<<"You have won the combat"<<endl;
    }else{
        cout<<"The enemies have won the combat -- GAME OVER"<<endl;
    }
}

void Combat::registerActions(){
    vector<Character*>::iterator participant = participants.begin();
    //iteracion por turno
    while(participant != participants.end()){
        Character *target = nullptr;
        Action currentAction;

        if((*participant)->getIsPlayer()){
            currentAction = ((Player*)*participant)->takeAction(enemies);
        }else{
            currentAction = ((Enemy*)*participant)->takeAction(teamMembers);
        }

        //se guardan todas las acciones, en la priority queue
        actions.push(currentAction);
        participant++;
    }
}

void Combat::executeActions() {
    //verificamos si enemy huyo
    for (auto& enemy : enemies) {
        fleeEnemy(enemy);
    }
    while(!actions.empty()){
        Action currentAction = actions.top();
        currentAction.action();
        checkForFlee(currentAction.suscriber);
        checkParticipantStatus(currentAction.suscriber);
        checkParticipantStatus(currentAction.target);
        actions.pop();
    }
}

void Combat::checkParticipantStatus(Character* participant) {
    if(participant->getHealth() <= 0){
        if(participant->getIsPlayer()){
            teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), participant), teamMembers.end());
        }else{
            enemies.erase(remove(enemies.begin(), enemies.end(), participant), enemies.end());
        }
        participants.erase(remove(participants.begin(), participants.end(), participant), participants.end());
    }
}

//ENEMY HUYE
void Combat::fleeEnemy(Enemy* enemy) {
    if (enemy->getHealth() < 15) {
        srand(time(NULL));
        int escape_chance = rand() % 100 + 1;
        cout << "Chance of " << enemy->getName() << " escaping: " << escape_chance << endl;
        if (escape_chance > 40) {
            cout << enemy->getName() << " has fled the combat." << endl;
            // Elimina al enemigo que ha escapado
            participants.erase(remove(participants.begin(), participants.end(), enemy), participants.end());
            enemies.erase(remove(enemies.begin(), enemies.end(), enemy), enemies.end());
            //si delete no funciona
            actions.pop();
            return;

        } else {
            cout << enemy->getName() << " can't flee." << endl;
        }
    }
}


//PLAYER HUYE
void Combat::checkForFlee(Character *player) {
    bool fleed = player->hasFleed();
    if(fleed){
        if(player->getIsPlayer()){
            cout<<"You have fled the combat"<<endl;
            teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), player), teamMembers.end());
        }else{
            cout<<player->getName()<<" has fled the combat"<<endl;
            enemies.erase(remove(enemies.begin(), enemies.end(), player), enemies.end());
        }
        participants.erase(remove(participants.begin(), participants.end(), player), participants.end());
    }
}

//SE MUESTRAN TODOS LOS PARTICIPANTES
string Combat::participantsToString() {
    string result="";
    for(int i=0;i<participants.size(); i++){
        result += participants[i]->toString() + "\n";
    }
    return result;
}


