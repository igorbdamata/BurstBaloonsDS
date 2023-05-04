#pragma once
#include "AnimatedEntity.h"

class Balloon : public AnimatedEntity
{
public:
    Balloon(Vector2 position, SpriteSize spriteSize, const char *defaultAnimation, const void *tiles);
};