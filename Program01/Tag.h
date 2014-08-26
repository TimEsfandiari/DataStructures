#ifndef TAG_H
#define TAG_H

#include <iostream>
#include <string>

using namespace std;

class Tag
{
private:
    int tagger;
    int target;
    int time;
    int hitBox;
public:
    Tag();
    void setTagger(int i);
    int getTagger();
    void setTarget(int i);
    int getTarget();
    void setTime(int i);
    int getTime();
    void setHitBox(int i);
    int getHitBox();
};

#endif // TAG_H
