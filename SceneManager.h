#pragma once
#include "singleton.h"
#include "Scene.h"
class SceneManager : public singleton<SceneManager>
{
private:
	map<string, Scene*> m_scene;
	Scene * NowScene = nullptr;
	Scene * NextScene = nullptr;
public:
	SceneManager();
	~SceneManager();
	Scene * AddScene(string key, Scene * scene);
	void ChangeScene(string key);
	void Update();
	void Render();
	void Release();

};

#define SCENE SceneManager::Getinstance()