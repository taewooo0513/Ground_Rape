#pragma once
#include "Object.h"
class SpeedEnemy : public Object
{
private:
	Vec2 Dir = Vec2(0,0);
	Texture * text;
	Vec2 Pos;
public:
	SpeedEnemy();
	~SpeedEnemy();
	virtual void Update() override;
	virtual void Render() override;
	virtual void Collion(Object * obj) override;
};

