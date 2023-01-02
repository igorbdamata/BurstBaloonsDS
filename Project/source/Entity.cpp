#include "Entity.h"
#include "Vector2.h"
#include <nds.h>

Entity::Entity(Vector2 position, u8* tiles,const void* pal, uint32 size, int tilescount)
{
    this->position = position;
    sprite[0] = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);
    dmaCopy(tiles, sprite[0], SpriteSize_32x32);
}


void Entity::RenderInLowerScreen(void* pal, int priority)
{
    oamSet(&oamSub, 
			priority, 
			position.x, position.y, 
			0, 
			0,
			SpriteSize_32x32,
			SpriteColorFormat_256Color, 
			sprite[0] ,
			-1, 
			false, 
			false,
			false,
			false, 
			false);
}