#include "Data/PressAnyKeyTextData.h"
#include "PressAnyKeyText0.h"
#include "PressAnyKeyText1.h"
#include "PressAnyKeyText2.h"
#include "PressAnyKeyText3.h"
#include<nds/arm9/sassert.h>

const std::string PressAnyKeyTextData::GetName()
{
	return "PressAnyKeyText";
}

Vector2* PressAnyKeyTextData::GetCenteredPositionForTile(int id)
{
	return new Vector2(CENTERED_POSITION_X + TILE_WIDTH * id, CENTERED_POSITION_Y);
}