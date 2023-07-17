#pragma once
#include "Scenes/SceneManager.h"

class GameManager
{
public:
	GameManager(int totalLife, SceneManager* sceneManager, float secondsToReachMaxDifficult);
	void AddToScore(int value);
	int GetScore();
	int GetHighScore();

	int GetCurrentLife();
	void RemoveLife();
	void ResetGameplayData();
	float GetDifficultFactor();
private:
	int score;
	int highScore;

	int totalLife;
	int currentLife;
	
	float gameplayStartTime;
	float secondsToReachMaxDifficult;

	SceneManager* sceneManager;
};