#if !defined(BACKGROUND_SETTINGS)	
#define BACKGROUND_SETTINGS true
#pragma once
#include <nds/arm9/background.h>
class BackgroundData
{
public:
	static const int FONT_MAP_BASE = 2;
	static const int FONT_LAYER = 1;

	static const int BACKGROUND2_MAIN_MAP_BASE = 8;
	static const int BACKGROUND3_MAIN_MAP_BASE = 1;

	static const int BACKGROUND3_SUB_MAP_BASE = 0;

	static const u16* BACKGROUND3_MAIN_RAM;
	static const u16* BACKGROUND2_MAIN_RAM;
	static const u16* BACKGROUND3_SUB_RAM;
};
#endif;