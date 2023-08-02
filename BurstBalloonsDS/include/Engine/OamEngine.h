#if !defined(OAM_ENGINE_H)
#define OAM_ENGINE_H 1
#pragma once

#include "Entity.h"
#include "AnimatedEntity.h"

#include <nds.h>
#include <map>
#include <iostream>
#include <map>
#include <string>

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
    
    void SetPrintConsole();
    void SetTextFont(void *fontTiles, void *fontPallete, u16 fontPalleteLength);

    void InitEntity(Entity *entity);
    void AddPallete(const void *palette, const char *pallateName);
    int GetPallete(const char *palleteName);

    void AddSprite(std::string spriteName, const void *tiles, SpriteSize spriteSize);
    void *GetSprite(std::string spriteName);

    void UpdateOam();

private:
    int availableOamIndex;
    int availablePalleteIndex;

    std::map<const char *, int> palletes;
    std::map<std::string, void *> sprites;

    u16 *oamAddress;
    u16 *palletesAddress;
    u16 *backgroundRam;
    OamState *oamState;

    void InitOam();

    int GetAvailableOamIndex();
    int GetAvailablePalleteIndex();

    void CopyPalleteOnMemory(const void *palette, int oamID);
    void CopyGraphicsOnMemory(const void *tiles, void *graphicMemory, SpriteSize spriteSize);
};

#endif