#include "Scenes/GameOverScene.h"
#include <nds\arm9\input.h>
#include <nds\arm9\sprite.h>
#include <string>
#include<nds.h>
#include<nds\arm9\sprite.h>
#include<nds/memory.h>
#include<nds\arm9\background.h>


#include"GameOverText.h"
#include"PressAnyKeyText.h"
#include "BackgroundGameOver.h"

GameOverScene::GameOverScene(OamEngine* mainEngine, OamEngine* subEngine, GameManager* gameManager) : Scene(mainEngine, subEngine)
{
//	mainEngine->AddSprite("GameOverText", GameOverTextTiles, SpriteSize_64x64);
//	mainEngine->AddPallete(GameOverTextPal, "GameOverText");
	subEngine->AddSprite("PressAnyKeyText", PressAnyKeyTextTiles, SpriteSize_64x64);
	subEngine->AddPallete(PressAnyKeyTextPal, "PressAnyKeyText");

	pressAnyKeyText = new Entity(new Vector2(0, 0), SpriteSize_64x64);
	subEngine->InitEntity(pressAnyKeyText);
	pressAnyKeyText->ChangePalleteTo(subEngine->GetPallete("PressAnyKeyText"));
	pressAnyKeyText->spriteAddress = subEngine->GetSprite("PressAnyKeyText");

	//gameOverText = new Entity(new Vector2(0, 0), SpriteSize_64x64);
	//mainEngine->InitEntity(gameOverText);
//	gameOverText->ChangePalleteTo(subEngine->GetPallete("GameOverText"));
//	gameOverText->spriteAddress = subEngine->GetSprite("GameOverText");

}

void GameOverScene::Load()
{
	Scene::Load();
}

void GameOverScene::InputLoop()
{
	Scene::InputLoop();
	if (keysDown())
		gameManager->Restart();
}
void GameOverScene::GameLoop()
{

	pressAnyKeyText->Render();
	//gameOverText->Render();
	dmaCopyHalfWords(3,
					 BackgroundGameOverBitmap,
					 BG_BMP_RAM(0),
					 BackgroundGameOverBitmapLen);
	dmaCopyHalfWords(3,
					 GameOverTextBitmap,
				BG_BMP_RAM(2),
					 GameOverTextBitmapLen);
}	