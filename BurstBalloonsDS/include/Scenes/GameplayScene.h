#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "../Balloon.h"
#include "../GameManager.h"
#include "../Data/GameplayData.h"

class GameplayScene : public Scene
{
public:
	GameplayScene(GraphicsHandler* mainEngine, GraphicsHandler* subEngine, GameManager* gameManager);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	Balloon* balloons[GameplayData::BALLOONS_COUNT];
	Entity* balloonsUI[3];
	GameManager* gameManager;

	touchPosition touch;
	Vector2 touchVector2 = Vector2(0, 0);
};