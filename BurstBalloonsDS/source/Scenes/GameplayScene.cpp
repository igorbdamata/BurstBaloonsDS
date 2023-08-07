#include "Scenes/GameplayScene.h"
#include <nds/arm9/input.h>
#include <nds/arm9/sprite.h>
#include <string>
#include "BalloonSprite.h"
#include "Engine/SoundManager.h"
#include "Engine/HardwareManager.h"
#include "BalloonUI.h"
#include "Background.h"
#include "Background1.h"
#include "Data/GameplayData.h"
#include<soundbank.h>

GameplayScene::GameplayScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, GameManager* gameManager) : Scene(mainEngine, subEngine)
{
	this->gameManager = gameManager;
	std::vector<void*> balloonFlyFrames;
	std::vector<void*> balloonBurstFrames;
	int balloonSpriteSheetWidth = 2048 / 4;
	mainEngine->AddSprite("balloonUI", BalloonUITiles, SpriteSize_32x32);
	subEngine->AddPalette(BalloonSpritePal, "balloon");

	subEngine->AddSprite("balloonFly0", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 0, SpriteSize_64x64);
	subEngine->AddSprite("balloonFly1", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 1, SpriteSize_64x64);
	subEngine->AddSprite("balloonFly2", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 2, SpriteSize_64x64);
	subEngine->AddSprite("balloonFly3", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 3, SpriteSize_64x64);

	subEngine->AddSprite("balloonBurst0", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 4, SpriteSize_64x64);
	subEngine->AddSprite("balloonBurst1", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 5, SpriteSize_64x64);
	subEngine->AddSprite("balloonBurst2", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 6, SpriteSize_64x64);
	subEngine->AddSprite("balloonBurst3", BalloonSpriteTiles + (balloonSpriteSheetWidth) * 7, SpriteSize_64x64);

	balloonFlyFrames.insert(balloonFlyFrames.end(), subEngine->GetSprite("balloonFly0"));
	balloonFlyFrames.insert(balloonFlyFrames.end(), subEngine->GetSprite("balloonFly1"));
	balloonFlyFrames.insert(balloonFlyFrames.end(), subEngine->GetSprite("balloonFly2"));
	balloonFlyFrames.insert(balloonFlyFrames.end(), subEngine->GetSprite("balloonFly3"));

	balloonBurstFrames.insert(balloonBurstFrames.end(), subEngine->GetSprite("balloonBurst0"));
	balloonBurstFrames.insert(balloonBurstFrames.end(), subEngine->GetSprite("balloonBurst1"));
	balloonBurstFrames.insert(balloonBurstFrames.end(), subEngine->GetSprite("balloonBurst2"));
	balloonBurstFrames.insert(balloonBurstFrames.end(), subEngine->GetSprite("balloonBurst3"));


	touch;
	touchVector2 = Vector2(0, 0);
	Balloon* balloons[GameplayData::BALLOONS_COUNT] = { new Balloon(gameManager),
										  new Balloon(gameManager),
										  new Balloon(gameManager),
										  new Balloon(gameManager),
										  new Balloon(gameManager) };
	Animation* flyAnimations[GameplayData::BALLOONS_COUNT] = {
		new Animation(0.2, 3, true, balloonFlyFrames, [balloons](void* newSprite) {balloons[0]->SetSpriteTo(newSprite); }),
		new Animation(0.2, 3, true, balloonFlyFrames, [balloons](void* newSprite) {balloons[1]->SetSpriteTo(newSprite); }),
		new Animation(0.2, 3, true, balloonFlyFrames, [balloons](void* newSprite) {balloons[2]->SetSpriteTo(newSprite); }),
		new Animation(0.2, 3, true, balloonFlyFrames, [balloons](void* newSprite) {balloons[3]->SetSpriteTo(newSprite); }),
		new Animation(0.2, 3, true, balloonFlyFrames, [balloons](void* newSprite) {balloons[4]->SetSpriteTo(newSprite); }) };
	Animation* burstAnimations[GameplayData::BALLOONS_COUNT] = {
		new Animation(0.2, 3, false, balloonBurstFrames, [balloons](void* newSprite) {balloons[0]->SetSpriteTo(newSprite); }),
		new Animation(0.2, 3, false, balloonBurstFrames, [balloons](void* newSprite) {balloons[1]->SetSpriteTo(newSprite); }),
		new Animation(0.2, 3, false, balloonBurstFrames, [balloons](void* newSprite) {balloons[2]->SetSpriteTo(newSprite); }),
		new Animation(0.2, 3, false, balloonBurstFrames, [balloons](void* newSprite) {balloons[3]->SetSpriteTo(newSprite); }),
		new Animation(0.2, 3, false, balloonBurstFrames, [balloons](void* newSprite) {balloons[4]->SetSpriteTo(newSprite); }) };


	for (int i = 0; i < GameplayData::BALLOONS_COUNT; i++)
	{
		this->balloons[i] = balloons[i];

		subEngine->InitEntity(balloons[i]);
		balloons[i]->SetPaletteTo(subEngine->GetPalette("balloon"));

		balloons[i]->AddAnimation("fly", flyAnimations[i]);
		balloons[i]->AddAnimation("burst", burstAnimations[i]);
	}

	Entity* balloonsUI[] = { new Entity(new Vector2(GameplayData::DISTANCE_BETWEEN_UI_BALLOONS * 0 + GameplayData::UI_BALLOON_ALIGNMENT, 0),32,32, new Vector2(0,0), SpriteSize_32x32),
							 new Entity(new Vector2(GameplayData::DISTANCE_BETWEEN_UI_BALLOONS * 1 + GameplayData::UI_BALLOON_ALIGNMENT, 0),32,32, new Vector2(0,0), SpriteSize_32x32),
							 new Entity(new Vector2(GameplayData::DISTANCE_BETWEEN_UI_BALLOONS * 2 + GameplayData::UI_BALLOON_ALIGNMENT, 0),32,32, new Vector2(0,0), SpriteSize_32x32) };
	mainEngine->AddPalette(BalloonUIPal, "balloonUI");
	for (int i = 0; i < 3; i++)
	{

		this->balloonsUI[i] = balloonsUI[i];
		mainEngine->InitEntity(balloonsUI[i]);
		balloonsUI[i]->SetSpriteTo(mainEngine->GetSprite("balloonUI"));
		balloonsUI[i]->SetPaletteTo(mainEngine->GetPalette("balloonUI"));
	}

	SetMainBackgroundTo(Background1Bitmap, Background1BitmapLen);
	SetSubBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);
}

