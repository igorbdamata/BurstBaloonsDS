#pragma once

class GameManager
{
public:
	GameManager(int totalLife);
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
};