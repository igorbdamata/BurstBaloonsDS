#include <nds/arm9/video.h>
#include "Data/HardwareData.h"

const double HardwareData::CPU_CLOCK = 33.514;
Rect* HardwareData::screenRect = new Rect(new Vector2(0, 0), new Vector2(0, 0), SCREEN_WIDTH, SCREEN_HEIGHT);