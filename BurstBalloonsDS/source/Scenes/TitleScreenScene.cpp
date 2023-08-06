#include<string>
#include<nds.h>
#include<nds/arm9/sprite.h>
#include<nds/arm9/input.h>
#include<soundbank.h>

#include "Scenes/TitleScreenScene.h"
#include "Engine/HardwareManager.h"
#include "Engine/SoundManager.h"

#include "Data/BurstBalloonsTextData.h"
#include "BurstBalloonsText0.h"

#include "Data/PressAnyKeyTextData.h"

#include "BackgroundAnimation2.h"
#include "Background.h"

TitleScreenScene::TitleScreenScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager) : Scene(mainEngine, subEngine)
{
	this->sceneManager = sceneManager;

	SetMainBackgroundTo(BackgroundAnimation2Bitmap, BackgroundAnimation2BitmapLen);
	SetSubBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

	#pragma region PressAnyKeyTextInit
	Entity* pressAnyKeyText[4] =
	{
		new Entity(PressAnyKeyTextData::GetCenteredPositionForTile(0), 64,64, new Vector2(0,0), SpriteSize_64x64),
		new Entity(PressAnyKeyTextData::GetCenteredPositionForTile(1), 64,64, new Vector2(0,0), SpriteSize_64x64),
		new Entity(PressAnyKeyTextData::GetCenteredPositionForTile(2), 64,64, new Vector2(0,0), SpriteSize_64x64),
		new Entity(PressAnyKeyTextData::GetCenteredPositionForTile(3), 64,64, new Vector2(0,0), SpriteSize_64x64)
	};

	for (int i = 0; i < PressAnyKeyTextData::TILES_LENGTH; i++)
	{
		subEngine->InitEntity(pressAnyKeyText[i]);
		pressAnyKeyText[i]->SetPaletteTo(subEngine->GetPalette(PressAnyKeyTextData::GetName().c_str()));
		pressAnyKeyText[i]->SetSpriteTo(subEngine->GetSprite(PressAnyKeyTextData::GetName() + std::to_string(i)));
	}
	#pragma endregion

	#pragma region BurstBalloonsTextInit
	Entity* burstBalloonsText[2] =
	{
		new Entity(BurstBalloonsTextData::GetCenteredPositionForTile(0), 64,64, new Vector2(0,0), SpriteSize_64x64),
		new Entity(BurstBalloonsTextData::GetCenteredPositionForTile(1), 64,64, new Vector2(0,0), SpriteSize_64x64)
	};


	mainEngine->AddPalette(BurstBalloonsText0Pal, BurstBalloonsTextData::GetName().c_str());

	for (int i = 0; i < BurstBalloonsTextData::TILES_LENGTH; i++)
	{
		std::string spriteName = BurstBalloonsTextData::GetName() + std::to_string(i);

		mainEngine->AddSprite(spriteName, BurstBalloonsTextData::GetTile(i), SpriteSize_64x64);
		mainEngine->InitEntity(burstBalloonsText[i]);

		burstBalloonsText[i]->SetPaletteTo(mainEngine->GetPalette(BurstBalloonsTextData::GetName().c_str()));
		burstBalloonsText[i]->SetSpriteTo(mainEngine->GetSprite(spriteName));
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