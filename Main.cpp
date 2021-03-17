#include "DXUT.h"
#include "Main.h"
#include "IngameScene.h"
Main::Main()
{
}

Main::~Main()
{
}

void Main::Init()
{
	IMAGE->AddImage("Line","./image/Line.png");
	IMAGE->AddImage("FlashEnemy", "./image/FlashEnemy.png");
	IMAGE->AddImage("SpeedEnemy","./image/SpeedEnemy.png");
	IMAGE->AddImage("BigEnemy", "./image/BigEnemy.png");
	IMAGE->AddImage("Player","./image/Player.png");
	IMAGE->AddImage("BackG","./image/BackG.png");
	IMAGE->AddImage("Boss1", "./image/Boss1.png");
	IMAGE->AddImage("Boss", "./image/Boss.png");
	
		IMAGE->AddImage("AssaultboatC", "./image/AssaultboatC.png");

	SCENE->AddScene("IngameScene", new IngameScene);
	SCENE->ChangeScene("IngameScene");
}

void Main::Update()
{
	OBJ->Update();
	SCENE->Update();
}

void Main::Render()
{
	IMAGE->Begin();
	SCENE->Render();
	OBJ->Render();
	IMAGE->End();
}

void Main::Release()
{
	ImageManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	SceneManager::ReleaseInstance();
}

void Main::ResetDevice()
{
	IMAGE->ResetDevice();
}

void Main::LostDevice()
{
	IMAGE->LostDevice();
}
