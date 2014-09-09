#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#include "Player.h"

using namespace std;

class Team
{
private:
    Player** roster;
    char* teamName;
    int rosterSize;
public:
    Team();
    void setTeamName(char* c);
    char* getTeamName();
    void setRosterSize(int i);
    int getRosterSize();
    void addPlayer(int id, char* name, char* teamName, int c);
    void fillRoster(int i, int* IDs, char** names, ifstream& file);
    void printRoster(ofstream& file);
    void addTagToPlayer(Tag* tag, int id);
    bool isPlayerInTeam(int id);
    const Player* getPlayerByID(int id) const;
    Player* getPlayer(int id);
    int getTotalScore();
    int getHighScore();


};

#endif // TEAM_H
