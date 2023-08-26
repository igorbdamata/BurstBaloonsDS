#include <soundbank.h>

#include "Scenes/EndOfLevelScene.h"

#include "Engine/SoundManager.h"
#include "Data/PressAnyKeyTextData.h"

#include <nds/arm9/input.h>

EndOfLevelScene::EndOfLevelScene(GraphicsHandler* topGraphicsHandler, GraphicsHandler* bottomGraphicsHandler, SceneManager* sceneManager, int sfxToPlayOnLoad, std::string titlePrefix, const void* backgroundTiles, uint32 backgroundTilesLen, Vector2* titleCenteredPosition, const void* titleTiles[GeneralTitleData::TITLES_COUNT]) : Scene(topGraphicsHandler, bottomGraphicsHandler)
{
	#pragma region InitPressAnyKeyText
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

	#pragma region InitTitleText
	std::vector<Entity*> titleText;
	for (int i = 0; i < GeneralTitleData::TITLES_COUNT; i++)
	{
		std::string currentTileName = titlePrefix + std::to_string(i);
		topGraphicsHandler->AddSprite(currentTileName, titleTiles[i], SpriteSize_64x64);

		Vector2* position = new Vector2(titleCenteredPosition->x + GeneralTitleData::TILE_WIDTH * i, titleCenteredPosition->y);
		Entity* entity = new Entity(position, GeneralTitleData::TILE_WIDTH, GeneralTitleData::TILE_HEIGHT,
									new Vector2(GeneralTitleData::OFFSET_X, GeneralTitleData::OFFSET_Y),
									GeneralTitleData::SPRITE_SIZE);

		topGraphicsHandler->InitEntity(entity);
		entity->SetPaletteTo(topGraphicsHandler->GetPalette("text"));
		entity->SetSpriteTo(topGraphicsHandler->GetSprite(currentTileName));
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
		sceneManager->ChangeSceneTo("gameplay");
}

void EndOfLevelScene::GameLoop()
{
	idleCodedAnimation->Update();
}