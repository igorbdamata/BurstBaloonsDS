#include "Entity.h"
#include "Vector2.h"
#include <nds.h>

Entity::Entity(Vector2 position, u8* tiles,const void* pal, uint32 size, int tilescount)
{
    this->position = position;
    sprite[0] = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);
		if(position.y == 0)
		{
			for(int i=0; i< SpriteSize_32x32;i++)
				{
					sprite[0][i] += 36;
					sprite[0][i] |= 1<<8;

				}
		}
	
	
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