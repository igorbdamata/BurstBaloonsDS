#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "..\Balloon.h"
#include "..\GameManager.h"
#include "..\Data.h"

class GameplayScene : public Scene
{
public:
	GameplayScene(OamEngine* mainEngine, OamEngine* subEngine, GameManager* gameManager);

	void Load() override;

	void InputLoop() override;
	void GameLoop() override;
private:
	Balloon* balloons[BALLOONS_COUNT];
	Entity* balloonsUI[3];
	GameManager* gameManager;

	touchPosition touch;
	Vector2 touchVector2 = Vector2(0, 0);
};