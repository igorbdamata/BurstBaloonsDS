#include "Engine/HardwareManager.h"
#include <nds.h>
#include <maxmod9.h>
#include <soundbank.h>
#include <soundbank_bin.h>

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
    mmInitDefaultMem((mm_addr)soundbank_bin);
}

void HardwareManager::InitVideo()
{
    HardwareManager::SetVRAM();
    videoSetMode(MODE_5_2D | DISPLAY_BG3_ACTIVE);
    videoSetModeSub(MODE_5_2D | DISPLAY_BG3_ACTIVE);
    oamInit(&oamMain, SpriteMapping_1D_128, false);
    oamInit(&oamSub, SpriteMapping_1D_128, false);
}
void HardwareManager::SetVRAM()
{
    vramSetMainBanks(VRAM_A_MAIN_BG, VRAM_B_MAIN_SPRITE, VRAM_C_SUB_BG, VRAM_D_SUB_SPRITE);
}

void HardwareManager::SetBackgrounds()
{
    bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 1, 0);
    bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 1, 0);
}

void HardwareManager::StartMillisecondsTimer()
{
    cpuStartTiming(1);
}