void GameplayScene::Load()
{
	Scene::Load();
	SoundManager::StopAllSFXs();
	if (!SoundManager::IsPlayingSong(MOD_THEME)) SoundManager::PlaySong(MOD_THEME);
	gameManager->ResetGameplayData();
	for (int i = 0; i < GameplayData::BALLOONS_COUNT; i++)
		balloons[i]->Respawn();
}

void GameplayScene::InputLoop()
{
	Scene::InputLoop();

	touchRead(&touch);
	touchVector2.x = touch.px;
	touchVector2.y = touch.py;

	if (keysDown() & KEY_TOUCH)
	{
		for (int i = 0; i < GameplayData::BALLOONS_COUNT; i++)
		{
			if (balloons[i]->IsCollidingWith(&touchVector2))
				balloons[i]->Burst();
		}
	}
}
void GameplayScene::GameLoop()
{
	printf("\n\n\n\n");
	printf(" Score: ");
	printf(std::to_string(gameManager->GetScore()).c_str());
	printf("\n High Score: ");
	printf(std::to_string(gameManager->GetHighScore()).c_str());

	for (int i = 0; i < GameplayData::BALLOONS_COUNT; i++)
	{
		balloons[i]->Update();
		balloons[i]->Render();
		balloons[i]->UpdateAnimation();
	}

	for (int i = 0; i < GameplayData::BALLOONS_COUNT; i++)
	{
		if (i < gameManager->GetCurrentLife())
			balloonsUI[i]->Render();
	}
}