#include <nds.h>
#include "Engine\OamEngine.h"

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
    sprites = screen == UPPER ? SPRITE_GFX : SPRITE_GFX_SUB;
    palletes = screen == UPPER ? SPRITE_PALETTE : SPRITE_PALETTE_SUB;
    backgroundRam = (uint16 *)(screen == UPPER ? BG_BMP_RAM(0) : BG_BMP_RAM_SUB(0));
    availableOamIndex = 0;
    InitOam();
    SetPrintConsole();
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

AnimatedEntity OamEngine::GetNewAnimatedEntity(Vector2 position, const void *tiles, uint32 tilesSize, const void *pallete, SpriteSize spriteSize, const char *defaultAnimation)
{
    Entity entity = GetNewEntity(position, tiles, tilesSize, pallete, spriteSize);
    AnimatedEntity animatedEntity = AnimatedEntity(entity.GetOamID(), entity.GetSpriteAddress(), position, oamState, spriteSize, defaultAnimation);
    return animatedEntity;
}

Entity OamEngine::GetNewEntity(Vector2 position, const void *tiles, uint32 tilesSize, const void *pallete, SpriteSize spriteSize)
{
    int oamID = GetAvailableOamIndex();
    void *graphicMemory = oamAllocateGfx(oamState, spriteSize, SpriteColorFormat_16Color);

    CopyPalleteOnMemory(pallete, oamID);
    CopyGraphicsOnMemory(tiles, graphicMemory, spriteSize);

    Entity entity = Entity(oamID, graphicMemory, position, oamState, spriteSize);
    return entity;
}

int OamEngine::GetAvailableOamIndex()
{
    assert(availableOamIndex < SPRITE_COUNT);
    return availableOamIndex++;
}

void OamEngine::CopyPalleteOnMemory(const void *pallete, int oamID)
{
    DC_FlushAll();
    dmaCopy(pallete, palletes + COLORS_PER_PALETTE * oamID, COLORS_PER_PALETTE);
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