#include "Engine/Entity.h"
#include "Engine/Vector2.h"
#include <nds.h>

Entity::Entity() {};
Entity::Entity(Vector2* position, SpriteSize spriteSize, int width, int height)
{
	this->position = position;
	this->spriteSize = spriteSize;
	this->width = width;
	this->height = height;
}

void Entity::Init(int oamID, OamState* engine)
{
	this->oamID = oamID;
	this->engine = engine;
}

void Entity::Render(bool horizontalFlip, bool verticalFlip)
{
	bool hide = IsOutOfScreen();
	oamSet(engine, oamID, position->x, position->y, OBJPRIORITY_0, palleteID, spriteSize, SpriteColorFormat_16Color,
		   spriteAddress, -1, false, hide, horizontalFlip, verticalFlip, false);
}
bool Entity::IsOutOfScreen()
{
	if (position->x + width < 0) return true;
	if (position->x > SCREEN_WIDTH)return true;
	if (position->y + height < 0) return true;
	if (position->y > SCREEN_HEIGHT) return true;
	return false;
}

void* Entity::GetSpriteAddress()
{
	return spriteAddress;
}
int Entity::GetOamID()
{
	return oamID;
}
SpriteSize Entity::GetSpriteSize()
{
	return spriteSize;
}


void Entity::ChangePalleteTo(int newPalleteID)
{
	palleteID = newPalleteID;
}

void Entity::SetSpriteAddressTo(void* newSprite)
{
	spriteAddress = newSprite;
}