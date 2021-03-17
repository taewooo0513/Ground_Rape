#pragma once
#include "Object.h"
#include "BossTail.h"
class Boss1Stage : public Object
{
private:
	Vec2 ToDir = Vec2(0,0);
	Vec2 Speed = Vec2(0,0);
	Boss1Stage * obj; int a;
	Vec2 Dir = Vec2(0,0);
	int i = 0;
	vector<Vec2> ListPos;
	CDXUTTimer* timer;
	Vec2 NextPos[5] = { Vec2(0,0), Vec2(0,0), Vec2(0,0), Vec2(0,0), Vec2(0,0) };
	Texture* text;
public:
	int fd = 0;
	float radian = 0;
	vector<BossTail*> vTail;
	BossTail * tail;
	Boss1Stage(Vec2 pos, int num);
	~Boss1Stage();
	INT V = 0;
	void NumDel(int num);

	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void Collion(Object* obj) override;
	Vec2 Pos;
};

