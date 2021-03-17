#pragma once
#include "Object.h"
class Player : public Object
{
private:
	Texture* Line;
	enum Direction
	{
		ELeft,
		ERight,
		EUp,
		EDown
	};
	int Speed = 1;
	Texture* Back;
	Texture* text;
	int Dir = 5;
public:
	bool LineDrawStart = false;
	int Map[WINSIZEY+1][WINSIZEX+1] = {0};
	Vec2 Pos;
	Player(Vec2 Pos);
	~Player();
public:
	void PlayerLineMove();
	void PlayerDrawLine();
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void Collion(Object* obj) override;
	Vec2 SEXPos;

	void FloodFill(Vec2 Pos);
	void ChangeTile();
	int C(int i, int j);
	void DelLine(int i, int j);
	bool Coll(int i, int j,int Size);
	bool Check(int i, int j, int num,int Num);
	Vec2 ososososos() { return SEXPos; };
};

