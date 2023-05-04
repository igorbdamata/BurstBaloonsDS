#if !defined(ENTITY_H)
#define ENTITY_H 1
#pragma once

#include <nds.h>
#include "Vector2.h"

class Entity
{
public:
    Vector2 position;

    Entity();
    Entity(int oamID, void *sprite, Vector2 position, OamState *engine, SpriteSize spriteSize);
    void Render(bool horizontalFlip = false, bool verticalFlip = false);
    
    void* GetSpriteAddress();
    int GetOamID();
    
    void ChangePalleteTo(int newPalleteID);

protected:
    void *sprite;
    OamState *engine;
    int palleteID;

private:
    int oamID;
    SpriteSize spriteSize;
};

#endif