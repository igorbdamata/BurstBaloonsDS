#include <string>
#include <nds/arm9/sprite.h>
#include <nds/arm9/input.h>

#include "Scenes/GameplayScene.h"

#include "Engine/SoundManager.h"
#include "Engine/HardwareManager.h"

#include "Data/GameplayData.h"
#include "Data/LifeIconData.h"

#include "Data/BalloonData.h"
#include "Data/BurstAnimationData.h"
#include "Data/FlyAnimationData.h"

#include "BalloonSprite.h"
#include "BalloonUI.h"
#include "Background.h"
#include "Background1.h"

#include<soundbank.h>

GameplayScene::GameplayScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, GameManager* gameManager) : Scene(mainEngine, subEngine)
{
	this->gameManager = gameManager;
	vector2TouchPosition = Vector2(0, 0);
	
	SetMainBackgroundTo(Background1Bitmap, Background1BitmapLen);
	SetSubBackgroundTo(BackgroundBitmap, BackgroundBitmapLen);

	#pragma region InitBalloon
	#pragma region InitFlyAnimation
	std::vector<void*> flyAnimationFrames;
	for (int i = 0; i < FlyAnimationData::FRAMES_COUNT; i++)
	{
		std::string spriteName = "balloonFly" + i;
		const void* tiles = BalloonSpriteTiles + (BalloonData::SPRITE_SHEET_OFFSET) *i;
		subEngine->AddSprite(spriteName, tiles, BalloonData::SPRITE_SIZE);
		flyAnimationFrames.insert(flyAnimationFrames.end(), subEngine->GetSprite(spriteName));
	}
	#pragma endregion
	#pragma region InitBurstAnimation
	std::vector<void*> burstAnimationFrames;
	for (int i = FlyAnimationData::FRAMES_COUNT; i < FlyAnimationData::FRAMES_COUNT + BurstAnimationData::FRAMES_COUNT; i++)
	{
		std::string spriteName = "balloonBurst" + (i - FlyAnimationData::FRAMES_COUNT);
		const void* tiles = BalloonSpriteTiles + (BalloonData::SPRITE_SHEET_OFFSET) *i;
		subEngine->AddSprite(spriteName, tiles, BalloonData::SPRITE_SIZE);
		burstAnimationFrames.insert(burstAnimationFrames.end(), subEngine->GetSprite(spriteName));
	}
	#pragma endregion

	subEngine->AddPalette(BalloonSpritePal, "balloon");

	for (int i = 0; i < GameplayData::BALLOONS_COUNT; i++)
	{
		balloons[i] = new Balloon(gameManager, flyAnimationFrames, burstAnimationFrames);
		subEngine->InitEntity(balloons[i]);
		balloons[i]->SetPaletteTo(subEngine->GetPalette("balloon"));
	}
	#pragma endregion

	#pragma region LifeIconsInit
	mainEngine->AddSprite("balloonUI", BalloonUITiles, LifeIconData::SPRITE_SIZE);
	mainEngine->AddPalette(BalloonUIPal, "balloonUI");

	for (int i = 0; i < GameplayData::TOTAL_LIFE; i++)
	{
		float iconPositionX = LifeIconData::DISTANCE_BETWEEN_LIFE_ICONS * i + LifeIconData::LIFE_ICON_HORIZONTAL_ALIGNMENT;
		const float iconPositionY = LifeIconData::LIFE_ICON_VERTICAL_ALIGNMENT;
		this->lifeIcons[i] = new Entity(new Vector2(iconPositionX, iconPositionY),
										LifeIconData::SPRITE_WIDTH, LifeIconData::SPRITE_HEIGHT,
										new Vector2(LifeIconData::SPRITE_OFFSET_X, LifeIconData::SPRITE_OFFSET_Y),
										LifeIconData::SPRITE_SIZE);
		mainEngine->InitEntity(lifeIcons[i]);
		lifeIcons[i]->SetSpriteTo(mainEngine->GetSprite("balloonUI"));
		lifeIcons[i]->SetPaletteTo(mainEngine->GetPalette("balloonUI"));
	}
	#pragma endregion
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
	if (!(keysDown() & KEY_TOUCH)) return;

	UpdateTouchPosition();
	BurstTouchedBalloons();
}
void GameplayScene::UpdateTouchPosition()
{
	touchPosition structTouchPosition;
	touchRead(&structTouchPosition);
	vector2TouchPosition.x = structTouchPosition.px;
	vector2TouchPosition.y = structTouchPosition.py;
}
void GameplayScene::BurstTouchedBalloons()
{
	for (int i = 0; i < GameplayData::BALLOONS_COUNT; i++)
	{
		if (balloons[i]->IsCollidingWith(&vector2TouchPosition))
			balloons[i]->Burst();
	}
}

void GameplayScene::GameLoop()
{
	UpdateBalloons();
	UpdateHUD();
}
void GameplayScene::UpdateBalloons()
{
	for (int i = 0; i < GameplayData::BALLOONS_COUNT; i++)
		balloons[i]->Update();
}
void GameplayScene::UpdateHUD()
{
	printf("\n\n\n");
	printf("\n Score: ");
	printf(std::to_string(gameManager->GetScore()).c_str());
	printf("\n High Score: ");
	printf(std::to_string(gameManager->GetHighScore()).c_str());

	for (int i = 0; i < GameplayData::TOTAL_LIFE; i++)
	{
		if (i < gameManager->GetCurrentLife())
			lifeIcons[i]->Render();
		else break;
	}
}