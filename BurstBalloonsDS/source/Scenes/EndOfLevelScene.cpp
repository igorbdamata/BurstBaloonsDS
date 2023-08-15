#include "Scenes/EndOfLevelScene.h"
#include "Engine/HardwareManager.h"
#include <nds/arm9/input.h>
#include <nds/arm9/sprite.h>
#include <string>
#include<nds.h>
#include<nds/arm9/sprite.h>

#include"GameOverText0.h"
#include"GameOverText1.h"
#include"GameOverText2.h"
#include"GameOverText3.h"

#include "Engine/SoundManager.h"
#include<soundbank.h>
#include "BackgroundGameOver.h"
#include<math.h>

EndOfLevelScene::EndOfLevelScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager, std::string titleSuffix, int sfxToPlayOnLoad, const void* backgroundTiles, uint32 backgroundTilesLen) : Scene(mainEngine, subEngine)
{
	float textPositionX = SCREEN_WIDTH / 2 - 64 * 2 + 24;
	float textPositionY = SCREEN_HEIGHT / 2;

	Entity* pressAnyKeyText[4] = { new Entity(new Vector2(textPositionX , textPositionY), 64,64, new Vector2(0,0), SpriteSize_64x64),
		new Entity(new Vector2(textPositionX + 64, textPositionY), 64,64, new Vector2(0,0), SpriteSize_64x64),
		new Entity(new Vector2(textPositionX + 64 * 2,textPositionY), 64,64, new Vector2(0,0), SpriteSize_64x64),
		new Entity(new Vector2(textPositionX + 64 * 3, textPositionY), 64,64, new Vector2(0,0), SpriteSize_64x64) };
	for (int i = 0; i < 4; i++)
	{
		this->pressAnyKeyText[i] = pressAnyKeyText[i];
		subEngine->InitEntity(this->pressAnyKeyText[i]);
		this->pressAnyKeyText[i]->SetPaletteTo(subEngine->GetPalette("PressAnyKeyText"));
		this->pressAnyKeyText[i]->SetSpriteTo(subEngine->GetSprite("PressAnyKeyText" + std::to_string(i)));
	}

	Entity* gameOverText[4] = { new Entity(new Vector2(textPositionX, textPositionY),64,64, new Vector2(0,0), SpriteSize_64x64),
		new Entity(new Vector2(textPositionX + 64, textPositionY),64,64, new Vector2(0,0), SpriteSize_64x64),
		new Entity(new Vector2(textPositionX + 64 * 2, textPositionY),64,64, new Vector2(0,0), SpriteSize_64x64),
		new Entity(new Vector2(textPositionX + 64 * 3, textPositionY),64,64, new Vector2(0,0), SpriteSize_64x64) };
	for (int i = 0; i < 4; i++)
	{
		this->titleText[i] = gameOverText[i];
		mainEngine->InitEntity(this->titleText[i]);
		this->titleText[i]->SetPaletteTo(mainEngine->GetPalette(titleSuffix));
		this->titleText[i]->SetSpriteTo(mainEngine->GetSprite(titleSuffix + std::to_string(i)));

	}

	this->sceneManager = sceneManager;
	this->sfxToPlayOnLoad = sfxToPlayOnLoad;

	SetMainBackgroundTo(backgroundTiles, backgroundTilesLen);
	SetSubBackgroundTo(backgroundTiles, backgroundTilesLen);
}

void EndOfLevelScene::Load()
{
	Scene::Load();
	SoundManager::PlaySFX(sfxToPlayOnLoad);
	SoundManager::StopCurrentSong();
}

void EndOfLevelScene::InputLoop()
{
	Scene::InputLoop();

	if (keysDown())
		sceneManager->ChangeSceneTo("Gameplay");
}
void EndOfLevelScene::GameLoop()
{
	for (int i = 0; i < 4; i++)
	{
		this->titleText[i]->position->y = sin(HardwareManager::GetCurrentMilliseconds() / 930) * 15 + SCREEN_HEIGHT / 2 - 64 / 2;
		this->titleText[i]->Render();

		this->pressAnyKeyText[i]->position->y = sin(HardwareManager::GetCurrentMilliseconds() / 930) * 15 + SCREEN_HEIGHT / 2;
		pressAnyKeyText[i]->Render();
	}
}