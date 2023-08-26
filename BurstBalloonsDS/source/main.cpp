#include "Engine/GraphicsHandler.h"
#include "Engine/HardwareManager.h"
#include "GameManager.h"
#include "Scenes/SceneManager.h"

#include "AssetsInitializer.h"

int main()
{
	HardwareManager::InitAndSetEverything();

	GraphicsHandler* main = new GraphicsHandler(Screen::TOP);
	GraphicsHandler* sub = new GraphicsHandler(Screen::BOTTOM);

	SceneManager* sceneManager = new SceneManager();
	GameManager* gameManager = new GameManager(sceneManager);
	
	AssetsInitializer* assetsInitializer = new AssetsInitializer(main, sub, sceneManager, gameManager);
	assetsInitializer->InitializeGlobalGraphics();
	assetsInitializer->InitializeScenes();
	delete assetsInitializer;

	sceneManager->ChangeSceneTo("titleScreen");

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