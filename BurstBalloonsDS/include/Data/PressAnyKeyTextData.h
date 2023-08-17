#pragma once
#if !defined(PRESS_ANY_KEY_TEXT_DATA_H )
#define PRESS_ANY_KEY_TEXT_DATA_H 1
#include<nds/arm9/video.h>
#include<string>
#include"Engine/Vector2.h"

class PressAnyKeyTextData
{
public:
	static const int TILES_LENGTH = 4;

	static const int TILE_WIDTH = 64;
	static const int TILE_HEIGHT = 64;

	static const int CENTERED_POSITION_X = SCREEN_WIDTH / 2 - TILE_WIDTH * TILES_LENGTH / 2 + 24;
	static const int CENTERED_POSITION_Y = SCREEN_HEIGHT / 2 + 80-100;

	static const std::string GetName();
	static Vector2* GetCenteredPositionForTile(int id);
};
#endif