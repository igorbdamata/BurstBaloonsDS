#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "../Balloon.h"
#include "../GameManager.h"
#include "../Data/GameplayData.h"

class GameplayScene : public Scene
{
public:
	GameplayScene(GraphicsHandler* topGraphicsHandler, GraphicsHandler* bottomGraphicsHandler, GameManager* gameManager);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	Balloon* balloons[GameplayData::BALLOONS_COUNT];
	Entity* lifeIcons[GameplayData::TOTAL_LIFE];
	GameManager* gameManager;

	Vector2 vector2TouchPosition = Vector2(0, 0);

	void UpdateTouchPosition();
	void BurstTouchedBalloons();

	void UpdateBalloons();
	void UpdateHUD();
};