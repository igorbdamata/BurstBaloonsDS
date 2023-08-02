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
	oamSet(engine, GetOamID(),
		   this->position->x, this->position->y, 
		   OBJPRIORITY_0, GetCurrentPalette(), GetSpriteSize(), SpriteColorFormat_16Color,
		   GetSprite(), -1, false, hide, horizontalFlip, verticalFlip, false);
}

void* Entity::GetSprite()
{
	return spriteAddress;
}
void Entity::SetSpriteTo(void* newSpriteAddress)
{
	spriteAddress = newSpriteAddress;
}

int Entity::GetCurrentPalette()
{
	return paletteID;
}
void Entity::SetPaletteTo(int newPaletteID)
{
	paletteID = newPaletteID;
}

int Entity::GetOamID()
{
	return oamID;
}

SpriteSize Entity::GetSpriteSize()
{
	return spriteSize;
}