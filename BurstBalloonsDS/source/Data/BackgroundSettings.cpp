#include <nds/arm9/background.h>
#include "Data/BackgroundSettings.h"

const u16* BackgroundSettings::BACKGROUND3_MAIN_RAM = BG_BMP_RAM(BackgroundSettings::BACKGROUND3_MAIN_MAP_BASE);
const u16* BackgroundSettings::BACKGROUND2_MAIN_RAM = BG_BMP_RAM(BackgroundSettings::BACKGROUND2_MAIN_MAP_BASE);

const u16* BackgroundSettings::BACKGROUND3_SUB_RAM = BG_BMP_RAM_SUB(BackgroundSettings::BACKGROUND3_SUB_MAP_BASE);