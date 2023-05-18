#if !defined(OAM_ENGINE_H)
#define OAM_ENGINE_H 1
#pragma once

#include "Entity.h"
#include "AnimatedEntity.h"

#include <nds.h>
#include <map>
#include <iostream>
#include <map>

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

    void InitEntity(Entity *entity);
    void AddPallete(const void *pallete, const char *pallateName);
    int GetPallete(const char *palleteName);

    void AddSprite(const char *spriteName, const void *tiles, SpriteSize spriteSize);
    void *GetSprite(const char *spriteName);

    void UpdateOam();

private:
    int availableOamIndex;
    int availablePalleteIndex;

    std::map<const char *, int> palletes;
    std::map<const char *, void *> sprites;

    u16 *oamAddress;
    u16 *palletesAddress;
    u16 *backgroundRam;
    OamState *oamState;

    void InitOam();
    void SetPrintConsole();

    int GetAvailableOamIndex();
    int GetAvailablePalleteIndex();

    void CopyPalleteOnMemory(const void *pallete, int oamID);
    void CopyGraphicsOnMemory(const void *tiles, void *graphicMemory, SpriteSize spriteSize);
};

#endif