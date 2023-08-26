#pragma once
#if !defined(SCENE_MANAGER_H)
#define SCENE_MANAGER_H true

#include <map>
#include "Scene.h"

class SceneManager
{
public:
	void AddScene(const char* sceneName, Scene* scene);
	void ChangeSceneTo(const char* newScene);
	Scene* GetCurrentScene();
	Scene* GetScene(const char* scene);
private:
	std::map<const char*, Scene*> scenes;
	const char* currentScene;
};

#endif