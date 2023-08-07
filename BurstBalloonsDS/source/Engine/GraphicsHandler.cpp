#include <nds.h>
#include <nds/arm9/sprite.h>
#include <nds/arm9/background.h>

#include "Engine/GraphicsHandler.h"
#include "Engine/HardwareManager.h"

#include "Data/BackgroundSettings.h"
#include "Data/HardwareData.h"

GraphicsHandler::GraphicsHandler(Screen screen)
{
	this->screen = screen;

	oamState = screen == TOP ? &oamMain : &oamSub;
	oamAddress = screen == TOP ? OAM : OAM_SUB;
	palettesAddress = screen == TOP ? SPRITE_PALETTE : SPRITE_PALETTE_SUB;
	
	backgroundAddress[0] = NULL;
	backgroundAddress[1] = NULL;
	backgroundAddress[2] = (uint16*) (screen == TOP ? BackgroundSettings::BACKGROUND2_MAIN_RAM : NULL);
	backgroundAddress[3] = (uint16*) (screen == TOP ? BackgroundSettings::BACKGROUND3_MAIN_RAM : 
													  BackgroundSettings::BACKGROUND3_SUB_RAM);
	availableOamIndex = 0;
	availablePaletteIndex = 0;

	oamClear(oamState, 0, 0);
}

void GraphicsHandler::Update()
{
	oamUpdate(oamState);
}

void GraphicsHandler::SetBackgroundTo(const void* backgroundBitmap, uint32 backgroundSize, int layer)
{
	dmaCopy(backgroundBitmap, backgroundAddress[layer], backgroundSize);
}

void GraphicsHandler::SetTextFontTo(void* fontTiles, void* fontPalette, u16 fontPaletteLength)
{
	ConsoleFont font;
	font.gfx = (u16*) fontTiles;
	font.pal = (u16*) fontPalette;
	font.numChars = 95;
	font.numColors = fontPaletteLength / 2;
	font.bpp = 4;
	font.asciiOffset = 32;
	font.convertSingleColor = false;
	consoleSetFont(HardwareManager::printConsole, &font);
}

void GraphicsHandler::AddSprite(std::string spriteName, const void* tiles, SpriteSize spriteSize)
{
	void* spriteAddress = oamAllocateGfx(oamState, spriteSize, SpriteColorFormat_16Color);
	sprites.insert(std::make_pair(spriteName, spriteAddress));
	dmaCopy(tiles, spriteAddress, spriteSize);
}
void* GraphicsHandler::GetSprite(std::string spriteName)
{
	return sprites[spriteName];
}

void GraphicsHandler::AddPalette(const void* palette, std::string paletteName)
{
	int paletteIndex = GetAvailablePaletteIndex();
	palettes.insert(std::make_pair(paletteName, paletteIndex));
	dmaCopy(palette, palettesAddress + HardwareData::COLORS_PER_PALETTE * paletteIndex, HardwareData::COLORS_PER_PALETTE);
}
int GraphicsHandler::GetPalette(std::string paletteName)
{
	return palettes[paletteName];
}

void GraphicsHandler::InitEntity(Entity* entity)
{
	int oamID = GetAvailableOamIndex();
	entity->Init(oamID, oamState);
}

int GraphicsHandler::GetAvailableOamIndex()
{
	assert(availableOamIndex < SPRITE_COUNT);
	return availableOamIndex++;
}
int GraphicsHandler::GetAvailablePaletteIndex()
{
	assert(availablePaletteIndex < 16);
	return availablePaletteIndex++;
}

Screen GraphicsHandler::GetScreen()
{
	return screen;
}