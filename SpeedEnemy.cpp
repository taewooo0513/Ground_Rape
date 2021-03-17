#include "DXUT.h"
#include "SpeedEnemy.h"

SpeedEnemy::SpeedEnemy(Vec2 Pos ,Vec2 Dir )
	:Pos(Pos),Dir(Dir)
{
	int Speed = 3;

	random_device Rd;
	mt19937 Gen(Rd());
	uniform_int_distribution<int> X(1, WINSIZEX - 1);
	uniform_int_distribution<int> Y(1, WINSIZEY - 1);
	text = IMAGE->FindImage("SpeedEnemy");

}

SpeedEnemy::~SpeedEnemy()
{
}

void SpeedEnemy::Update()
{
	random_device Rd;
	mt19937 Gen(Rd());
	uniform_int_distribution<int> X(-1, 1);
	if (Pos.x - Speed > 0)
	{
		int a = 0;
		for (int i = 1; i < Speed; i++)
		{
			if (OBJ->player->Map[int(Pos.y)][int(Pos.x - i)] == 2)
			{
				a++;
			}
			else if (OBJ->player->Map[int(Pos.y)][int(Pos.x - i)] != 2)
			{
				break;
			}
		}
		Pos.x -= a;
	}
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
