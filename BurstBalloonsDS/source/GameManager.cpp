#include "GameManager.h"
#include "Engine/SoundManager.h"
#include "Engine/HardwareManager.h"
#include <soundbank.h>
#include <soundbank_bin.h>
#include <cmath>

GameManager::GameManager(int totalLife, SceneManager* sceneManager, float secondsToReachMaxDifficult)
{
	this->totalLife = totalLife;
	currentLife = totalLife;
	this->sceneManager = sceneManager;
	this->secondsToReachMaxDifficult = secondsToReachMaxDifficult;
}

void GameManager::AddToScore(int value)
{
	score += value;
	if (score > highScore)
		highScore = score;
}

int GameManager::GetScore()
{
	return score;
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
		SoundManager::PlaySFX(SFX_GAMEOVER);
		sceneManager->ChangeSceneTo("GameOver");
	}
	else
		SoundManager::PlaySFX(SFX_LOSELIFE);
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
	float t =  (currentSeconds - gameplayStartTime) / secondsToReachMaxDifficult;
	if (t >= 1) return 1;
	float difficult = pow((1 - t), 3) * (-0.47) + 3 * pow((1 - t), 2) * 0.19 + 3 * (1-t) * pow(t, 2) * 0.86 + pow(t, 3);
	return difficult;
}