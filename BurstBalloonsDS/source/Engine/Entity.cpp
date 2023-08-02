#include "Engine/Entity.h"
#include "Engine/HardwareManager.h"
#include "Engine/Vector2.h"
#include <nds.h>
#include <string>

Entity::Entity() {};
Entity::Entity(Vector2* position, SpriteSize spriteSize, int width, int height, Vector2* spriteOffset)
{
	this->position = position;
	this->spriteSize = spriteSize;
	spriteRect = new Rect(this->position, spriteOffset, width, height);
}
Entity::Entity(SpriteSize spriteSize)
{
	this->spriteSize = spriteSize;
	spriteRect = new Rect(nullptr, nullptr, 0, 0);
}

void Entity::Init(int oamID, OamState* engine)
{
	this->oamID = oamID;
	this->engine = engine;
}

void Entity::Render(bool horizontalFlip, bool verticalFlip)
{
	bool hide = spriteRect->IsOutOfScreen();
	oamSet(engine, oamID, 
		   this->position->x, this->position->y, 
		   OBJPRIORITY_0, palleteID, spriteSize, SpriteColorFormat_16Color,
		   spriteAddress, -1, false, hide, horizontalFlip, verticalFlip, false);
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