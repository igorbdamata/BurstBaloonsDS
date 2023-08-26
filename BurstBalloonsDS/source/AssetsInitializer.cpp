#include<soundbank.h>

#include "AssetsInitializer.h"

#include "Engine/GraphicsHandler.h"
#include "Engine/HardwareManager.h"

#include "GameManager.h"

#include "Scenes/SceneManager.h"
#include "Scenes/TitleScreenScene.h"
#include "Scenes/GameplayScene.h"
#include "Scenes/EndOfLevelScene.h"

#include"Data/PressAnyKeyTextData.h"
#include"PressAnyKeyText0.h"
#include"PressAnyKeyText1.h"
#include"PressAnyKeyText2.h"
#include"PressAnyKeyText3.h"

#include"BackgroundPassRecord.h"
#include"BackgroundGameOver.h"

#include"Data/NewRecordTitleData.h"
#include"Data/GameOverTitleData.h"

#include"font.h"

AssetsInitializer::AssetsInitializer(GraphicsHandler* topGraphicsHandler, GraphicsHandler* bottomGraphicsHandler, SceneManager* sceneManager, GameManager* gameManager)
{
	this->topGraphicsHandler = topGraphicsHandler;
	this->bottomGraphicsHandler = bottomGraphicsHandler;
	this->sceneManager = sceneManager;
	this->gameManager = gameManager;
}

void AssetsInitializer::InitializeScenes()
{
	TitleScreenScene* titleScreenScene = new TitleScreenScene(topGraphicsHandler, bottomGraphicsHandler, sceneManager);
	GameplayScene* gameplayScene = new GameplayScene(topGraphicsHandler, bottomGraphicsHandler, gameManager);

	EndOfLevelScene* newRecordScene = new EndOfLevelScene(
		topGraphicsHandler,
		bottomGraphicsHandler,
		sceneManager,
		SFX_PASSRECORD,
		"newRecordText",
		BackgroundPassRecordBitmap,
		BackgroundPassRecordBitmapLen,
		NewRecordTitleData::GetCenteredPosition(),
		NewRecordTitleData::TILES);

	EndOfLevelScene* gameOverScene = new EndOfLevelScene(
		topGraphicsHandler,
		bottomGraphicsHandler,
		sceneManager,
		SFX_GAMEOVER,
		"gameOverText",
		BackgroundGameOverBitmap,
		BackgroundGameOverBitmapLen,
		GameOverTitleData::GetCenteredPosition(),
		GameOverTitleData::TILES);

	sceneManager->AddScene("titleScreen", titleScreenScene);
	sceneManager->AddScene("gameplay", gameplayScene);
	sceneManager->AddScene("newRecord", newRecordScene);
	sceneManager->AddScene("gameOver", gameOverScene);
}

void AssetsInitializer::InitializeGlobalGraphics()
{
	topGraphicsHandler->AddPalette(PressAnyKeyText0Pal, "text");
	bottomGraphicsHandler->AddPalette(PressAnyKeyText0Pal, "text");
	topGraphicsHandler->SetTextFontTo((void*) fontTiles, (void*) fontPal, fontPalLen);

	InitPressAnyKeyText();
}

void AssetsInitializer::InitPressAnyKeyText()
{
	bottomGraphicsHandler->AddSprite("pressAnyKeyText0", PressAnyKeyText0Tiles, PressAnyKeyTextData::SPRITE_SIZE);
	bottomGraphicsHandler->AddSprite("pressAnyKeyText1", PressAnyKeyText1Tiles, PressAnyKeyTextData::SPRITE_SIZE);
	bottomGraphicsHandler->AddSprite("pressAnyKeyText2", PressAnyKeyText2Tiles, PressAnyKeyTextData::SPRITE_SIZE);
	bottomGraphicsHandler->AddSprite("pressAnyKeyText3", PressAnyKeyText3Tiles, PressAnyKeyTextData::SPRITE_SIZE);
}