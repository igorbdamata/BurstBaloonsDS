#include "Engine/HardwareManager.h"
#include <nds.h>

const double CPU_CLOCK = 33.514;
const int MILLISECONDS_PER_CYCLE = 125000;
int timeCycles = 0;
float lastMilliseconds = 0;

Rect* HardwareManager::screenRect = new Rect(new Vector2(0, 0), new Vector2(0, 0), SCREEN_WIDTH, SCREEN_HEIGHT);

float HardwareManager::GetCurrentSeconds()
{
	return HardwareManager::GetCurrentMilliseconds() / 1000;
}

float HardwareManager::GetCurrentMilliseconds()
{
	float currentMilliseconds = cpuGetTiming() / CPU_CLOCK / 1024;
	if (currentMilliseconds < lastMilliseconds) timeCycles++;
	lastMilliseconds = currentMilliseconds;
	return currentMilliseconds + MILLISECONDS_PER_CYCLE * timeCycles;
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
