#pragma once
#include "Vector2.h"
#include <nds.h>

class Entity
{
public:
    Entity(Vector2 position,   u8* tiles,const void* pal, uint32 size, int tilescount);
    Vector2 position;
	u16* sprite[12];
    void RenderInLowerScreen( void* pal,int priority);
    void InitSprite(u8* tiles, const void* pal, uint32 size, int tilescount);

};