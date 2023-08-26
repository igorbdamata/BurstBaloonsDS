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

TitleScreenScene::TitleScreenScene(GraphicsHandler* topGraphicsHandler, GraphicsHandler* bottomGraphicsHandler, SceneManager* sceneManager) : Scene(topGraphicsHandler, bottomGraphicsHandler)
{
	this->sceneManager = sceneManager;

	SetMainBackgroundTo(BackgroundAnimation2Bitmap, BackgroundAnimation2BitmapLen);
	SetSubBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

	#pragma region PressAnyKeyTextInit
	std::vector<Entity*> pressAnyKeyText;
	for (int i = 0; i < PressAnyKeyTextData::TILES_COUNT; i++)
	{
		Entity* entity = new Entity(PressAnyKeyTextData::GetCenteredPositionForTile(i),
									PressAnyKeyTextData::TILE_WIDTH, PressAnyKeyTextData::TILE_HEIGHT,
									new Vector2(PressAnyKeyTextData::OFFSET_X, PressAnyKeyTextData::OFFSET_Y), 
									PressAnyKeyTextData::SPRITE_SIZE);

		bottomGraphicsHandler->InitEntity(entity);
		entity->SetPaletteTo(bottomGraphicsHandler->GetPalette("text"));
		entity->SetSpriteTo(bottomGraphicsHandler->GetSprite(PressAnyKeyTextData::GetName() + std::to_string(i)));

		pressAnyKeyText.insert(pressAnyKeyText.end(), entity);
	}
	#pragma endregion

	#pragma region BurstBalloonsTextInit
	topGraphicsHandler->AddPalette(BurstBalloonsText0Pal, BurstBalloonsTextData::GetName());

	std::vector<Entity*> burstBalloonsText;
	for (int i = 0; i < BurstBalloonsTextData::TILES_COUNT; i++)
	{
		Entity* entity = new Entity(BurstBalloonsTextData::GetCenteredPositionForTile(i),
									BurstBalloonsTextData::TILE_WIDTH, BurstBalloonsTextData::TILE_HEIGHT,
									new Vector2(BurstBalloonsTextData::OFFSET_X, BurstBalloonsTextData::OFFSET_Y), 
									BurstBalloonsTextData::SPRITE_SIZE);
		std::string spriteName = BurstBalloonsTextData::GetName() + std::to_string(i);
		topGraphicsHandler->AddSprite(spriteName, BurstBalloonsTextData::GetTile(i), SpriteSize_64x64);

		topGraphicsHandler->InitEntity(entity);
		entity->SetPaletteTo(topGraphicsHandler->GetPalette(BurstBalloonsTextData::GetName()));
		entity->SetSpriteTo(topGraphicsHandler->GetSprite(spriteName));

		burstBalloonsText.insert(burstBalloonsText.end(), entity);
	}

	#pragma endregion

	splashScreenCodedAnimation = new SplashScreenCodedAnimation(pressAnyKeyText, topGraphicsHandler, bottomGraphicsHandler);
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
		sceneManager->ChangeSceneTo("gameplay");
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