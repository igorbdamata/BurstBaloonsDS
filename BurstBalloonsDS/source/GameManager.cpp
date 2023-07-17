#include "GameManager.h"
#include "Engine/SoundManager.h"
#include "Engine/HardwareManager.h"
#include <soundbank.h>
#include <soundbank_bin.h>
#include <cmath>
#include "BackgroundPassRecord.h"
#include "BackgroundGameOver.h"

GameManager::GameManager(int totalLife, SceneManager* sceneManager, float secondsToReachMaxDifficult)
{
	this->totalLife = totalLife;
	currentLife = totalLife;
	this->sceneManager = sceneManager;
	this->secondsToReachMaxDifficult = secondsToReachMaxDifficult;
	highScore = 0;
	score = 0;
}

void GameManager::AddToScore(int value)
{
	score += value;
}

int GameManager::GetScore()
{
	return score;
}
int GameManager::GetHighScore()
{
	return highScore;
}

int GameManager::GetCurrentLife()
{
	return currentLife;
}

void GameManager::RemoveLife()
{
	currentLife--;
	if (currentLife <= 0)
	{
		if (score > highScore)
		{
			highScore = score;
			SoundManager::PlaySFX(SFX_PASSRECORD);
			SetNewRecordGameOver();
		}
		else
		{
			SoundManager::PlaySFX(SFX_GAMEOVER);
			SetDefaultGameOverScene();
		}
		sceneManager->ChangeSceneTo("GameOver");
	}
	else
		SoundManager::PlaySFX(SFX_LOSELIFE);
}
void GameManager::SetNewRecordGameOver()
{
	sceneManager->GetScene("GameOver")->SetMainBackgroundTo(BackgroundPassRecordBitmap, BackgroundPassRecordBitmapLen);
	sceneManager->GetScene("GameOver")->SetSubBackgroundTo(BackgroundPassRecordBitmap, BackgroundPassRecordBitmapLen);
}
void GameManager::SetDefaultGameOverScene()
{
	sceneManager->GetScene("GameOver")->SetMainBackgroundTo(BackgroundGameOverBitmap, BackgroundGameOverBitmapLen);
	sceneManager->GetScene("GameOver")->SetSubBackgroundTo(BackgroundGameOverBitmap, BackgroundGameOverBitmapLen);
}

void GameManager::ResetGameplayData()
{
	currentLife = totalLife;
	score = 0;
	gameplayStartTime = HardwareManager::GetCurrentMilliseconds() / 1000;
}

float GameManager::GetDifficultFactor()
{
	float currentSeconds = HardwareManager::GetCurrentMilliseconds() / 1000;
	if (currentSeconds - gameplayStartTime > secondsToReachMaxDifficult) return 1;
	float timePercent = (currentSeconds - gameplayStartTime) / secondsToReachMaxDifficult;
	float initialDifficult = 0.4f;
	float angularCoefficient = atan2(1 - initialDifficult, 1);
	float difficult = angularCoefficient * timePercent + initialDifficult;
	return difficult;
}