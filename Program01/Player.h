#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "Tag.h"

using namespace std;

class Player
{
private:
    vector<Tag*> tags;
    int id;
    char* name;
    char* team;
public:
    Player();
    Player(int id, char* name, char* team);
    void setID(int i);
    int getID() const;
    void setName(char* c);
    char* getName() const;
    void setTeam(char* c);
    char* getTeam() const;
    void addTag(Tag* tag);
    const vector<Tag*>& getTags() const;
    int getPointsScored() const;
    int getNumTags();


};

#endif // PLAYER_H
