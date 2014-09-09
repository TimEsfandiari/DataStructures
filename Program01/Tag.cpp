#include "Tag.h"

Tag::Tag()
{
}
Tag::Tag(const Player* tgr, const Player* trgt, int clock, int hit)
{
    tagger = tgr;
    target = trgt;
    time = clock;
    hitBox = hit;
}
void Tag::setTagger(const Player* i)
{
    tagger = i;
}

const Player* Tag::getTagger()
{
    return tagger;
}

void Tag::setTarget(const Player* i)
{
    target = i;
}

const Player* Tag::getTarget()
{
    return target;
}

void Tag::setTime(int i)
{
    time = i;
}

int Tag::getTime()
{
    return time;
}

void Tag::setHitBox(int i)
{
    hitBox = i;
}

int Tag::getHitBox()
{
    return hitBox;
}
