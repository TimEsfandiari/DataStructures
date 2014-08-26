#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    int id;
    string name;
    string team;
public:
    Player();
    Player(int id, string& name, string& team);
    void setID(int i);
    int getID();
    void setName(string& c);
    string getName();
    void setTeam(string& c);
    string getTeam();

};

#endif // PLAYER_H
