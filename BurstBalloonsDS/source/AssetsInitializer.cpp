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
		"NewRecordText",
		BackgroundPassRecordBitmap,
		BackgroundPassRecordBitmapLen,
		NewRecordTitleData::GetCenteredPosition(),
		NewRecordTitleData::TILES);

	EndOfLevelScene* gameOverScene = new EndOfLevelScene(
		mainEngine,
		subEngine,
		sceneManager,
		SFX_GAMEOVER,
		"GameOverText",
		BackgroundGameOverBitmap,
		BackgroundGameOverBitmapLen,
		GameOverTitleData::GetCenteredPosition(),
		GameOverTitleData::TILES);

	sceneManager->AddScene("TitleScreen", titleScreenScene);
	sceneManager->AddScene("Gameplay", gameplayScene);
	sceneManager->AddScene("NewRecord", newRecordScene);
	sceneManager->AddScene("GameOver", gameOverScene);
}

void AssetsInitializer::InitializeGlobalGraphics()
{
	mainEngine->AddPalette(PressAnyKeyText0Pal, "Text");
	subEngine->AddPalette(PressAnyKeyText0Pal, "Text");
	mainEngine->SetTextFontTo((void*) fontTiles, (void*) fontPal, fontPalLen);

	InitPressAnyKeyText();
}

void AssetsInitializer::InitPressAnyKeyText()
{
	subEngine->AddSprite("PressAnyKeyText0", PressAnyKeyText0Tiles, PressAnyKeyTextData::SPRITE_SIZE);
	subEngine->AddSprite("PressAnyKeyText1", PressAnyKeyText1Tiles, PressAnyKeyTextData::SPRITE_SIZE);
	subEngine->AddSprite("PressAnyKeyText2", PressAnyKeyText2Tiles, PressAnyKeyTextData::SPRITE_SIZE);
	subEngine->AddSprite("PressAnyKeyText3", PressAnyKeyText3Tiles, PressAnyKeyTextData::SPRITE_SIZE);
}