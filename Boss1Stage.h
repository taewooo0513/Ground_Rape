#pragma once
#include "Object.h"
class Boss1Stage : public Object
{
private:
	Texture* text;
public:
	Boss1Stage(Vec2 pos);
	~Boss1Stage();
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void Collion(Object* obj) override;
	Vec2 Pos;
};

