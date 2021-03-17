#pragma once
#include "Object.h"
class EnemyBullet : public Object
{
private :
	float Speed =1 ;
	Vec2 Pos, Dir;
public:
	EnemyBullet(Vec2 Pos , Vec2 Dir);
	~EnemyBullet();
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void Collion(Object* obj) override;
};

