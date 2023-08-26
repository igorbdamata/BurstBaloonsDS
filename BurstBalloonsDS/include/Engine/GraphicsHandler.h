#pragma once
#if !defined(GRAPHICS_HANDLER_H)
#define GRAPHICS_HANDLER_H true

#include <nds.h>
#include <nds/arm9/console.h>

#include <map>
#include <string>

#include "Entity.h"

enum Screen
{
	BOTTOM,
	TOP
};

class GraphicsHandler
{
public:

	GraphicsHandler(Screen screen);

	void Update();

	void SetBackgroundTo(const void* backgroundBitmap, uint32 backgroundSize, int layer = 3);
	void SetTextFontTo(void* fontTiles, void* fontPalette, u16 fontPaletteLength);

	void AddSprite(std::string spriteName, const void* tiles, SpriteSize spriteSize);
	void* GetSprite(std::string spriteName);

	void AddPalette(const void* palette, std::string pallateName);
	int GetPalette(std::string paletteName);

	void InitEntity(Entity* entity);

	Screen GetScreen();
private:
	Screen screen;

	int availableOamIndex;
	int availablePaletteIndex;

	std::map<std::string, int> palettes;
	std::map<std::string, void*> sprites;

	u16* oamAddress;
	u16* palettesAddress;
	u16* backgroundAddress[4];
	OamState* oamState;

	int GetAvailableOamIndex();
	int GetAvailablePaletteIndex();
};

#endif