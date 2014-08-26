#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>

#include "Player.h"

using namespace std;

class Team
{
private:
    Player** roster;
    string teamName;
    int rosterSize;
public:
    Team();
    void setTeamName(string& c);
    string getTeamName();
    void setRosterSize(int i);
    int getRosterSize();
    void addPlayer(int id, string& name);
};

#endif // TEAM_H
