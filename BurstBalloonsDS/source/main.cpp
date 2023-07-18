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
#include "BackgroundPassRecord.h"
#include "BackgroundPassRecord1.h"
#include "BackgroundPassRecord2.h"
#include "Font.h"

#include "BitmapImage.h"
#include "Balloon.h"
#include "BackgroundAnimationTest.h"
#include "GameManager.h"
#include "Scenes/GameplayScene.h"
#include "Scenes/NewRecordScene.h"
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

	main.SetPrintConsole();

	SceneManager sceneManager = SceneManager();

	GameManager gameManager = GameManager(3, &sceneManager, 120.0f);

	GameOverScene gameOverScene = GameOverScene(&main, &sub, &sceneManager);
	gameOverScene.SetMainBackgroundTo(BackgroundGameOverBitmap, BackgroundGameOverBitmapLen);
	gameOverScene.SetSubBackgroundTo(BackgroundGameOverBitmap, BackgroundGameOverBitmapLen);

	NewRecordScene newRecordScene = NewRecordScene(&main, &sub, &sceneManager);
	newRecordScene.SetMainBackgroundTo(BackgroundPassRecordBitmap, BackgroundPassRecordBitmapLen);
	newRecordScene.SetSubBackgroundTo(BackgroundPassRecordBitmap, BackgroundPassRecordBitmapLen);

	GameplayScene gameplayScene = GameplayScene(&main, &sub, &gameManager);
	gameplayScene.SetMainBackgroundTo(Background1Bitmap, Background1BitmapLen);
	gameplayScene.SetSubBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

	TitleScreenScene titleScreenScene = TitleScreenScene(&main, &sub, &sceneManager);
	titleScreenScene.SetMainBackgroundTo(Background1Bitmap, Background1BitmapLen);
	titleScreenScene.SetSubBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

	sceneManager.AddScene("Gameplay", &gameplayScene);
	sceneManager.AddScene("GameOver", &gameOverScene);
	sceneManager.AddScene("NewRecord", &newRecordScene);
	sceneManager.AddScene("TitleScreen", &titleScreenScene);
	sceneManager.ChangeSceneTo("TitleScreen");

	const unsigned int* backgrounds[] = { Background1Bitmap, BackgroundBitmap, BackgroundGameOverBitmap, BackgroundPassRecordBitmap, BackgroundPassRecord1Bitmap , BackgroundPassRecord2Bitmap };

	int i = 0;
	float t = HardwareManager::GetCurrentMilliseconds();
	while (true)
	{
		HardwareManager::ClearScreens();
		if (HardwareManager::GetCurrentMilliseconds() - t >= 500)
		{
			i++;
			t = HardwareManager::GetCurrentMilliseconds();
		}
		if (i > 5)
			i = 0;
		main.SetBackgroundTo(backgrounds[i], Background1BitmapLen);
		sceneManager.GetCurrentScene()->InputLoop();
		sceneManager.GetCurrentScene()->GameLoop();

		main.UpdateOam();
		sub.UpdateOam();
		HardwareManager::WaitForNextFrame();
	}
	return 0;
}
