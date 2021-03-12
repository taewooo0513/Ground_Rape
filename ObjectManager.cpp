#include "DXUT.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

Object * ObjectManager::AddObject(Object * obj, int Tag)
{
	if (obj == nullptr)
	{
		return nullptr;
	}
	objlist[Tag].push_back(obj );
	return obj;
}

void ObjectManager::Update()
{
	for (int i = 0; i < End; i++)
	{
		for (auto iter = objlist[i].begin(); iter != objlist[i].end();)
		{
			(*iter)->Update();
			if ((*iter)->ObjectLive() == false)
			{

				SAFE_DELETE((*iter));
				iter = objlist[i].erase(iter);
			}
			else iter++;
		}
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < End; i++)
	{
		for (auto iter : objlist[i])
		{
			iter->Render();
		}
	}
}

void ObjectManager::Release()
{
}
