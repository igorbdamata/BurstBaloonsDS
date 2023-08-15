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

void InitPressAnyKeyText(GraphicsHandler* engine)
{
	engine->AddSprite("PressAnyKeyText0", PressAnyKeyText0Tiles, SpriteSize_64x64);
	engine->AddSprite("PressAnyKeyText1", PressAnyKeyText1Tiles, SpriteSize_64x64);
	engine->AddSprite("PressAnyKeyText2", PressAnyKeyText2Tiles, SpriteSize_64x64);
	engine->AddSprite("PressAnyKeyText3", PressAnyKeyText3Tiles, SpriteSize_64x64);
	engine->AddPalette(PressAnyKeyText0Pal, "PressAnyKeyText");

}

int main()
{
	HardwareManager::InitAndSetEverything();

	GraphicsHandler* main = new GraphicsHandler(Screen::TOP);
	GraphicsHandler* sub = new GraphicsHandler(Screen::BOTTOM);

	main->AddSprite("NewRecordText0", TextPassRecord0Tiles, SpriteSize_64x64);
	main->AddSprite("NewRecordText1", TextPassRecord1Tiles, SpriteSize_64x64);
	main->AddSprite("NewRecordText2", TextPassRecord2Tiles, SpriteSize_64x64);
	main->AddSprite("NewRecordText3", TextPassRecord3Tiles, SpriteSize_64x64);
	main->AddPalette(PressAnyKeyText0Pal, "NewRecordText");

	main->AddSprite("GameOverText0", GameOverText0Tiles, SpriteSize_64x64);
	main->AddSprite("GameOverText1", GameOverText1Tiles, SpriteSize_64x64);
	main->AddSprite("GameOverText2", GameOverText2Tiles, SpriteSize_64x64);
	main->AddSprite("GameOverText3", GameOverText3Tiles, SpriteSize_64x64);
	main->AddPalette(PressAnyKeyText0Pal, "GameOverText");

	InitPressAnyKeyText(sub);
	main->SetTextFontTo((void*) fontTiles, (void*) fontPal, fontPalLen);

	SceneManager* sceneManager = new SceneManager();

	GameManager* gameManager = new GameManager(sceneManager);

	TitleScreenScene* titleScreenScene = new TitleScreenScene(main, sub, sceneManager);
	GameplayScene* gameplayScene = new GameplayScene(main, sub, gameManager);
	EndOfLevelScene* newRecordScene = new EndOfLevelScene(main, sub, sceneManager, "NewRecordText", SFX_PASSRECORD, BackgroundPassRecordBitmap, BackgroundPassRecordBitmapLen);
	EndOfLevelScene* gameOverScene = new EndOfLevelScene(main, sub, sceneManager, "GameOverText", SFX_GAMEOVER, BackgroundGameOverBitmap, BackgroundGameOverBitmapLen);

	sceneManager->AddScene("TitleScreen", titleScreenScene);
	sceneManager->AddScene("Gameplay", gameplayScene);
	sceneManager->AddScene("NewRecord", newRecordScene);
	sceneManager->AddScene("GameOver", gameOverScene);

	sceneManager->ChangeSceneTo("TitleScreen");

	while (true)
	{
		HardwareManager::ClearScreens();

		sceneManager->GetCurrentScene()->InputLoop();
		sceneManager->GetCurrentScene()->GameLoop();

		main->Update();
		sub->Update();

		HardwareManager::WaitForNextFrame();
	}
	return 0;
}
