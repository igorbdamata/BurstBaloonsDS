#include "Scenes/SceneManager.h"

Scene* SceneManager::GetCurrentScene()
{
	return scenes[currentScene];
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