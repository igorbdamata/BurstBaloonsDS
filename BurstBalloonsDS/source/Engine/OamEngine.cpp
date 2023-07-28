#include <nds.h>
#include <nds\arm9\sprite.h>
#include <nds\arm9\background.h>
#include "Engine/OamEngine.h"

const int COLORS_PER_PALETTE = 16;
const int DEFAULT_BACKGROUND_ID = 3;

const int TILE_BASE = 0;
const int FONT_MAP_BASE = 2;
const int FONT_LAYER = 1;

OamEngine::OamEngine(Screen screen)
{
    this->screen = screen;
    oamState = screen == UPPER ? &oamMain : &oamSub;
    oamAddress = screen == UPPER ? OAM : OAM_SUB;
    palletesAddress = screen == UPPER ? SPRITE_PALETTE : SPRITE_PALETTE_SUB;
    backgroundRam = (uint16 *)(screen == UPPER ? BG_BMP_RAM(1) : BG_BMP_RAM_SUB(8));
    availableOamIndex = 0;
    availablePalleteIndex = 0;
    InitOam();
}
void OamEngine::InitOam()
{
    oamClear(oamState, 0, 0);
}
void OamEngine::SetPrintConsole()
{
    delete printConsole;
    printConsole = consoleInit(NULL, FONT_LAYER,
                               BgType_Text4bpp, BgSize_T_256x256,
                               FONT_MAP_BASE, TILE_BASE,
                               this->screen == UPPER, false);
}

void OamEngine::SetBackgroundTo(const unsigned int *backgroundBitmap, uint32 backgroundSize)
{
    dmaCopyHalfWords(DEFAULT_BACKGROUND_ID,
                     backgroundBitmap,
                     backgroundRam,
                     backgroundSize);
}
void OamEngine::SetTextFont(void *fontTiles, void *fontPallete, u16 fontPalleteLength)
{
    ConsoleFont font;
    font.gfx = (u16 *)fontTiles;
    font.pal = (u16 *)fontPallete;
    font.numChars = 95;
    font.numColors = fontPalleteLength / 2;
    font.bpp = 4;
    font.asciiOffset = 32;
    font.convertSingleColor = false;
    consoleSetFont(printConsole, &font);
}

void OamEngine::AddPallete(const void *pallete, const char *palleteName)
{
    int palleteIndex = GetAvailablePalleteIndex();
    palletes.insert(std::make_pair(palleteName, palleteIndex));
    DC_FlushAll();
    dmaCopy(pallete, palletesAddress + COLORS_PER_PALETTE * palleteIndex, COLORS_PER_PALETTE);
}

int OamEngine::GetPallete(const char *palleteName)
{
    return palletes[palleteName];
}

void OamEngine::InitEntity(Entity *entity)
{
    int oamID = GetAvailableOamIndex();
    entity->Init(oamID, oamState);
}

int OamEngine::GetAvailableOamIndex()
{
    assert(availableOamIndex < SPRITE_COUNT);
    return availableOamIndex++;
}
int OamEngine::GetAvailablePalleteIndex()
{
    assert(availablePalleteIndex < 16);
    return availablePalleteIndex++;
}

void OamEngine::CopyGraphicsOnMemory(const void *tiles, void *graphicMemory, SpriteSize spriteSize)
{
    DC_FlushAll();
    dmaCopy(tiles, graphicMemory, spriteSize);
}

void OamEngine::UpdateOam()
{
    oamUpdate(oamState);
}

void OamEngine::AddSprite(const char *spriteName, const void *tiles, SpriteSize spriteSize)
{
    void *spriteAddress = oamAllocateGfx(oamState, spriteSize, SpriteColorFormat_16Color);
    sprites.insert(std::make_pair(spriteName, spriteAddress));
    CopyGraphicsOnMemory(tiles, spriteAddress, spriteSize);
}
void *OamEngine::GetSprite(const char* spriteName)
{
    return sprites[spriteName];
}