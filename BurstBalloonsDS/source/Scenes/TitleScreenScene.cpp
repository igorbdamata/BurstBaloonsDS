#include<soundbank.h>
#include<nds/arm9/sprite.h>
#include<nds.h>
#include<string>

#include "Scenes/TitleScreenScene.h"
#include "Engine/HardwareManager.h"
#include "Engine/SoundManager.h"

#include "Data/BurstBalloonsTextData.h"
#include "BurstBalloonsText0.h";
#include "BurstBalloonsText1.h";

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
		subEngine->InitEntity(pressAnyKeyText[i]);
		pressAnyKeyText[i]->ChangePalleteTo(subEngine->GetPallete("PressAnyKeyText"));
	}

	pressAnyKeyText[0]->spriteAddress = subEngine->GetSprite("PressAnyKeyText0");
	pressAnyKeyText[1]->spriteAddress = subEngine->GetSprite("PressAnyKeyText1");
	pressAnyKeyText[2]->spriteAddress = subEngine->GetSprite("PressAnyKeyText2");
	pressAnyKeyText[3]->spriteAddress = subEngine->GetSprite("PressAnyKeyText3");
	#pragma endregion

	#pragma region BurstBalloonsTextInit
	float burstBalloonsTextPositionX = SCREEN_WIDTH / 2 - 53;
	float burstBalloonsTextPositionY = SCREEN_HEIGHT / 2 - 21;
	Entity* burstBalloonsText[2] =
	{
		new Entity(new Vector2(burstBalloonsTextPositionX , burstBalloonsTextPositionY), SpriteSize_64x64,64,64),
		new Entity(new Vector2(burstBalloonsTextPositionX + 64, burstBalloonsTextPositionY), SpriteSize_64x64,64,64)
	};

	mainEngine->AddPallete(BurstBalloonsText0Pal, "BurstBalloonsText");
	mainEngine->AddSprite("BurstBalloonsText0", BurstBalloonsText0Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("BurstBalloonsText1", BurstBalloonsText1Tiles, SpriteSize_64x64);

	for (int i = 0; i < BurstBalloonsText::tilesCount; i++)
	{
		mainEngine->InitEntity(burstBalloonsText[i]);
		burstBalloonsText[i]->ChangePalleteTo(mainEngine->GetPallete("BurstBalloonsText"));
		std::string spriteName = "BurstBalloonsText" + std::to_string(i);
		burstBalloonsText[i]->spriteAddress = mainEngine->GetSprite(spriteName);
	}

	#pragma endregion

	splashScreenCodedAnimation = new SplashScreenCodedAnimation(pressAnyKeyText);
	titleScreenIdleCodedAnimation = new TitleScreenIdleCodedAnimation(pressAnyKeyText, burstBalloonsText);
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
	else if (!titleScreenIdleCodedAnimation->IsPlaying())
		titleScreenIdleCodedAnimation->Start();

	titleScreenIdleCodedAnimation->Update();
}