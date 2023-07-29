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
	pressAnyKeyInitialPosition = new Vector2(pressAnyKeyTextPositionX, pressAnyKeyTextPositionY * 2);
	pressAnyKeyFinalPosition = new Vector2(pressAnyKeyTextPositionX, pressAnyKeyTextPositionY);

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
	
	#pragma region SplashScreenInit
	splashScreenWasFinished = false;

	std::vector<void*> splashScreenFrames;
	splashScreenFrames.insert(splashScreenFrames.end(), (void*) BackgroundAnimation3Bitmap);
	splashScreenFrames.insert(splashScreenFrames.end(), (void*) BackgroundAnimation4Bitmap);
	splashScreenFrames.insert(splashScreenFrames.end(), (void*) BackgroundAnimation5Bitmap);
	splashScreenFrames.insert(splashScreenFrames.end(), (void*) BackgroundAnimation6Bitmap);
	splashScreenFrames.insert(splashScreenFrames.end(), (void*) BackgroundAnimation7Bitmap);
	splashScreenFadeOutAnimation = new Animation(0.3f, 5, [](void* newSprite) { dmaCopyHalfWords(3, newSprite, BG_BMP_RAM(1), Background1BitmapLen); }, false, splashScreenFrames);
	splashScreenFadeOutAnimation->Start();
	splashScreenSeconds = 3;
	startedSplashScreenFadeOut = false;
	#pragma endregion
}

void TitleScreenScene::Load()
{
	Scene::Load();
	SoundManager::PlaySong(MOD_THEME);
	splashScreenStartTime = HardwareManager::GetCurrentSeconds();
}

void TitleScreenScene::InputLoop()
{
	if (!splashScreenWasFinished) return;

	Scene::InputLoop();
	if (keysDown())
		sceneManager->ChangeSceneTo("Gameplay");
}
void TitleScreenScene::GameLoop()
{
	if (!splashScreenWasFinished)
	{
		UpdateSplashScreen();
		return;
	}

	UpdatePressAnyKey();
	UpdateBurstBalloonsText();
}
void TitleScreenScene::UpdatePressAnyKey()
{
	for (int i = 0; i < 4; i++)
	{
		this->pressAnyKeyText[i]->position->y += sin(HardwareManager::GetCurrentMilliseconds() / 930) / 2;
		pressAnyKeyText[i]->Render();
	}
}
void TitleScreenScene::UpdateBurstBalloonsText()
{
	for (int i = 0; i < 2; i++)
	{
		this->burstBalloonsText[i]->position->y += sin((HardwareManager::GetCurrentMilliseconds()) / 930) / 2;
		burstBalloonsText[i]->Render();
	}
}

void TitleScreenScene::UpdateSplashScreen()
{
	bool isTimeToStartFadeOut = HardwareManager::GetCurrentSeconds() - splashScreenStartTime >= splashScreenSeconds;
	if (!isTimeToStartFadeOut) return;
	UpdateFadeOut();
	if (splashScreenFadeOutAnimation->FinishedExecution())FinishSplashScreenAnimation();
}

void TitleScreenScene::UpdateFadeOut()
{
	if (!startedSplashScreenFadeOut) StartFadeOut();
	splashScreenFadeOutAnimation->Update();
	LerpPressAnyKeyText();
}

void TitleScreenScene::StartFadeOut()
{
	splashScreenFadeOutStartSeconds = HardwareManager::GetCurrentSeconds();
	splashScreenFadeOutAnimation->Start();
	startedSplashScreenFadeOut = true;
}

void TitleScreenScene::LerpPressAnyKeyText()
{
	for (int i = 0; i < 4; i++)
	{
		float timeSinceFadeOutStarted = HardwareManager::GetCurrentSeconds() - splashScreenFadeOutStartSeconds;
		float fadeOutTotalTime = 0.3f * 5;
		float fadeOutPercent = timeSinceFadeOutStarted / fadeOutTotalTime;
		this->pressAnyKeyText[i]->position->Lerp(pressAnyKeyInitialPosition, pressAnyKeyFinalPosition, fadeOutPercent);
		this->pressAnyKeyText[i]->position->x += 64 * i;
		pressAnyKeyText[i]->Render();
	}
}

void TitleScreenScene::FinishSplashScreenAnimation()
{
	splashScreenWasFinished = true;
	dmaCopyHalfWords(3, Background1Bitmap, BG_BMP_RAM(1), Background1BitmapLen);
}