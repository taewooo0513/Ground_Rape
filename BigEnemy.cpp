#include "DXUT.h"
#include "BigEnemy.h"

BigEnemy::BigEnemy()
{
	timer = new CDXUTTimer;
	timer->Start();
	random_device Rd;
	mt19937 Gen(Rd());
	uniform_int_distribution<int> X(1, WINSIZEX - 1);
	uniform_int_distribution<int> Y(1, WINSIZEY - 1);
	Dir.x = (rand() % 2 - 1);
	Dir.y = (rand() % 2 - 1);
	if (Dir.x == 0 && Dir.y == 0)
	{
		Dir.x = 2;
		Dir.y = 2;
	}
	Pos = Vec2(X(Rd), Y(Rd));
	text = IMAGE->FindImage("BigEnemy");
}

BigEnemy::~BigEnemy()
{
}

void BigEnemy::Update()
{
	if (OBJ->player->Map[int(Pos.y)][int(Pos.x)] == 1)
	{
		DieObj();
	}

	OBJ->player->Coll(Pos.x,Pos.y,text->info.Width * 0.2);

}

void BigEnemy::Render()
{
	IMAGE->CenterRender(text, Vec2(500, 500), Vec2(0.2, 0.2));
}

void BigEnemy::Collion(Object* obj)
{
}
