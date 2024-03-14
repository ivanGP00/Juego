#include "Combat.h"
#include <iostream>
#include <algorithm>
using namespace std;
bool compareSpeed(Character *a, Character *b){
    return a->getSpeed() > b->getSpeed();
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

void Combat::checkForFlee(Character *character) {
    bool fleed = character->hasFleed();
    if(fleed){
        if(character->getIsPlayer()){
            cout<<"You have fled the combat"<<endl;
            teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), character), teamMembers.end());
        }else{
            cout<<character->getName()<<" has fled the combat"<<endl;
            enemies.erase(remove(enemies.begin(), enemies.end(), character), enemies.end());
        }
        participants.erase(remove(participants.begin(), participants.end(), character), participants.end());
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
