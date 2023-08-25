#include "AssetsInitializer.h"

#include<nds/arm9/sprite.h>
#include<soundbank.h>

#include "Engine/GraphicsHandler.h"
#include "Engine/HardwareManager.h"

#include "GameManager.h"

#include "Scenes/SceneManager.h"
#include "Scenes/TitleScreenScene.h"
#include "Scenes/GameplayScene.h"
#include "Scenes/EndOfLevelScene.h"

#include"PressAnyKeyText0.h"
#include"PressAnyKeyText1.h"
#include"PressAnyKeyText2.h"
#include"PressAnyKeyText3.h"

#include"BackgroundPassRecord.h"
#include"TextPassRecord0.h"
#include"TextPassRecord1.h"
#include"TextPassRecord2.h"
#include"TextPassRecord3.h"

#include"BackgroundGameOver.h"
#include"GameOverText0.h"
#include"GameOverText1.h"
#include"GameOverText2.h"
#include"GameOverText3.h"
#include"font.h"

AssetsInitializer::AssetsInitializer(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager, GameManager* gameManager)
{
	this->mainEngine = mainEngine;
	this->subEngine = subEngine;
	this->sceneManager = sceneManager;
	this->gameManager = gameManager;
}

void AssetsInitializer::InitializeGlobalAssets()
{
	mainEngine->AddPalette(PressAnyKeyText0Pal, "Text");
	subEngine->AddPalette(PressAnyKeyText0Pal, "Text");
	InitPressAnyKeyText();
	mainEngine->SetTextFontTo((void*) fontTiles, (void*) fontPal, fontPalLen);

	TitleScreenScene* titleScreenScene = new TitleScreenScene(mainEngine, subEngine, sceneManager);
	GameplayScene* gameplayScene = new GameplayScene(mainEngine, subEngine, gameManager);
	EndOfLevelScene* newRecordScene = new EndOfLevelScene(mainEngine, subEngine, sceneManager, SFX_PASSRECORD, "NewRecordText", BackgroundPassRecordBitmap, BackgroundPassRecordBitmapLen, new Vector2(24, 76), new const void* [4] { TextPassRecord0Tiles, TextPassRecord1Tiles, TextPassRecord2Tiles, TextPassRecord3Tiles });
	EndOfLevelScene* gameOverScene = new EndOfLevelScene(mainEngine, subEngine, sceneManager, SFX_GAMEOVER, "GameOverText", BackgroundGameOverBitmap, BackgroundGameOverBitmapLen, new Vector2(24, 76), new const void* [4] { GameOverText0Tiles, GameOverText1Tiles, GameOverText2Tiles, GameOverText3Tiles });

	sceneManager->AddScene("TitleScreen", titleScreenScene);
	sceneManager->AddScene("Gameplay", gameplayScene);
	sceneManager->AddScene("NewRecord", newRecordScene);
	sceneManager->AddScene("GameOver", gameOverScene);
}

void AssetsInitializer::InitPressAnyKeyText()
{
	subEngine->AddSprite("PressAnyKeyText0", PressAnyKeyText0Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText1", PressAnyKeyText1Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText2", PressAnyKeyText2Tiles, SpriteSize_64x64);
	subEngine->AddSprite("PressAnyKeyText3", PressAnyKeyText3Tiles, SpriteSize_64x64);
}