#include "Scenes/TitleScreenScene.h"
#include "Engine/HardwareManager.h"
#include "Engine/SoundManager.h"
#include<soundbank.h>
#include<nds/arm9/input.h>
#include<nds/arm9/sprite.h>
#include<string>
#include<nds.h>
#include<nds/arm9/sprite.h>
#include<nds/memory.h>
#include<nds/arm9/background.h>

#include<math.h>

#include "BurstBalloonsTextT0.h";
#include "BurstBalloonsTextT1.h";

#include "BackgroundGameOver.h";
#include "LogotipoLudosAurum.h";
#include "BackgroundPassRecord.h";
#include "Background1.h";
#include "BackgroundAnimation2.h";
#include "BackgroundAnimation3.h";
#include "BackgroundAnimation4.h";
#include "BackgroundAnimation5.h";
#include "BackgroundAnimation6.h";
#include "BackgroundAnimation7.h";

TitleScreenScene::TitleScreenScene(OamEngine* mainEngine, OamEngine* subEngine, SceneManager* sceneManager) : Scene(mainEngine, subEngine)
{
	this->sceneManager = sceneManager;

	#pragma region PressAnyKeyTextInit
	float pressAnyKeyTextPositionX = SCREEN_WIDTH / 2 - 64 * 2 + 24;
	float pressAnyKeyTextPositionY = SCREEN_HEIGHT / 2 + 80;

	Entity* pressAnyKeyText[4] =
	{
		new Entity(new Vector2(pressAnyKeyTextPositionX , pressAnyKeyTextPositionY), SpriteSize_64x64,64,64),
		new Entity(new Vector2(pressAnyKeyTextPositionX + 64, pressAnyKeyTextPositionY), SpriteSize_64x64,64,64),
		new Entity(new Vector2(pressAnyKeyTextPositionX + 64 * 2,pressAnyKeyTextPositionY), SpriteSize_64x64,64,64),
		new Entity(new Vector2(pressAnyKeyTextPositionX + 64 * 3, pressAnyKeyTextPositionY), SpriteSize_64x64,64,64)
	};

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
	#pragma endregion

	#pragma region BurstBalloonsTextInit
	float burstBalloonsTextPositionX = SCREEN_WIDTH / 2 - 53;
	float burstBalloonsTextPositionY = SCREEN_HEIGHT / 2 - 21;
	Entity* burstBalloonsText[2] =
	{
		new Entity(new Vector2(burstBalloonsTextPositionX , burstBalloonsTextPositionY), SpriteSize_64x64,64,64),
		new Entity(new Vector2(burstBalloonsTextPositionX + 64, burstBalloonsTextPositionY), SpriteSize_64x64,64,64)
	};

	mainEngine->AddPallete(BurstBalloonsTextT0Pal, "BurstBalloonsText");
	mainEngine->AddSprite("BurstBalloonsTextT0", BurstBalloonsTextT0Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("BurstBalloonsTextT1", BurstBalloonsTextT1Tiles, SpriteSize_64x64);

	for (int i = 0; i < 2; i++)
	{
		this->burstBalloonsText[i] = burstBalloonsText[i];
		mainEngine->InitEntity(this->burstBalloonsText[i]);
		this->burstBalloonsText[i]->ChangePalleteTo(mainEngine->GetPallete("BurstBalloonsText"));
	}

	this->burstBalloonsText[0]->spriteAddress = mainEngine->GetSprite("BurstBalloonsTextT0");
	this->burstBalloonsText[1]->spriteAddress = mainEngine->GetSprite("BurstBalloonsTextT1");
	#pragma endregion

	splashScreenCodedAnimation = new SplashScreenCodedAnimation(this->pressAnyKeyText);
	titleScreenIdleCodedAnimation = new TitleScreenIdleCodedAnimation(this->pressAnyKeyText, this->burstBalloonsText);
}

void TitleScreenScene::Load()
{
	Scene::Load();
	SoundManager::PlaySong(MOD_THEME);
	splashScreenCodedAnimation->Start();
}

void TitleScreenScene::InputLoop()
{
	if (!splashScreenCodedAnimation->HaveFinished()) return;

	Scene::InputLoop();
	if (keysDown())
		sceneManager->ChangeSceneTo("Gameplay");
}
void TitleScreenScene::GameLoop()
{
	if (!splashScreenCodedAnimation->HaveFinished())
	{
		splashScreenCodedAnimation->Update();
		return;
	}
	titleScreenIdleCodedAnimation->Update();
}
