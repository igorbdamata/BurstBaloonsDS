#if !defined(ENTITY_H)
#define ENTITY_H true
#pragma once

#include <nds/arm9/sprite.h>
#include "Vector2.h"
#include "Rect.h"

class Entity
{
public:
	Vector2* position;

	Entity();
	Entity(Vector2* position, int width, int height, Vector2* spriteOffset, SpriteSize spriteSize);
	Entity(SpriteSize spriteSize);

	void Init(int oamID, OamState* engine);

	void Render(bool horizontalFlip = false, bool verticalFlip = false);

	void* GetSprite();
	void SetSpriteTo(void* newSprite);

	int GetCurrentPalette();
	void SetPaletteTo(int newPaletteID);

	int GetOamID();

	SpriteSize GetSpriteSize();

protected:
	OamState* engine;
	Rect* spriteRect;

private:
	int oamID;
	int paletteID;
	void* spriteAddress;
	SpriteSize spriteSize;
};

#endif