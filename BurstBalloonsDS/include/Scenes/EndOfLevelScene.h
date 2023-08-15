#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "../GameManager.h"

class EndOfLevelScene : public Scene
{
public:
	EndOfLevelScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager, std::string titleSuffix, int sfxToPlayOnLoad, const void* backgroundTiles, uint32 backgroundTilesLen);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	SceneManager* sceneManager;

	Entity* pressAnyKeyText[4];
	Entity* titleText[4];
	int sfxToPlayOnLoad;
};