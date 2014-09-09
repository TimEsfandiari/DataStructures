#include "Player.h"

Player::Player()
{
    id = 0;
    name = " ";
    team = " ";
}

Player::Player(int id, char* name, char* team)
{
    setID(id);
    setName(name);
    setTeam(team);
}

void Player::setID(int i)
{
    id = i;
}

int Player::getID() const
{
    return id;
}

void Player::setName(char* c)
{
    name = c;
}

char* Player::getName() const
{
    return name;
}

void Player::setTeam(char* c)
{
    team = c;
}

char* Player::getTeam() const
{
    return team;
}

void Player::addTag(Tag* tag)
{
    tags.push_back(tag);
}

const vector<Tag*>& Player::getTags() const
{
    return tags;
}

//I feel like the way I name and present my code,
//most stuff is self explanatory. But this might require
//a little explanation. I used a switch statement to allocate
//point values for the different hitboxes on the Laser Tag vest
//and added them up through here for each player's total.
int Player::getPointsScored() const
{
    int total = 0;

    for(int i = 0; i < tags.size(); i++)
    {
        switch(tags[i]->getHitBox())
        {
            case 1:
               total += 5;
               break;
            case 2:
                total += 8;
                break;
            case 3:
                total += 10;
                break;
            case 4:
                total += 15;
                break;
            default:
                break;
        }
    }
    return total;
}


int Player::getNumTags()
{
    return tags.size();
}
