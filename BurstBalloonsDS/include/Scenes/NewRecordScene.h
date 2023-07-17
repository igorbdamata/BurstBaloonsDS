#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "../GameManager.h"

class NewRecordScene: public Scene
{
public:
	NewRecordScene(OamEngine* mainEngine, OamEngine* subEngine, SceneManager* sceneManager);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	SceneManager* sceneManager;

	Entity* pressAnyKeyText[4];
	Entity* passRecordText[4];
};