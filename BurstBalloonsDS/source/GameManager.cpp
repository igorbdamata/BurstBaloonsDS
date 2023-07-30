#include <soundbank.h>
#include <math.h>

#include "GameManager.h"
#include "Engine/SoundManager.h"
#include "Engine/HardwareManager.h"

GameManager::GameManager(int totalLife, float secondsToReachMaxDifficult, SceneManager* sceneManager)
{
	this->totalLife = totalLife;
	currentLife = totalLife;
	this->secondsToReachMaxDifficult = secondsToReachMaxDifficult;
	this->sceneManager = sceneManager;
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
		OnRunOutOfLives();
	else
		SoundManager::PlaySFX(SFX_LOSELIFE);
}
void GameManager::OnRunOutOfLives()
{
	const char* sceneToLoad = "GameOver";
	if (score > highScore)
	{
		highScore = score;
		sceneToLoad = "NewRecord";
	}
	sceneManager->ChangeSceneTo(sceneToLoad);
}

float GameManager::GetDifficultFactor()
{
	float secondsSinceGameplayStart = HardwareManager::GetCurrentSeconds() - gameplayStartSeconds;
	float timePercent = secondsSinceGameplayStart / secondsToReachMaxDifficult;

	if (timePercent >= 1) return 1;

	float initialDifficult = 0.4f;
	float difficultIncreasePerTimePercent = 1 - initialDifficult;
	return difficultIncreasePerTimePercent * timePercent + initialDifficult;
}

void GameManager::ResetGameplayData()
{
	currentLife = totalLife;
	score = 0;
	gameplayStartSeconds = HardwareManager::GetCurrentSeconds();
}