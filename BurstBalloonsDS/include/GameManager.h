#pragma once
#include "Scenes/SceneManager.h"

class GameManager
{
public:
	GameManager(int totalLife, SceneManager* sceneManager);
	void AddToScore(int value);
	int GetScore();

	int GetCurrentLife();
	void RemoveLife();
	void Restart();
private:
	int score;
	int highScore;

	int totalLife;
	int currentLife;

	SceneManager* sceneManager;
};