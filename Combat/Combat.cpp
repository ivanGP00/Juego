#include "Combat.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool compareSpeed(Character *a, Character *b){
    return a->getSpeed() > b->getSpeed();
}

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

//SORT FUNCIONA PARA ITERAR AL VECTOR, SE NECESITA
//EL INICIO DEL VECTOR (BEGIN), EL FINAL DEL VECTOR (END)
//Y UNA FUNCION PARA COMPARAR LAS DOS VELOCIDADES.
void Combat::prepareCombat() {
    sort(participants.begin(), participants.end(), compareSpeed);
}

void Combat::doCombat() {
    prepareCombat();

    while(enemies.size() != 0 && teamMembers.size() != 0){
        vector<Character*>::iterator participant = participants.begin();

        while(participant != participants.end()){
            Character *target = nullptr;

            if((*participant)->getIsPlayer()){
                ActionResult playerAction = ((Player*)*participant)->takeAction(enemies);
                if(playerAction.target && playerAction.target->getHealth() <= 0){
                    participant = participants.erase(remove(participants.begin(), participants.end(), playerAction.target), participants.end());
                    enemies.erase(remove(enemies.begin(), enemies.end(), playerAction.target), enemies.end());
                }else if(playerAction.fleed){
                    return;
                }else{
                    participant++;
                }
            }
            else{
                target=((Enemy*)*participant)->getTarget(teamMembers);
                (*participant)->doAttack(target);
                if(target->getHealth() <= 0){
                    participant = participants.erase(remove(participants.begin(), participants.end(), target), participants.end());
                    if(target->getIsPlayer()){
                        teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), target), teamMembers.end());
                    }else{
                        enemies.erase(remove(enemies.begin(), enemies.end(), target), enemies.end());
                    }
                }else{
                    participant++;
                }
            }
        }
    }
    if(enemies.size()==0){
        cout<<"You have won the combat"<<endl;
    }else{
        cout<<"The enemies have won the combat -- GAME OVER"<<endl;
    }

}

string Combat::participantsToString() {
    string result="";
    for(int i=0;i<participants.size(); i++){
        result += participants[i]->toString() + "\n";
    }
    return result;
}
