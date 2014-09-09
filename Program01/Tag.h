#ifndef TAG_H
#define TAG_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

class Player;

using namespace std;

class Tag
{
private:
    const Player* tagger;
    const Player* target;
    int time;
    int hitBox;
public:
    Tag();
    Tag(const Player* tgr, const Player* trgt, int clock, int hit);
    void setTagger(const Player* i);
    const Player* getTagger();
    void setTarget(const Player* i);
    const Player* getTarget();
    void setTime(int i);
    int getTime();
    void setHitBox(int i);
    int getHitBox();
};

#endif // TAG_H
