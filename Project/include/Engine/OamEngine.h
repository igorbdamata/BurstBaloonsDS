#if !defined(OAM_ENGINE_H)
#define OAM_ENGINE_H 1
#pragma once

#include "Entity.h"
#include "AnimatedEntity.h"

#include <nds.h>
#include <map>
#include <iostream>

enum Screen
{
    BOTTOM,
    UPPER
};

class OamEngine
{
public:
    Screen screen;
    PrintConsole *printConsole;

    OamEngine(Screen screen);

    void SetBackgroundTo(const unsigned int *backgroundBitmap, uint32 backgroundSize);
    void SetTextFont(void *fontTiles, void *fontPallete, u16 fontPalleteLength);

    AnimatedEntity GetNewAnimatedEntity(Vector2 position, const void *tiles, uint32 tilesSize, const void *pallete, SpriteSize spriteSize, const char *defaultAnimation);
    Entity GetNewEntity(Vector2 position, const void *tiles, uint32 tilesSize, const void *pallete, SpriteSize spriteSize);
    int GetAvailableOamIndex();

    void UpdateOam();

private:
    int availableOamIndex;

    u16 *oamAddress;
    u16 *palletes;
    u16 *sprites;
    u16 *backgroundRam;
    OamState *oamState;

    void InitOam();
    void SetPrintConsole();

    void CopyPalleteOnMemory(const void *pallete, int oamID);
    void CopyGraphicsOnMemory(const void *tiles, void *graphicMemory, SpriteSize spriteSize);
};

#endif