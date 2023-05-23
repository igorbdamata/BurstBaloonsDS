#include <nds.h>
#include<nds/arm9/sprite.h>
#include<nds/touch.h>
#include<nds/arm9/input.h>
#include <soundbank.h>

#include "Engine/OamEngine.h"
#include "Engine/Entity.h"
#include "Engine/HardwareManager.h"
#include "Engine/SoundManager.h"
#include "Engine/Vector2.h"

#include <soundbank_bin.h>
#include "BalloonSprite.h"
#include "BalloonUI.h"
#include "Background.h"
#include "Background1.h"
#include "BackgroundGameOver.h"
#include "Font.h"

#include "Balloon.h"
#include "GameManager.h"
#include "Scenes/GameplayScene.h"
#include "Scenes/GameOverScene.h"
#include "Scenes/TitleScreenScene.h"

#include <time.h>
#include<string>

int main()
{

	const int BALLOONS_COUNT = 5;

	HardwareManager::InitAndSetEverything();
	srand(time(NULL));

	OamEngine main = OamEngine(UPPER);
	OamEngine sub = OamEngine(BOTTOM);

	SceneManager sceneManager = SceneManager();

	GameManager gameManager = GameManager(3, &sceneManager, 120.0f);

	GameOverScene gameOverScene = GameOverScene(&main, &sub, &sceneManager);
	gameOverScene.SetMainBackgroundTo(BackgroundGameOverBitmap, BackgroundGameOverBitmapLen);
	gameOverScene.SetSubBackgroundTo(BackgroundGameOverBitmap, BackgroundGameOverBitmapLen);

	GameplayScene gameplayScene = GameplayScene(&main, &sub, &gameManager);
	gameplayScene.SetMainBackgroundTo(Background1Bitmap, Background1BitmapLen);
	gameplayScene.SetSubBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

	TitleScreenScene titleScreenScene = TitleScreenScene(&main, &sub, &sceneManager);
	titleScreenScene.SetMainBackgroundTo(Background1Bitmap, Background1BitmapLen);
	titleScreenScene.SetSubBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

	sceneManager.AddScene("Gameplay", &gameplayScene);
	sceneManager.AddScene("GameOver", &gameOverScene);
	sceneManager.AddScene("TitleScreen", &titleScreenScene);
	sceneManager.ChangeSceneTo("TitleScreen");

	while (true)
	{
		HardwareManager::ClearScreens();

		sceneManager.GetCurrentScene()->InputLoop();
		sceneManager.GetCurrentScene()->GameLoop();
		main.UpdateOam();
		sub.UpdateOam();
		HardwareManager::WaitForNextFrame();
	}
	return 0;
}
