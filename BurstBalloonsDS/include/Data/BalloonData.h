#pragma once
#if !defined(BALLOON_DATA_H)
#define BALLOON_DATA_H true
#include"../Engine/Vector2.h"
#include<nds/arm9/sprite.h>
class BalloonData
{
public:
	static const int SPRITE_OFFSET_X = 20;
	static const int SPRITE_OFFSET_Y = 5;
	static const int SPRITE_WIDTH = 22;
	static const int SPRITE_HEIGHT = 51;

	static const int COLLIDER_OFFSET_X = 20;
	static const int COLLIDER_OFFSET_Y = 5;
	static const int COLLIDER_WIDTH = 22;
	static const int COLLIDER_HEIGHT = 27;

	static const SpriteSize SPRITE_SIZE = SpriteSize_64x64;
	
	static const float SPEED_ON_MAX_DIFFICULT;
	static const char* INITIAL_ANIMATION ;

	static const int POSITION_Y_VARIATION_ON_SPAWN= 100;
};
#endif
