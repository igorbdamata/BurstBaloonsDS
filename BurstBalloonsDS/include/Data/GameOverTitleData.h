#pragma once
#if !defined (GAME_OVER_TITLE_DATA_H)
#define GAME_OVER_TITLE_DATA_H true
#include "../Engine/Vector2.h"

class GameOverTitleData
{
public:
	static const void* TILES[4];

	static Vector2* GetCenteredPosition();
private:
	static const float CENTERED_POSITION_X;
	static const float CENTERED_POSITION_Y;
};

#endif