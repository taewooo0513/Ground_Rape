#pragma once
#include "singleton.h"
#include "Object.h"
#include "Boss1Stage.h"
#include "Player.h"
class ObjectManager : public singleton<ObjectManager>
{
public:
	enum Tag
	{
		Begin,
		Play,
		ENEMY,
		End
	};
	list<Object*> objlist[10];
	ObjectManager();
	~ObjectManager();
public:
	Object * AddObject(Object * obj,int Tag);
	void Update();
	void Render();
	void Release();

	Player* player;
	Boss1Stage* Boss1;
};

#define OBJ ObjectManager::Getinstance()