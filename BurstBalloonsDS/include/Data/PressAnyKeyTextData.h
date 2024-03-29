#pragma once
#if !defined(PRESS_ANY_KEY_TEXT_DATA_H)
#define PRESS_ANY_KEY_TEXT_DATA_H true

#include <nds/arm9/video.h>
#include <nds/arm9/sprite.h>
#include <string>

#include "Engine/Vector2.h"

class PressAnyKeyTextData
{
public:
	static const int TILES_COUNT = 4;

	static const int TILE_WIDTH = 64;
	static const int TILE_HEIGHT = 64;

	static const int OFFSET_X = 26;
	static const int OFFSET_Y = -10;

	static const SpriteSize SPRITE_SIZE = SpriteSize_64x64;

	static const int CENTERED_POSITION_X = SCREEN_WIDTH / 2 - TILE_WIDTH * TILES_COUNT / 2 + OFFSET_X;
	static const int CENTERED_POSITION_Y = SCREEN_HEIGHT / 2 + OFFSET_Y;

	static const std::string GetName();
	static Vector2* GetCenteredPositionForTile(int id);
};

#endif