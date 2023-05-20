#include "GameManager.h"

GameManager::GameManager(int totalLife)
{
    this->totalLife = totalLife;
    currentLife=totalLife;
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
}

void GameManager::Restart()
{
    currentLife=totalLife;
}