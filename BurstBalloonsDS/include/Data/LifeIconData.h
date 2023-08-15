#pragma once
#if !defined(LIFE_ICON_H)
#define LIFE_ICON_H true
#include<nds/arm9/sprite.h>

class LifeIconData
{
public:
	static const int SPRITE_WIDTH = 32;
	static const int SPRITE_HEIGHT = 32;
	static const int SPRITE_OFFSET_X = 10;
	static const int SPRITE_OFFSET_Y = 3;

	static const int DISTANCE_BETWEEN_LIFE_ICONS = 20;
	static const int LIFE_ICON_HORIZONTAL_ALIGNMENT = 0;
	static const int LIFE_ICON_VERTICAL_ALIGNMENT = 3;
	
	static const SpriteSize SPRITE_SIZE = SpriteSize_32x32;
};
#endif