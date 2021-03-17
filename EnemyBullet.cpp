#include "DXUT.h"
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(Vec2 Pos, Vec2 Dir)
	:Pos(Pos),Dir(Dir)
{
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update()
{
	Pos -= Speed * Dir;
}

void EnemyBullet::Render()
{
}

void EnemyBullet::Collion(Object* obj)
{
}
