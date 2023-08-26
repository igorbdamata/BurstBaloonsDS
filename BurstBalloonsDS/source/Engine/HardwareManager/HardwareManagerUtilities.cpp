#include <nds.h>
#include <nds/arm9/sprite.h>

#include "Engine/HardwareManager.h"

#include "Data/HardwareData.h"

int HardwareManager::timeLoops = 0;
float HardwareManager::lastMilliseconds = 0;

float HardwareManager::GetCurrentSeconds()
{
	return HardwareManager::GetCurrentMilliseconds() / 1000;
}
float HardwareManager::GetCurrentMilliseconds()
{
	float currentMilliseconds = cpuGetTiming() / HardwareData::CPU_CLOCK / 1024;
	if (currentMilliseconds < lastMilliseconds) timeLoops++;
	lastMilliseconds = currentMilliseconds;
	return currentMilliseconds + HardwareData::MILLISECONDS_PER_TIMER_LOOP * timeLoops;
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

int HardwareManager::GetSubBackground3ID()
{
	return subBackground3ID;
}
int HardwareManager::GetMainBackground3ID()
{
	return mainBackground3ID;
}
int HardwareManager::GetMainBackground2ID()
{
	return mainBackground2ID;
}