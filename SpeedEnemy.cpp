#include "DXUT.h"
#include "SpeedEnemy.h"

SpeedEnemy::SpeedEnemy()
{
	random_device Rd;
	mt19937 Gen(Rd());
	uniform_int_distribution<int> X(1, WINSIZEX - 1);
	uniform_int_distribution<int> Y(1,WINSIZEY-1);
	text = IMAGE->FindImage("SpeedEnemy");
	Dir.x = 1;
	Dir.y = 0;
	Pos = Vec2(1800,Y(Rd));
}

SpeedEnemy::~SpeedEnemy()
{
}

void SpeedEnemy::Update()
{
	random_device Rd;
	mt19937 Gen(Rd());
	uniform_int_distribution<int> X(-1,1);

	Pos.x += Dir.x ;
	Pos.y += Dir.y ;
	if (OBJ->player->Map[int(Pos.y)][int(Pos.x)] == 1)
	{
		DieObj();
	}
	if (OBJ->player->Map[int(Pos.y - 1)][int(Pos.x)] == 2)
	{
		Dir.y = 1;
		Dir.x = X(Rd);

	}
	if (OBJ->player->Map[int(Pos.y + 1)][int(Pos.x)] == 2)
	{
		Dir.y = -1;
		Dir.x = X(Rd);

	}
	if (OBJ->player->Map[int(Pos.y)][int(Pos.x-1)] ==2)
	{
		Dir.x = 1;
		Dir.y = X(Rd);

	}
	if (OBJ->player->Map[int(Pos.y)][int(Pos.x+1)] == 2)
	{
		Dir.x= -1;

		Dir.y= X(Rd);

	}
}

void SpeedEnemy::Render()
{
	IMAGE->CenterRender(text,Pos,Vec2(0.1,0.1));
}

void SpeedEnemy::Collion(Object * obj)
{
}
