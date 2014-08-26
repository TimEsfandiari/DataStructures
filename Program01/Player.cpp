#include "Player.h"

Player::Player()
{
}

Player::Player(int id, string& name, string& team)
{
    setID(id);
    setName(name);
    setTeam(team);
}

void Player::setID(int i)
{
    id = i;
}

int Player::getID()
{
    return id;
}

void Player::setName(string& c)
{
    name = c;
}

string Player::getName()
{
    return name;
}

void Player::setTeam(string& c)
{
    team = c;
}

string Player::getTeam()
{
    return team;
}
