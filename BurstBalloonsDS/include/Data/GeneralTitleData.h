#pragma once
#if !defined(DEFAULT_TITLE_TEXT_H)
#define DEFAULT_TITLE_TEXT_H true

#include <nds/arm9/video.h>
#include <nds/arm9/sprite.h>
#include <string>

#include "Engine/Vector2.h"

class GeneralTitleData
{
public:
	static const int TITLES_COUNT = 4;

	static const int TILE_WIDTH = 64;
	static const int TILE_HEIGHT = 64;

	static const int OFFSET_X = 0;
	static const int OFFSET_Y = 0;

	static const SpriteSize SPRITE_SIZE = SpriteSize_64x64;
};

#endif