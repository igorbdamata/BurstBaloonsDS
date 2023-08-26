#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "../GameManager.h"
#include "../CodedAnimations/MenuIdleCodedAnimation.h"
#include "../Data/GeneralTitleData.h"

class EndOfLevelScene : public Scene
{
public:
	EndOfLevelScene(GraphicsHandler* topGraphicsHandler, GraphicsHandler* bottomGraphicsHandler, SceneManager* sceneManager, int sfxToPlayOnLoad, std::string titlePrefix, const void* backgroundTiles, uint32 backgroundTilesLen, Vector2* titleCenteredPosition, const void* titleTiles[GeneralTitleData::TITLES_COUNT]);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	SceneManager* sceneManager;
	MenuIdleCodedAnimation* idleCodedAnimation;

	int sfxToPlayOnLoad;
};