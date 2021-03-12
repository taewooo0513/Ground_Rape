#include "DXUT.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	Release();
}

Scene * SceneManager::AddScene(string key, Scene * scene)
{
	if (!scene)
		return nullptr;
	if (m_scene.find(key) != m_scene.end())
		return nullptr;
	m_scene[key] = scene;
	return scene;
}

void SceneManager::ChangeScene(string key)
{
	auto find = m_scene.find(key);
	if (find == m_scene.end())
		return;
	NextScene = find->second;
}

void SceneManager::Update()
{
	if (NextScene)
	{
		if (NowScene)
		{
			NowScene->Release();
		}
		NowScene = NextScene;
		NextScene = nullptr;
		NowScene->Init();
	}
	if (NowScene)
	{
		NowScene->Update();
	}
}

void SceneManager::Render()
{
	if (NowScene)
		NowScene->Render();
}

void SceneManager::Release()
{
	if (NowScene)
	{
		NowScene->Release();
	}
	for (auto iter : m_scene)
	{
		SAFE_DELETE(iter.second);
	}
	m_scene.clear();
}
