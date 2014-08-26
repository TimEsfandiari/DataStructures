#include "Tag.h"

Tag::Tag()
{
}
void Tag::setTagger(int i)
{
    tagger = i;
}

int Tag::getTagger()
{
    return tagger;
}

void Tag::setTarget(int i)
{
    target = i;
}

int Tag::getTarget()
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
