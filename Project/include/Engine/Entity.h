#if !defined(ENTITY_H)
#define ENTITY_H 1
#pragma once

#include <nds.h>
#include "Vector2.h"

class Entity
{
public:
    Vector2* position;

    Entity();
    Entity(Vector2* position, SpriteSize spriteSize, const void *tiles);
    void Init(int oamID, u16 *spriteAddress, OamState *engine);
    void Render(bool horizontalFlip = false, bool verticalFlip = false);

    u16 *GetSpriteAddress();
    int GetOamID();
    SpriteSize GetSpriteSize();

    void ChangePalleteTo(int newPalleteID);

protected:
    u16 *spriteAddress;
    void *tiles;
    OamState *engine;
    int palleteID;

private:
    int oamID;
    SpriteSize spriteSize;
};

#endif