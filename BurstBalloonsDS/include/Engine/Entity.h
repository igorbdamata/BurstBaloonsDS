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
    Entity(Vector2* position, SpriteSize spriteSize);
    void Init(int oamID,  OamState *engine);
    void Render(bool horizontalFlip = false, bool verticalFlip = false);

    void *GetSpriteAddress();
    void *spriteAddress;
    int GetOamID();
    SpriteSize GetSpriteSize();

    void ChangePalleteTo(int newPalleteID);

protected:
    OamState *engine;
    int palleteID;

private:
    int oamID;
    SpriteSize spriteSize;
};

#endif