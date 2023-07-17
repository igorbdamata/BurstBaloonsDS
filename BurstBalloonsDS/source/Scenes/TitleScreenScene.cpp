#include "Scenes/TitleScreenScene.h"
#include "Engine/HardwareManager.h"
#include <nds\arm9\input.h>
#include <nds\arm9\sprite.h>
#include <string>
#include<nds.h>
#include<nds\arm9\sprite.h>
#include<nds/memory.h>
#include<nds\arm9\background.h>

#include<math.h>

#include "BurstBalloonsText0.h";
#include "BurstBalloonsText1.h";
#include "BackgroundGameOver.h";
#include "Background1.h";

TitleScreenScene::TitleScreenScene(OamEngine* mainEngine, OamEngine* subEngine, SceneManager* sceneManager) : Scene(mainEngine, subEngine)
{
	this->sceneManager = sceneManager;

	float pressAnyKeyTextPositionX = SCREEN_WIDTH / 2 - 64 * 2 + 24;
	float pressAnyKeyTextPositionY = SCREEN_HEIGHT / 2;



	Entity* pressAnyKeyText[4] = { new Entity(new Vector2(pressAnyKeyTextPositionX , pressAnyKeyTextPositionY), SpriteSize_64x64,64,64),
		new Entity(new Vector2(pressAnyKeyTextPositionX + 64, pressAnyKeyTextPositionY), SpriteSize_64x64,64,64),
		new Entity(new Vector2(pressAnyKeyTextPositionX + 64 * 2,pressAnyKeyTextPositionY), SpriteSize_64x64,64,64),
		new Entity(new Vector2(pressAnyKeyTextPositionX + 64 * 3, pressAnyKeyTextPositionY), SpriteSize_64x64,64,64) };


	for (int i = 0; i < 4; i++)
	{
		this->pressAnyKeyText[i] = pressAnyKeyText[i];
		subEngine->InitEntity(this->pressAnyKeyText[i]);
		this->pressAnyKeyText[i]->ChangePalleteTo(subEngine->GetPallete("PressAnyKeyText"));
	}

	this->pressAnyKeyText[0]->spriteAddress = subEngine->GetSprite("PressAnyKeyText0");
	this->pressAnyKeyText[1]->spriteAddress = subEngine->GetSprite("PressAnyKeyText1");
	this->pressAnyKeyText[2]->spriteAddress = subEngine->GetSprite("PressAnyKeyText2");
	this->pressAnyKeyText[3]->spriteAddress = subEngine->GetSprite("PressAnyKeyText3");


	float burstBalloonsTextPositionX = SCREEN_WIDTH / 2 - 50;
	float burstBalloonsTextPositionY = SCREEN_HEIGHT / 2;
	Entity* burstBalloonsText[2] = { new Entity(new Vector2(burstBalloonsTextPositionX , burstBalloonsTextPositionY), SpriteSize_64x64,64,64),
		new Entity(new Vector2(burstBalloonsTextPositionX + 64, burstBalloonsTextPositionY), SpriteSize_64x64,64,64) };
	mainEngine->AddPallete(BurstBalloonsText0Pal, "BurstBalloonsText");
	mainEngine->AddSprite("BurstBalloonsText0", BurstBalloonsText0Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("BurstBalloonsText1", BurstBalloonsText1Tiles, SpriteSize_64x64);
	for (int i = 0; i < 2; i++)
	{
		this->burstBalloonsText[i] = burstBalloonsText[i];
		mainEngine->InitEntity(this->burstBalloonsText[i]);
		this->burstBalloonsText[i]->ChangePalleteTo(mainEngine->GetPallete("BurstBalloonsText"));
	}

	this->burstBalloonsText[0]->spriteAddress = mainEngine->GetSprite("BurstBalloonsText0");
	this->burstBalloonsText[1]->spriteAddress = mainEngine->GetSprite("BurstBalloonsText1");

}

void TitleScreenScene::Load()
{
	Scene::Load();
	dmaCopyHalfWords(2,
					 BackgroundGameOverBitmap,
					 BG_BMP_RAM(0),
					 BackgroundGameOverBitmapLen);
	dmaCopyHalfWords(3,
					 Background1Bitmap,
					 BG_BMP_RAM(7),
					 Background1BitmapLen);
}

void TitleScreenScene::InputLoop()
{
	Scene::InputLoop();
	int x = 0;
	int y = 0;
	//if (keysDown())
		//sceneManager->ChangeSceneTo("Gameplay");

	scanKeys();
	if (keysHeld() & KEY_LEFT)
		x = -1;
	if (keysHeld() & KEY_RIGHT)
		x = 1;
	if (keysHeld() & KEY_UP)
		y = -1;
	if (keysHeld() & KEY_DOWN)
		y = 1;
	bgScroll(2, -x, -y);
	bgUpdate();

}
void TitleScreenScene::GameLoop()
{
	for (int i = 0; i < 4; i++)
	{
		this->pressAnyKeyText[i]->position->y = sin(HardwareManager::GetCurrentMilliseconds() / 930) * 15 + SCREEN_HEIGHT / 2;
		pressAnyKeyText[i]->Render();
	}
	for (int i = 0; i < 2; i++)
	{
		this->burstBalloonsText[i]->position->y = sin(HardwareManager::GetCurrentMilliseconds() / 930) * 15 + SCREEN_HEIGHT / 2;
		burstBalloonsText[i]->Render();
	}


}