#include <nds.h>
#include <nds/arm9/sprite.h>
#include <nds/arm9/background.h>

#include <maxmod9.h>
#include <soundbank_bin.h>

#include "Engine/HardwareManager.h"

#include "Engine/SoundManager.h"
#include "Data/BackgroundData.h"

int HardwareManager::subBackground3ID = -1;
int HardwareManager::mainBackground2ID = -1;
int HardwareManager::mainBackground3ID = -1;

PrintConsole* HardwareManager::printConsole = NULL;

void HardwareManager::InitAndSetEverything()
{
	HardwareManager::PowerConsoleOn();
	HardwareManager::InitAudio();
	HardwareManager::InitVideo();

	HardwareManager::SetBackgrounds();
	HardwareManager::SetPrintConsole();

	HardwareManager::StartMillisecondsTimer();
}

void HardwareManager::PowerConsoleOn()
{
	powerOn(POWER_ALL_2D);
}

void HardwareManager::InitAudio()
{
	mmInitDefaultMem((mm_addr) soundbank_bin);
	mmSelectMode(MM_MODE_A);
	SoundManager::LoadAllSoundsFromSoundbank();
}

void HardwareManager::InitVideo()
{
	HardwareManager::SetVRAM();
	videoSetMode(MODE_5_2D | DISPLAY_BG3_ACTIVE | DISPLAY_BG2_ACTIVE);
	videoSetModeSub(MODE_5_2D | DISPLAY_BG3_ACTIVE);
	oamInit(&oamMain, SpriteMapping_1D_128, false);
	oamInit(&oamSub, SpriteMapping_1D_128, false);
}
void HardwareManager::SetVRAM()
{
	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankB(VRAM_B_MAIN_BG);
	vramSetBankC(VRAM_C_SUB_BG);
	vramSetBankD(VRAM_D_SUB_SPRITE);
	vramSetBankE(VRAM_E_MAIN_SPRITE);
}

void HardwareManager::SetBackgrounds()
{
	HardwareManager::mainBackground3ID = bgInit(3, BgType_Bmp16, BgSize_B16_256x256,
												BackgroundData::BACKGROUND3_MAIN_MAP_BASE, 0);
	HardwareManager::mainBackground2ID = bgInit(2, BgType_Bmp16, BgSize_B16_128x128,
												BackgroundData::BACKGROUND2_MAIN_MAP_BASE, 0);

	HardwareManager::subBackground3ID = bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256,
												  BackgroundData::BACKGROUND3_SUB_MAP_BASE, 0);
}
void HardwareManager::SetPrintConsole()
{
	delete printConsole;
	const bool useMainDisplay = true;
	printConsole = consoleInit(NULL, BackgroundData::FONT_LAYER,
							   BgType_Text4bpp, BgSize_T_256x256,
							   BackgroundData::FONT_MAP_BASE, 0,
							   useMainDisplay, false);
}

void HardwareManager::StartMillisecondsTimer()
{
	cpuStartTiming(1);
}