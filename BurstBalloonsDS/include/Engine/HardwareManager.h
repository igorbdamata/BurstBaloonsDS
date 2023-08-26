#pragma once
#if !defined(HARDWARE_MANAGER_H) 
#define HARDWARE_MANAGER_H true

#include <nds/arm9/console.h>

class HardwareManager
{
public:
	static void InitAndSetEverything();

	static void PowerConsoleOn();
	static void InitVideo();
	static void InitAudio();
	static void SetVRAM();
	static void SetBackgrounds();
	static void SetPrintConsole();
	static void StartMillisecondsTimer();

	static float GetCurrentSeconds();
	static float GetCurrentMilliseconds();

	static void WaitForNextFrame();
	static void ClearScreens();

	static int GetSubBackground3ID();
	static int GetMainBackground3ID();
	static int GetMainBackground2ID();

	static PrintConsole* printConsole;

private:
	static int subBackground3ID;
	static int mainBackground2ID;
	static int mainBackground3ID;

	static int timeLoops;
	static float lastMilliseconds;
};

#endif  