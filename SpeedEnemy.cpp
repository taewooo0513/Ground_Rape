#include "DXUT.h"
#include "SpeedEnemy.h"

SpeedEnemy::SpeedEnemy()
{
	random_device Rd;
	mt19937 Gen(Rd());
	uniform_int_distribution<int> X(1, WINSIZEX - 1);
	uniform_int_distribution<int> Y(1, WINSIZEY - 1);
	text = IMAGE->FindImage("SpeedEnemy");
	Dir.x = (rand() % 2 - 1) * 2;
	Dir.y = (rand() % 2 - 1) * 2;
	if (Dir.x == 0 && Dir.y == 0)
	{
		Dir.x = 2;
		Dir.y = 2;
	}
	Pos = Vec2(X(Rd), Y(Rd));
}

SpeedEnemy::~SpeedEnemy()
{
}

void SpeedEnemy::Update()
{
	random_device Rd;
	mt19937 Gen(Rd());
	uniform_int_distribution<int> X(-1, 1);

	Pos.x += Dir.x;
	Pos.y += Dir.y;
	if (OBJ->player->Map[int(Pos.y)][int(Pos.x)] == 1)
	{
		DieObj();
	}
	if (OBJ->player->Map[int(Pos.y - 1)][int(Pos.x)] == 2)
	{
		Dir.y = 2;
		Dir.x = X(Rd);
	}
	else if (OBJ->player->Map[int(Pos.y - 2)][int(Pos.x)] == 2)
	{
		Dir.y = 2;
		Dir.x = X(Rd);
	}
	if (OBJ->player->Map[int(Pos.y + 1)][int(Pos.x)] == 2)
	{
		Dir.y = -2;
		Dir.x = X(Rd);
	}
	else if (OBJ->player->Map[int(Pos.y + 2)][int(Pos.x)] == 2)
	{
		Dir.y = -2;
		Dir.x = X(Rd);
	}
	if (OBJ->player->Map[int(Pos.y)][int(Pos.x - 1)] == 2)
	{
		Dir.x = 2;
		Dir.y = X(Rd);
	}
	else if (OBJ->player->Map[int(Pos.y)][int(Pos.x - 2)] == 2)
	{
		Dir.x = 2;
		Dir.y = X(Rd);
	}
	if (OBJ->player->Map[int(Pos.y)][int(Pos.x + 1)] == 2)
	{
		Dir.x = -2;
		Dir.y = X(Rd);
	}
	else if (OBJ->player->Map[int(Pos.y)][int(Pos.x + 2)] == 2)
	{
		Dir.x = -2;
		Dir.y = X(Rd);
	}
}

void SpeedEnemy::Render()
{
	IMAGE->CenterRender(text, Pos, Vec2(0.1, 0.1));
}

void SpeedEnemy::Collion(Object* obj)
{
}
