#include<nds.h>
#include<nds/arm9/input.h>
#include<string>
#include<vector>
#include<soundbank.h>

#include "Scenes/TitleScreenScene.h"
#include "Engine/SoundManager.h"

#include "Data/BurstBalloonsTextData.h"
#include "Data/PressAnyKeyTextData.h"

#include "BurstBalloonsText0.h"

#include "BackgroundAnimation2.h"
#include "Background.h"

TitleScreenScene::TitleScreenScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager) : Scene(mainEngine, subEngine)
{
	this->sceneManager = sceneManager;

	SetMainBackgroundTo(BackgroundAnimation2Bitmap, BackgroundAnimation2BitmapLen);
	SetSubBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

	#pragma region PressAnyKeyTextInit
	std::vector<Entity*> pressAnyKeyText;
	for (int i = 0; i < PressAnyKeyTextData::TILES_LENGTH; i++)
	{
		Entity* entity = new Entity(PressAnyKeyTextData::GetCenteredPositionForTile(i),
									PressAnyKeyTextData::TILE_WIDTH, PressAnyKeyTextData::TILE_HEIGHT,
									new Vector2(PressAnyKeyTextData::OFFSET_X, PressAnyKeyTextData::OFFSET_Y), 
									PressAnyKeyTextData::SPRITE_SIZE);

		subEngine->InitEntity(entity);
		entity->SetPaletteTo(subEngine->GetPalette(PressAnyKeyTextData::GetName()));
		entity->SetSpriteTo(subEngine->GetSprite(PressAnyKeyTextData::GetName() + std::to_string(i)));

		pressAnyKeyText.insert(pressAnyKeyText.end(), entity);
	}
	#pragma endregion

	#pragma region BurstBalloonsTextInit
	mainEngine->AddPalette(BurstBalloonsText0Pal, BurstBalloonsTextData::GetName());

	std::vector<Entity*> burstBalloonsText;
	for (int i = 0; i < BurstBalloonsTextData::TILES_LENGTH; i++)
	{
		Entity* entity = new Entity(BurstBalloonsTextData::GetCenteredPositionForTile(i),
									BurstBalloonsTextData::TILE_WIDTH, BurstBalloonsTextData::TILE_HEIGHT,
									new Vector2(0, 0), SpriteSize_64x64);
		std::string spriteName = BurstBalloonsTextData::GetName() + std::to_string(i);
		mainEngine->AddSprite(spriteName, BurstBalloonsTextData::GetTile(i), SpriteSize_64x64);

		mainEngine->InitEntity(entity);
		entity->SetPaletteTo(mainEngine->GetPalette(BurstBalloonsTextData::GetName()));
		entity->SetSpriteTo(mainEngine->GetSprite(spriteName));

		burstBalloonsText.insert(burstBalloonsText.end(), entity);
	}

	#pragma endregion

	splashScreenCodedAnimation = new SplashScreenCodedAnimation(pressAnyKeyText, mainEngine, subEngine);
	idleCodedAnimation = new MenuIdleCodedAnimation(pressAnyKeyText, burstBalloonsText);
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

	if (!idleCodedAnimation->IsPlaying())
		idleCodedAnimation->Start();
	idleCodedAnimation->Update();
}