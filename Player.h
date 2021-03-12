#pragma once
#include "Object.h"
class Player : public Object
{
private:
	enum Direction
	{
		ELeft,
		ERight,
		EUp,
		EDown
	};
	Texture* Back;
	Vec2 Pos;
	Texture* text;
	bool LineDrawStart = false;
	int Dir = 5;
public:
	int Map[WINSIZEY+1][WINSIZEX+1] = {0};
	Player(Vec2 Pos);
	~Player();
public:
	void PlayerLineMove();
	void PlayerDrawLine();
	// Object을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void Collion(Object* obj) override;

	void FloodFill(Vec2 Pos);
	void ChangeTile();
};

