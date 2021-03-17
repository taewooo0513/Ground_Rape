#pragma once
#include "Object.h"
class SpeedEnemy : public Object
{
private:
	Vec2 Dir = Vec2(0,0);
	Texture * text;
	int Speed = 0;
	Vec2 Pos;
public:
	SpeedEnemy(Vec2 Pos, Vec2 Dir);
	~SpeedEnemy();
	virtual void Update() override;
	virtual void Render() override;
	virtual void Collion(Object * obj) override;
};

