#include "Scenes/EndOfLevelScene.h"
#include <nds/arm9/input.h>

#include "Engine/SoundManager.h"
#include<soundbank.h>
#include "Data/PressAnyKeyTextData.h"
#include "Data/GeneralTitleData.h"

EndOfLevelScene::EndOfLevelScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager, int sfxToPlayOnLoad, std::string titlePrefix, const void* backgroundTiles, uint32 backgroundTilesLen, int titleTilesCount, Vector2* titleCenteredPosition) : Scene(mainEngine, subEngine)
{
	#pragma region InitPressAnyKeyText
	std::vector<Entity*> pressAnyKeyText;
	for (int i = 0; i < PressAnyKeyTextData::TILES_COUNT; i++)
	{
		Entity* entity = new Entity(PressAnyKeyTextData::GetCenteredPositionForTile(i),
									PressAnyKeyTextData::TILE_WIDTH, PressAnyKeyTextData::TILE_HEIGHT,
									new Vector2(PressAnyKeyTextData::OFFSET_X, PressAnyKeyTextData::OFFSET_Y),
									PressAnyKeyTextData::SPRITE_SIZE);
		subEngine->InitEntity(entity);
		entity->SetPaletteTo(subEngine->GetPalette("PressAnyKeyText"));
		entity->SetSpriteTo(subEngine->GetSprite("PressAnyKeyText" + std::to_string(i)));
		pressAnyKeyText.insert(pressAnyKeyText.end(), entity);
	}
	#pragma endregion

	#pragma region InitTitleText
	std::vector<Entity*> titleText;
	for (int i = 0; i < titleTilesCount; i++)
	{
		Vector2* position = new Vector2(titleCenteredPosition->x + GeneralTitleData::TILE_WIDTH * i, titleCenteredPosition->y);
		Entity* entity = new Entity(position, GeneralTitleData::TILE_WIDTH, GeneralTitleData::TILE_HEIGHT,
									new Vector2(GeneralTitleData::OFFSET_X, GeneralTitleData::OFFSET_Y),
									GeneralTitleData::SPRITE_SIZE);

		mainEngine->InitEntity(entity);
		entity->SetPaletteTo(mainEngine->GetPalette(titlePrefix));
		entity->SetSpriteTo(mainEngine->GetSprite(titlePrefix + std::to_string(i)));
		titleText.insert(titleText.end(), entity);
	}
	#pragma endregion

	this->sceneManager = sceneManager;
	this->sfxToPlayOnLoad = sfxToPlayOnLoad;

	SetMainBackgroundTo(backgroundTiles, backgroundTilesLen);
	SetSubBackgroundTo(backgroundTiles, backgroundTilesLen);

	idleCodedAnimation = new MenuIdleCodedAnimation(titleText, pressAnyKeyText);
}

void EndOfLevelScene::Load()
{
	Scene::Load();
	SoundManager::PlaySFX(sfxToPlayOnLoad);
	SoundManager::StopCurrentSong();
	idleCodedAnimation->Start();
}

void EndOfLevelScene::InputLoop()
{
	Scene::InputLoop();

	if (keysDown())
		sceneManager->ChangeSceneTo("Gameplay");
}

void EndOfLevelScene::GameLoop()
{
	idleCodedAnimation->Update();
}