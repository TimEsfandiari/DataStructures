#include "Team.h"

Team::Team()
{
}

void Team::setTeamName(string& c)
{
    teamName = c;
}

string Team::getTeamName()
{
    return teamName;
}
void Team::setRosterSize(int i)
{
    rosterSize = i;
}

int Team::getRosterSize()
{
    return rosterSize;
}

void Team::addPlayer(int id, string& name)
{
    //roster[id] = new Player(id, name, teamName);
    Player* player = new Player(id, name, teamName);
}

