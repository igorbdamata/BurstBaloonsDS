#include "GameManager.h"
#include "Engine/SoundManager.h"
#include <soundbank.h>
#include <soundbank_bin.h>

GameManager::GameManager(int totalLife, SceneManager* sceneManager)
{
	this->totalLife = totalLife;
	currentLife = totalLife;
	this->sceneManager = sceneManager;
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
}