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
#include "Font.h"

#include "Balloon.h"
#include "GameManager.h"

#include <time.h>
#include<string>

int main()
{
	const int DISTANCE_BETWEEN_UI_BALLOONS = 20;
	const int BALLOONS_COUNT = 5;

	HardwareManager::InitAndSetEverything();
	srand(time(NULL));

	OamEngine main = OamEngine(UPPER);
	OamEngine sub = OamEngine(BOTTOM);

	GameManager gameManager = GameManager(3);

	main.AddSprite("balloonUI", BalloonUITiles, SpriteSize_32x32);
	std::vector<void*> balloonFlyFrames;
	std::vector<void*> balloonBurstFrames;
	int balloonSpriteSheetWidth = 2048 / 4;


	sub.AddSprite("balloonFly0", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 0, SpriteSize_64x64);
	sub.AddSprite("balloonFly1", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 1, SpriteSize_64x64);
	sub.AddSprite("balloonFly2", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 2, SpriteSize_64x64);
	sub.AddSprite("balloonFly3", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 3, SpriteSize_64x64);

	sub.AddSprite("balloonBurst0", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 4, SpriteSize_64x64);
	sub.AddSprite("balloonBurst1", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 5, SpriteSize_64x64);
	sub.AddSprite("balloonBurst2", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 6, SpriteSize_64x64);
	sub.AddSprite("balloonBurst3", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 7, SpriteSize_64x64);
	
	balloonFlyFrames.insert(balloonFlyFrames.end(), sub.GetSprite("balloonFly0"));
	balloonFlyFrames.insert(balloonFlyFrames.end(), sub.GetSprite("balloonFly1"));
	balloonFlyFrames.insert(balloonFlyFrames.end(), sub.GetSprite("balloonFly2"));
	balloonFlyFrames.insert(balloonFlyFrames.end(), sub.GetSprite("balloonFly3"));

	balloonBurstFrames.insert(balloonBurstFrames.end(), sub.GetSprite("balloonBurst0")); 
	balloonBurstFrames.insert(balloonBurstFrames.end(), sub.GetSprite("balloonBurst1")); 
	balloonBurstFrames.insert(balloonBurstFrames.end(), sub.GetSprite("balloonBurst2")); 
	balloonBurstFrames.insert(balloonBurstFrames.end(), sub.GetSprite("balloonBurst3")); 

	touchPosition touch;
	Vector2 touchVector2 = Vector2(0, 0);


	sub.AddPallete(BalloonSpritePal, "balloon");

	Balloon* balloons[BALLOONS_COUNT] = { new Balloon(SpriteSize_64x64, "fly", 2, 22, 27, 20, 5, &gameManager),
						  new Balloon(SpriteSize_64x64, "fly", 2, 22, 27, 20, 5, &gameManager),
						  new Balloon(SpriteSize_64x64, "fly", 2, 22, 27, 20, 5, &gameManager),
						  new Balloon(SpriteSize_64x64, "fly", 2, 22, 27, 20, 5, &gameManager),
						  new Balloon(SpriteSize_64x64, "fly", 2, 22, 27, 20, 5, &gameManager) };

	Animation* flyAnimations[BALLOONS_COUNT] = { new Animation(0.2, 3, balloons[0], true, balloonFlyFrames),
									new Animation(0.2, 3, balloons[1], true, balloonFlyFrames),
									new Animation(0.2, 3, balloons[2], true, balloonFlyFrames),
									new Animation(0.2, 3, balloons[3], true, balloonFlyFrames),
									new Animation(0.2, 3, balloons[4], true, balloonFlyFrames) };
	Animation* burstAnimations[BALLOONS_COUNT] = { new Animation(0.2, 3, balloons[0],false, balloonBurstFrames),
									   new Animation(0.2, 3, balloons[1],false, balloonBurstFrames),
									   new Animation(0.2, 3, balloons[2],false, balloonBurstFrames),
									   new Animation(0.2, 3, balloons[3],false, balloonBurstFrames),
									   new Animation(0.2, 3, balloons[4],false, balloonBurstFrames) };

	Balloon balloon = Balloon(SpriteSize_64x64, "fly", 2, 22, 27, 20, 5, &gameManager);
	sub.InitEntity(&balloon);
	balloon.ChangePalleteTo(sub.GetPallete("balloon"));

	Animation flyAnimation = Animation(0.2, 3, &balloon, true, balloonFlyFrames);
	Animation burstAnimation = Animation(0.2, 3, &balloon, false, balloonBurstFrames);
	balloon.AddAnimation("fly", &flyAnimation);
	balloon.AddAnimation("burst", &burstAnimation);

	for (int i = 0; i < BALLOONS_COUNT; i++)
	{
		sub.InitEntity(balloons[i]);
		balloons[i]->ChangePalleteTo(sub.GetPallete("balloon"));

		balloons[i]->AddAnimation("fly", flyAnimations[i]);
		balloons[i]->AddAnimation("burst", burstAnimations[i]);
	}


	Entity balloonsUI[] = { Entity(new Vector2(DISTANCE_BETWEEN_UI_BALLOONS * 0, 0), SpriteSize_32x32),
						   Entity(new Vector2(DISTANCE_BETWEEN_UI_BALLOONS * 1, 0), SpriteSize_32x32),
						   Entity(new Vector2(DISTANCE_BETWEEN_UI_BALLOONS * 2, 0), SpriteSize_32x32) };
	balloonsUI[0].spriteAddress = main.GetSprite("balloonUI");
	balloonsUI[1].spriteAddress = main.GetSprite("balloonUI");
	balloonsUI[2].spriteAddress = main.GetSprite("balloonUI");
	main.AddPallete(BalloonUIPal, "balloonUI");
	for (int i = 0; i < 3; i++)
	{
		main.InitEntity(&balloonsUI[i]);
		balloonsUI[i].ChangePalleteTo(main.GetPallete("balloonUI"));
	}

	main.SetBackgroundTo(Background1Bitmap, Background1BitmapLen);
	sub.SetBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

	main.SetTextFont((void*) fontTiles, (void*) fontPal, fontPalLen);
	int d = 0;
	int i = 0;
	int size = 1;

	while (true)
	{
		HardwareManager::ClearScreens();
		scanKeys();
		touchRead(&touch);
		touchVector2.x = touch.px;
		touchVector2.y = touch.py;

		printf("\n   Score: ");
		printf(std::to_string(gameManager.GetScore()).c_str());

		for (int i = 0; i < BALLOONS_COUNT; i++)
		{
			balloons[i]->Update();
			balloons[i]->Render();
			balloons[i]->UpdateAnimation();
		}

		if (keysDown() & KEY_TOUCH)
		{
			d++;
			for (int i = 0; i < BALLOONS_COUNT; i++)
			{
				balloons[i]->CheckCollision(&touchVector2);
			}
		}
		for (int i = 0; i < BALLOONS_COUNT; i++)
		{
			if (i < gameManager.GetCurrentLife())
				balloonsUI[i].Render();
		}

		main.UpdateOam();
		sub.UpdateOam();
		HardwareManager::WaitForNextFrame();
	}
	return 0;
}
