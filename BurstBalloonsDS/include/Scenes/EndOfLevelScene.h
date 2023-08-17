#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "../GameManager.h"
#include "../CodedAnimations/MenuIdleCodedAnimation.h"

class EndOfLevelScene : public Scene
{
public:
	EndOfLevelScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, SceneManager* sceneManager, std::string titleSuffix, int sfxToPlayOnLoad, const void* backgroundTiles, uint32 backgroundTilesLen);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	SceneManager* sceneManager;
	MenuIdleCodedAnimation* idleCodedAnimation;

	int sfxToPlayOnLoad;
};