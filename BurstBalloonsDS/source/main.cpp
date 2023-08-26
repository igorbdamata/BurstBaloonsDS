#include "Engine/GraphicsHandler.h"
#include "Engine/HardwareManager.h"
#include "GameManager.h"
#include "Scenes/SceneManager.h"

#include "AssetsInitializer.h"

int main()
{
	HardwareManager::InitAndSetEverything();

	GraphicsHandler* topGraphicsHandler = new GraphicsHandler(Screen::TOP);
	GraphicsHandler* bottomGraphicsHandler = new GraphicsHandler(Screen::BOTTOM);

	SceneManager* sceneManager = new SceneManager();
	GameManager* gameManager = new GameManager(sceneManager);
	
	AssetsInitializer* assetsInitializer = new AssetsInitializer(topGraphicsHandler, bottomGraphicsHandler, sceneManager, gameManager);
	assetsInitializer->InitializeGlobalGraphics();
	assetsInitializer->InitializeScenes();
	delete assetsInitializer;

	sceneManager->ChangeSceneTo("titleScreen");

	while (true)
	{
		HardwareManager::ClearScreens();

		sceneManager->GetCurrentScene()->InputLoop();
		sceneManager->GetCurrentScene()->GameLoop();

		topGraphicsHandler->Update();
		bottomGraphicsHandler->Update();

		HardwareManager::WaitForNextFrame();
	}

	return 0;
}