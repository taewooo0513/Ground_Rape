#include "DXUT.h"
#include "Boss1Stage.h"

Boss1Stage::Boss1Stage(Vec2 pos)
	:Pos(pos)
{
	text = IMAGE->FindImage("Boss1");
	OBJ->Boss1 = this;
}

Boss1Stage::~Boss1Stage()
{
}

void Boss1Stage::Update()
{
}

void Boss1Stage::Render()
{
	IMAGE->CenterRender(text,Pos,Vec2(1,1));
}

void Boss1Stage::Collion(Object* obj)
{
}
