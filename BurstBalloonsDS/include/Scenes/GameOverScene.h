#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "../GameManager.h"

class GameOverScene: public Scene
{
public:
	GameOverScene(OamEngine* mainEngine, OamEngine* subEngine, GameManager* gameManager);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	GameManager* gameManager;

	Entity* pressAnyKeyText[4];
	Entity* gameOverText[4];
};