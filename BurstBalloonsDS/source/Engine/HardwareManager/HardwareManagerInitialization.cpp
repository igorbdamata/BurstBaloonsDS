#include "Engine/HardwareManager.h"
#include <nds.h>
#include <nds\arm9\sprite.h>
#include <maxmod9.h>
#include <soundbank.h>
#include <soundbank_bin.h>
#include<nds\arm9\background.h>

int HardwareManager::background2SubID = -1;
int HardwareManager::background3SubID = -1;
int HardwareManager::background2MainID = -1;
int HardwareManager::background3MainID = -1;

void HardwareManager::InitAndSetEverything()
{
	HardwareManager::PowerOnConsole();
	HardwareManager::InitVideo();
	HardwareManager::InitAudio();
	HardwareManager::SetBackgrounds();
	HardwareManager::StartMillisecondsTimer();
}

void HardwareManager::PowerOnConsole()
{
	powerOn(POWER_ALL_2D);
}

void HardwareManager::InitAudio()
{
	mmInitDefaultMem((mm_addr) soundbank_bin);
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
	vramSetMainBanks(VRAM_A_MAIN_BG, VRAM_B_MAIN_BG, VRAM_C_SUB_BG, VRAM_D_SUB_SPRITE);
	vramSetBankE(VRAM_E_MAIN_SPRITE);
}

void HardwareManager::SetBackgrounds()
{
	HardwareManager::background3MainID = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 1, 0);
	HardwareManager::background2MainID = bgInit(2, BgType_Bmp16, BgSize_B16_256x256, 8, 0);
	HardwareManager::background3SubID = bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
}

void HardwareManager::StartMillisecondsTimer()
{
	cpuStartTiming(1);
}