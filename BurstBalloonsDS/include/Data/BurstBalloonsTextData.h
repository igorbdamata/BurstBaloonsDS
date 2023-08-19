#pragma once
#if !defined(BURST_BALLOONS_TEXT_DATA_H)
#define BURST_BALLOONS_TEXT_DATA_H true
#include<nds/arm9/video.h>
#include<string>
#include"Engine/Vector2.h"

class BurstBalloonsTextData
{
public:
	static const int TILES_LENGTH = 2;

	static const int TILE_WIDTH = 64;
	static const int TILE_HEIGHT = 64;

	static const int CENTERED_POSITION_X = SCREEN_WIDTH / 2 - 53;
	static const int CENTERED_POSITION_Y = SCREEN_HEIGHT / 2 - 21;

	static const void* GetTile(int tileID);

	static const std::string GetName();
	static Vector2* GetCenteredPositionForTile(int id);
private:
	static const void* TILES[2];
};
#endif