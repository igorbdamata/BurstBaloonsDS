#include "Scenes/EndOfLevelScene.h"
#include "Engine/HardwareManager.h"
#include <nds/arm9/input.h>
#include <nds/arm9/sprite.h>
#include <string>
#include <vector>
#include<nds.h>
#include<nds/arm9/sprite.h>

#include"GameOverText0.h"
#include"GameOverText1.h"
#include"GameOverText2.h"
#include"GameOverText3.h"

#include "Engine/SoundManager.h"
#include<soundbank.h>
#include "BackgroundGameOver.h"
#include "Data/PressAnyKeyTextData.h"
#include "Engine/Math.h"

EndOfLevelScene::EndOfLevelScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager, std::string titleSuffix, int sfxToPlayOnLoad, const void* backgroundTiles, uint32 backgroundTilesLen) : Scene(mainEngine, subEngine)
{
	float textPositionX = SCREEN_WIDTH / 2 - 64 * 2 + 24;
	float textPositionY = SCREEN_HEIGHT / 2;

	std::vector<Entity*> pressAnyKeyText;
	for (int i = 0; i < PressAnyKeyTextData::TILES_LENGTH; i++)
	{
		Entity* entity = new Entity(PressAnyKeyTextData::GetCenteredPositionForTile(i),
									PressAnyKeyTextData::TILE_WIDTH, PressAnyKeyTextData::TILE_HEIGHT,
									new Vector2(0, 0), SpriteSize_64x64);
		subEngine->InitEntity(entity);
		entity->SetPaletteTo(subEngine->GetPalette("PressAnyKeyText"));
		entity->SetSpriteTo(subEngine->GetSprite("PressAnyKeyText" + std::to_string(i)));
		pressAnyKeyText.insert(pressAnyKeyText.end(), entity);
	}

	std::vector<Entity*> titleText;
	for (int i = 0; i < 4; i++)
	{
		Entity* entity = new Entity(new Vector2(textPositionX + 64 * i, textPositionY), 64, 64,
									new Vector2(0, 0), SpriteSize_64x64);

		mainEngine->InitEntity(entity);
		entity->SetPaletteTo(mainEngine->GetPalette(titleSuffix));
		entity->SetSpriteTo(mainEngine->GetSprite(titleSuffix + std::to_string(i)));
		titleText.insert(titleText.end(), entity);
	}

	this->sceneManager = sceneManager;
	this->sfxToPlayOnLoad = sfxToPlayOnLoad;

	SetMainBackgroundTo(backgroundTiles, backgroundTilesLen);
	SetSubBackgroundTo(backgroundTiles, backgroundTilesLen);

	idleCodedAnimation = new MenuIdleCodedAnimation(pressAnyKeyText, titleText);
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