#include "Engine/Entity.h"
#include "Engine/Vector2.h"
#include <nds.h>

Entity::Entity(){};
Entity::Entity(Vector2* position, SpriteSize spriteSize)
{
    this->position = position;
    this->spriteSize = spriteSize;
}

void Entity::Init(int oamID, OamState* engine)
{
    this->oamID = oamID;
    this->engine=engine;
}

void Entity::Render(bool horizontalFlip, bool verticalFlip)
{
    const bool hide = false;
    oamSet(engine, oamID, position->x, position->y, OBJPRIORITY_0, palleteID, spriteSize, SpriteColorFormat_16Color,
           spriteAddress, -1, false, hide, horizontalFlip, verticalFlip, false);
}

void *Entity::GetSpriteAddress()
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