#pragma once
#include "Object.h"
class BigEnemy : public Object
{
private:
	Vec2 Pos;
	Vec2 Dir = Vec2(0, 0);
	Texture* text;
	CDXUTTimer* timer;
public:
	BigEnemy();
	~BigEnemy();


	// Object을(를) 통해 상속됨
	virtual void Update() override;

	virtual void Render() override;

	virtual void Collion(Object* obj) override;

};

