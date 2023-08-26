#pragma once
#if !defined(GAME_MANAGER_H)
#define GAME_MANAGER_H true

#include "Scenes/SceneManager.h"

class GameManager
{
public:
	GameManager(SceneManager* sceneManager);

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

	int currentLife;

	float gameplayStartSeconds;

	SceneManager* sceneManager;

	void OnRunOutOfLives();
};

#endif