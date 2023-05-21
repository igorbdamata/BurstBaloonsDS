#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "../GameManager.h"

class GameOverScene: public Scene
{
public:
	GameOverScene(OamEngine* mainEngine, OamEngine* subEngine, SceneManager* sceneManager);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	SceneManager* sceneManager;

	Entity* pressAnyKeyText[4];
	Entity* gameOverText[4];
};