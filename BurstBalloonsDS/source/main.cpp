#include<nds/arm9/sprite.h>

#include "Engine/GraphicsHandler.h"
#include "Engine/HardwareManager.h"

#include "GameManager.h"

#include "Scenes/SceneManager.h"
#include "Scenes/TitleScreenScene.h"
#include "Scenes/GameplayScene.h"
#include "Scenes/NewRecordScene.h"
#include "Scenes/GameOverScene.h"

#include"PressAnyKeyText0.h"
#include"PressAnyKeyText1.h"
#include"PressAnyKeyText2.h"
#include"PressAnyKeyText3.h"

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

	InitPressAnyKeyText(sub);

	SceneManager* sceneManager = new SceneManager();

	GameManager* gameManager = new GameManager(sceneManager);

	TitleScreenScene* titleScreenScene = new TitleScreenScene(main, sub, sceneManager);
	GameplayScene* gameplayScene = new GameplayScene(main, sub, gameManager);
	NewRecordScene* newRecordScene = new NewRecordScene(main, sub, sceneManager);
	GameOverScene* gameOverScene = new GameOverScene(main, sub, sceneManager);

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
