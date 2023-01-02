#include "Entity.h"
#include "Vector2.h"
#include <nds.h>

Entity::Entity(Vector2 position, u8* tiles, void* pal)
{
    this->position = position;
    InitSprite(tiles, pal);
}

void Entity::InitSprite( u8* tiles, void* pal)
{
    int i;
	for(i = 0; i < 12; i++)
	{
		sprite[i] = oamAllocateGfx(&oamSub, SpriteSize_32x32, SpriteColorFormat_256Color);
		dmaCopy(tiles, sprite[i], 32*32);
		tiles += 32*32;
	}

    dmaCopy(pal, SPRITE_PALETTE_SUB, 512);
}
