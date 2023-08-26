#include "Data/GameOverTitleData.h"

#include"GameOverText0.h"
#include"GameOverText1.h"
#include"GameOverText2.h"
#include"GameOverText3.h"

const void* GameOverTitleData::TILES[4]
{
	GameOverText0Tiles,
	GameOverText1Tiles,
	GameOverText2Tiles,
	GameOverText3Tiles
};

const float GameOverTitleData::CENTERED_POSITION_X = 24.0f;
const float GameOverTitleData::CENTERED_POSITION_Y = 76.0f;

Vector2* GameOverTitleData::GetCenteredPosition()
{
	return new Vector2(CENTERED_POSITION_X, CENTERED_POSITION_Y);
}