#include "Team.h"

Team::Team()
{
    teamName = new char[64];
}

void Team::setTeamName(char* c)
{
    strcpy(teamName, c);
}

char* Team::getTeamName()
{
    return teamName;
}
void Team::setRosterSize(int i)
{
    rosterSize = i;

    //potential problem A
    roster = new Player*[rosterSize];
}

int Team::getRosterSize()
{
    return rosterSize;
}

void Team::addPlayer(int id, char* name, char* teamName, int c)
{
    roster[c] = new Player(id, name, teamName);
}

//I filled up the roster here, I had some question for quite a bit getting
//this to work, until Jarrett helped me and I realized I was populating names with nothing
//thus making it inaccessable and giving me a seg fault.
void Team::fillRoster(int size, int* IDs, char** names, ifstream& file)
{
    if(file.is_open())
        for(int c = 0; c < size; c++)
        {
            file >> IDs[c];
            file.ignore();
            file.getline(names[c], 32);

            addPlayer(IDs[c], names[c], getTeamName(), c);
        }
}

bool compare(Player* left, Player* right)
{
    return left->getPointsScored() > right->getPointsScored();
}

//I used this to print the roster to the
//output file at the end of the main.cpp
void Team::printRoster(ofstream& file)
{
    //sort.. given I didn't already make a vector
    vector<Player*> tempRoster;
    for(int i=0; i < rosterSize; i++)
    {
        tempRoster.push_back(roster[i]);
    }

    sort(tempRoster.begin(), tempRoster.end(), compare);

    for(int c = 0; c < getRosterSize(); c++)
    {
        file << "\t" << tempRoster[c]->getName() << " had a total of " << tempRoster[c]->getNumTags() << " tags" <<endl;
    }

}

void Team::addTagToPlayer(Tag* tag, int id)
{
    int i;

    for(i = 0; i < rosterSize; i++)
    {
        if(id == roster[i]->getID()) break;
    }

    roster[i]->addTag(tag);
}

//checks to see if a player is on your own team
bool Team::isPlayerInTeam(int id)
{
    for(int i = 0; i < rosterSize; i++)
    {
        if(id == roster[i]->getID())
            return true;
    }
    return false;
}

const Player* Team::getPlayerByID(int id) const
{
    for(int i = 0; i < rosterSize; i++)
    {
        if(id == roster[i]->getID())
            return roster[i];
    }
    return NULL;
}

//same as above without the const
Player* Team::getPlayer(int id)
{
    for(int i = 0; i < rosterSize; i++)
    {
        if(id == roster[i]->getID())
            return roster[i];
    }
    return NULL;
}

int Team::getTotalScore()
{
    int total = 0;

    for (int i = 0; i < rosterSize; i++)
    {
        total += roster[i]->getPointsScored();
    }

    return total;
}

//code that compares to get the player with the highest score.
int Team::getHighScore()
{
    int highestPlayerIndex = 0;
    int highScore;

    for (int i = 0; i < rosterSize; i++)
    {
        if(roster[i]->getPointsScored() > highScore) highestPlayerIndex = i;
    }

   return highestPlayerIndex;
}
