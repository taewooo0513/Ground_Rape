#pragma once
class BossTail
{
public:
	Vec2 Pos=Vec2(0,0);
public:
	int i = 0;
	int Num;
	Vec2 Speed;
	vector<Vec2>ListPos;
	CDXUTTimer* timer;
	int fd = 0;
	vector <Vec2> NextPos;
	vector<Vec2> OldPos;
	Texture* text;
	Vec2 Dir;
	BossTail* head = nullptr;
	bool Del = false;
	BossTail(Vec2 Pos, int Num);
	~BossTail();
	void UpdatePos(vector<Vec2> pos);
	void Render(); vector<Vec2> vpos;
	void Update();
};

