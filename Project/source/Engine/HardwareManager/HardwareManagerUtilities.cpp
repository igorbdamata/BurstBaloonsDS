#include "Engine\HardwareManager.h"
#include <nds.h>

const double CPU_CLOCK = 33.514;

float HardwareManager::GetCurrentMilliseconds()
{
    return cpuGetTiming() / CPU_CLOCK / 1024;
}

void HardwareManager::WaitForNextFrame()
{
    swiWaitForVBlank();
}

void HardwareManager::ClearScreens()
{
    oamClear(&oamSub, 0, 0);
    oamClear(&oamMain, 0, 0);
    consoleClear();
}