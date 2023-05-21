#include "Scenes/GameOverScene.h"
#include "Engine/HardwareManager.h"
#include <nds\arm9\input.h>
#include <nds\arm9\sprite.h>
#include <string>
#include<nds.h>
#include<nds\arm9\sprite.h>
#include<nds/memory.h>
#include<nds\arm9\background.h>


#include"GameOverText0.h"
#include"GameOverText1.h"
#include"GameOverText2.h"
#include"GameOverText3.h"
#include"PressAnyKeyText0.h"
#include"PressAnyKeyText1.h"
#include"PressAnyKeyText2.h"
#include"PressAnyKeyText3.h"
#include "BackgroundGameOver.h"
#include<math.h>

GameOverScene::GameOverScene(OamEngine* mainEngine, OamEngine* subEngine, SceneManager* sceneManager) : Scene(mainEngine, subEngine)
{
	mainEngine->AddSprite("GameOverText0", GameOverText0Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("GameOverText1", GameOverText1Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("GameOverText2", GameOverText2Tiles, SpriteSize_64x64);
	mainEngine->AddSprite("GameOverText3", GameOverText3Tiles, SpriteSize_64x64);
	mainEngine->AddPallete(GameOverText0Pal, "GameOverText");

	subEngine->AddSprite("PressAnyKeyText0", PressAnyKeyText0Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText1", PressAnyKeyText1Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText2", PressAnyKeyText2Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText3", PressAnyKeyText3Tiles, SpriteSize_64x64);
	subEngine->AddPallete(PressAnyKeyText0Pal, "PressAnyKeyText");

	float textPositionX = SCREEN_WIDTH / 2-64*2+24;
	float textPositionY = SCREEN_HEIGHT / 2;

	Entity* pressAnyKeyText[4] = { new Entity(new Vector2(textPositionX , textPositionY), SpriteSize_64x64),
								   new Entity(new Vector2(textPositionX + 64, textPositionY), SpriteSize_64x64),
								   new Entity(new Vector2(textPositionX + 64 * 2,textPositionY), SpriteSize_64x64),
								   new Entity(new Vector2(textPositionX + 64 * 3, textPositionY), SpriteSize_64x64) };
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


	Entity* gameOverText[4] = { new Entity(new Vector2(textPositionX, textPositionY), SpriteSize_64x64),
							new Entity(new Vector2(textPositionX + 64, textPositionY), SpriteSize_64x64),
							new Entity(new Vector2(textPositionX + 64 * 2, textPositionY), SpriteSize_64x64),
							new Entity(new Vector2(textPositionX + 64 * 3, textPositionY), SpriteSize_64x64) };
	for (int i = 0; i < 4; i++)
	{
		this->gameOverText[i] = gameOverText[i];
		mainEngine->InitEntity(this->gameOverText[i]);
		this->gameOverText[i]->ChangePalleteTo(mainEngine->GetPallete("GameOverText"));
	}
	this->gameOverText[0]->spriteAddress = mainEngine->GetSprite("GameOverText0");
	this->gameOverText[1]->spriteAddress = mainEngine->GetSprite("GameOverText1");
	this->gameOverText[2]->spriteAddress = mainEngine->GetSprite("GameOverText2");
	this->gameOverText[3]->spriteAddress = mainEngine->GetSprite("GameOverText3");

	this->sceneManager = sceneManager;
}

void GameOverScene::Load()
{
	Scene::Load();
}

void GameOverScene::InputLoop()
{
	Scene::InputLoop();

	if (keysDown())
		sceneManager->ChangeSceneTo("Gameplay");
}
void GameOverScene::GameLoop()
{
	for (int i = 0; i < 4; i++)
	{
		this->gameOverText[i]->position->y = sin(HardwareManager::GetCurrentMilliseconds() / 930) * 15 + SCREEN_HEIGHT / 2 - 64 / 2;
		this->gameOverText[i]->Render();

		this->pressAnyKeyText[i]->position->y = sin(HardwareManager::GetCurrentMilliseconds() / 930) * 15 + SCREEN_HEIGHT / 2;
		pressAnyKeyText[i]->Render();
	}
}