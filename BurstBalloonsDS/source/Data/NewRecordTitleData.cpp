#include "Data/NewRecordTitleData.h"

#include"TextPassRecord0.h"
#include"TextPassRecord1.h"
#include"TextPassRecord2.h"
#include"TextPassRecord3.h"

const void* NewRecordTitleData::TILES[4]
{
	TextPassRecord0Tiles,
	TextPassRecord1Tiles,
	TextPassRecord2Tiles,
	TextPassRecord3Tiles
};

const float NewRecordTitleData::CENTERED_POSITION_X = 16.0f;
const float NewRecordTitleData::CENTERED_POSITION_Y = 76.0f;

Vector2* NewRecordTitleData::GetCenteredPosition()
{
	return new Vector2(CENTERED_POSITION_X, CENTERED_POSITION_Y);
}