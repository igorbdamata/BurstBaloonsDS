#pragma once
#include "Vector2.h"
#include <nds.h>

class Entity
{
public:
    Entity(Vector2 position,   u8* tiles, void* pal);
    Vector2 position;
	u16* sprite[12];
private:
    void InitSprite(u8* tiles, void* pal);
};