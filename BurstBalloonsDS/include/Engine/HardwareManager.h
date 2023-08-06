#pragma once
#if !defined(HARDWARE_MANAGER_H) 
#define HARDWARE_MANAGER_H 1
#include "Rect.h"
#include<nds/arm9/console.h>

class HardwareManager
{
public:
	static void InitAndSetEverything();
	static void PowerOnConsole();
	static void InitVideo();
	static void InitAudio();
	static void SetVRAM();
	static void SetBackgrounds();
	static PrintConsole *printConsole;
	static void SetPrintConsole();
		
	static void StartMillisecondsTimer();

	static float GetCurrentMilliseconds();
	static float GetCurrentSeconds();

	static void WaitForNextFrame();
	static void ClearScreens();

	static int background2SubID;
	static int background3SubID;
	static int background2MainID;
	static int background3MainID;
	static Rect* screenRect;
};

#endif  