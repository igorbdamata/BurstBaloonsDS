#include "Engine.h"
#include "Entity.h"
#include <nds.h>

Engine::Engine()
{

}

void Engine::InitializeVideo()
{
    videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_SPRITE);
	vramSetBankD(VRAM_D_SUB_SPRITE);

    oamInit(&oamMain, SpriteMapping_1D_128, false);
	oamInit(&oamSub, SpriteMapping_1D_128, false);
}

void Engine::UpdateScreens()
{
    swiWaitForVBlank();
	oamUpdate(&oamMain);
	oamUpdate(&oamSub);
}

