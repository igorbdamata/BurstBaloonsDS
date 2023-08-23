#include <nds/arm9/background.h>
#include "Data/BackgroundData.h"

const u16* BackgroundData::BACKGROUND3_MAIN_RAM = BG_BMP_RAM(BackgroundData::BACKGROUND3_MAIN_MAP_BASE);
const u16* BackgroundData::BACKGROUND2_MAIN_RAM = BG_BMP_RAM(BackgroundData::BACKGROUND2_MAIN_MAP_BASE);

const u16* BackgroundData::BACKGROUND3_SUB_RAM = BG_BMP_RAM_SUB(BackgroundData::BACKGROUND3_SUB_MAP_BASE);