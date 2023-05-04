#include "Engine\Entity.h"
#include "Engine\Vector2.h"
#include <nds.h>

Entity::Entity(){};

Entity::Entity(int oamID, void *sprite, Vector2 position, OamState *engine, SpriteSize spriteSize)
{
    this->oamID = oamID;
    this->sprite = sprite;
    this->position = position;
    this->engine = engine;
    this->spriteSize = spriteSize;
    this->palleteID = oamID;
}

void Entity::Render(bool horizontalFlip, bool verticalFlip)
{
    const bool hide = false;
    oamSet(engine, oamID, position.x, position.y, OBJPRIORITY_0, palleteID, spriteSize, SpriteColorFormat_16Color,
           sprite, -1, false, hide, horizontalFlip, verticalFlip, false);
}

void *Entity::GetSpriteAddress()
{
    return sprite;
}
int Entity::GetOamID()
{
    return oamID;
}

void Entity::ChangePalleteTo(int newPalleteID)
{
    palleteID = newPalleteID;
}