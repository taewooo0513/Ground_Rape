#include "DXUT.h"
#include "IngameScene.h"
#include "Boss1Stage.h"
#include "Player.h"
#include "BigEnemy.h"
#include "SpeedEnemy.h"
IngameScene::IngameScene()
{
}

IngameScene::~IngameScene()
{
}

void IngameScene::Init()
{
	OBJ->AddObject(new BigEnemy,1);
	OBJ->AddObject(new Boss1Stage(Vec2(WINSIZEX/2,500 )),1);
	OBJ->AddObject(new Player(Vec2(WINSIZEX/2,0)),0);
	OBJ->AddObject(new SpeedEnemy,1);
	OBJ->AddObject(new SpeedEnemy, 1);
	OBJ->AddObject(new SpeedEnemy, 1);

}

void IngameScene::Update()
{
}

void IngameScene::Render()
{
}

void IngameScene::Release()
{
}

