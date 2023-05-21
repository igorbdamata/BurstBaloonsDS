#pragma once
#include "Scene.h"
#include <map>

class SceneManager
{
public:
	void AddScene(const char* sceneName, Scene* scene);
	void ChangeSceneTo(const char* newScene);
	Scene* GetCurrentScene();
private:
	std::map<const char*, Scene*> scenes;
	const char* currentScene;
};