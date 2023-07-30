#pragma once
#include "Scenes/SceneManager.h"

class GameManager
{
public:
	GameManager(int totalLife, float secondsToReachMaxDifficult, SceneManager* sceneManager);

	void AddToScore(int value);

	int GetScore();
	int GetHighScore();

	int GetCurrentLife();
	void RemoveLife();

	float GetDifficultFactor();

	void ResetGameplayData();
private:
	int score;
	int highScore;

	int totalLife;
	int currentLife;

	float gameplayStartSeconds;
	float secondsToReachMaxDifficult;

	SceneManager* sceneManager;

	void OnRunOutOfLives();
};