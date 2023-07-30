#pragma once
#if !defined(BURST_BALLOONS_TEXT_DATA_H)
#define BURST_BALLOONS_TEXT_DATA_H 1
#include<nds/arm9/video.h>
#include<string>
#include"Engine/Vector2.h"

class BurstBalloonsTextData
{
public:
	static const int tilesCount = 2;

	static const int tileWidth = 64;
	static const int tileHeight = 64;

	static const int centeredPositionX = SCREEN_WIDTH / 2 - 53;
	static const int centeredPositionY = SCREEN_HEIGHT / 2 - 21;

	static const void* GetTile(int tileID);

	static const std::string GetName();
	static Vector2* GetCenteredPositionForTile(int id);
private:
	static const void* tiles[2];
};
#endif