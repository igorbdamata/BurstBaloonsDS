#include "Scenes/SceneManager.h"

const char* SceneManager::GetCurrentScene()
{
	return currentScene;
}
void SceneManager::AddScene(const char* sceneName, Scene* scene)
{
	scenes.insert(std::make_pair(sceneName, scene));
}

void SceneManager::ChangeSceneTo(const char* newScene)
{
	this->currentScene = newScene;
	scenes[newScene]->Load();
}