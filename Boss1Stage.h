#pragma once
#include "Object.h"
class Boss1Stage : public Object
{
private:
	Texture* text;
public:
	Boss1Stage(Vec2 pos);
	~Boss1Stage();
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void Collion(Object* obj) override;
	Vec2 Pos;
};

