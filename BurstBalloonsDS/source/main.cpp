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

#include <time.h>
#include<string>

int main()
{

	const int BALLOONS_COUNT = 5;

	HardwareManager::InitAndSetEverything();
	srand(time(NULL));

	OamEngine main = OamEngine(UPPER);
	OamEngine sub = OamEngine(BOTTOM);

	GameManager gameManager = GameManager(3);

	main.SetTextFont((void*) fontTiles, (void*) fontPal, fontPalLen);
	bool inGameOver = false;

	GameOverScene gameOverScene = GameOverScene(&main, &sub, &gameManager);
	gameOverScene.SetMainBackgroundTo(BackgroundGameOverBitmap, BackgroundGameOverBitmapLen);
	gameOverScene.SetSubBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

	GameplayScene gameplayScene = GameplayScene(&main, &sub, &gameManager);
	gameplayScene.SetMainBackgroundTo(Background1Bitmap, Background1BitmapLen);
	gameplayScene.SetSubBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);
	gameplayScene.Load();
	while (true)
	{
		HardwareManager::ClearScreens();


		if (gameManager.GetCurrentLife() <= 0)
		{
			if (!inGameOver)
			{
				inGameOver = true;
				gameOverScene.Load();
			}
			gameOverScene.InputLoop();
			gameOverScene.GameLoop();
		}
		else
		{
			inGameOver = false;
			gameplayScene.InputLoop();
			gameplayScene.GameLoop();
		}

		main.UpdateOam();
		sub.UpdateOam();
		HardwareManager::WaitForNextFrame();
	}
	return 0;
}
