#include "AssetsInitializer.h"

#include<soundbank.h>

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

AssetsInitializer::AssetsInitializer(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager, GameManager* gameManager)
{
	this->mainEngine = mainEngine;
	this->subEngine = subEngine;
	this->sceneManager = sceneManager;
	this->gameManager = gameManager;
}

void AssetsInitializer::InitializeScenes()
{
	TitleScreenScene* titleScreenScene = new TitleScreenScene(mainEngine, subEngine, sceneManager);
	GameplayScene* gameplayScene = new GameplayScene(mainEngine, subEngine, gameManager);

	EndOfLevelScene* newRecordScene = new EndOfLevelScene(
		mainEngine,
		subEngine,
		sceneManager,
		SFX_PASSRECORD,
		"newRecordText",
		BackgroundPassRecordBitmap,
		BackgroundPassRecordBitmapLen,
		NewRecordTitleData::GetCenteredPosition(),
		NewRecordTitleData::TILES);

	EndOfLevelScene* gameOverScene = new EndOfLevelScene(
		mainEngine,
		subEngine,
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
	mainEngine->AddPalette(PressAnyKeyText0Pal, "text");
	subEngine->AddPalette(PressAnyKeyText0Pal, "text");
	mainEngine->SetTextFontTo((void*) fontTiles, (void*) fontPal, fontPalLen);

	InitPressAnyKeyText();
}

void AssetsInitializer::InitPressAnyKeyText()
{
	subEngine->AddSprite("pressAnyKeyText0", PressAnyKeyText0Tiles, PressAnyKeyTextData::SPRITE_SIZE);
	subEngine->AddSprite("pressAnyKeyText1", PressAnyKeyText1Tiles, PressAnyKeyTextData::SPRITE_SIZE);
	subEngine->AddSprite("pressAnyKeyText2", PressAnyKeyText2Tiles, PressAnyKeyTextData::SPRITE_SIZE);
	subEngine->AddSprite("pressAnyKeyText3", PressAnyKeyText3Tiles, PressAnyKeyTextData::SPRITE_SIZE);
}