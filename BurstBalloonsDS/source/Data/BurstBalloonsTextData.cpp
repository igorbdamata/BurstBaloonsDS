#include "Data/BurstBalloonsTextData.h"
#include "BurstBalloonsText0.h"
#include "BurstBalloonsText1.h"
#include<nds/arm9/sassert.h>

const void* BurstBalloonsTextData::TILES[] = { BurstBalloonsText0Tiles, BurstBalloonsText1Tiles };

const void* BurstBalloonsTextData::GetTile(int tileID)
{
	sassert
	(
		TILE_HEIGHT >= 2,
		("The maximum tile id possible for BurstBalloonsText is 1. But the value used is: " + std::to_string(tileID)).c_str()
	);
	return TILES[tileID];
}

const std::string BurstBalloonsTextData::GetName()
{
	return "burstBalloonsText";
}

Vector2* BurstBalloonsTextData::GetCenteredPositionForTile(int id)
{
	return new Vector2(CENTERED_POSITION_X + TILE_WIDTH * id, CENTERED_POSITION_Y);
}