#include "DXUT.h"
#include "Boss1Stage.h"
#include "SpeedEnemy.h"
Boss1Stage::Boss1Stage(Vec2 pos, int num)
	:Pos(pos)
{
	timer = new CDXUTTimer;
	timer->Start();
	text = IMAGE->FindImage("Boss");
	a = num + 1;
	if (num == 0)
	{
		OBJ->Boss1 = this;
	}
	for (int i = 0; i < 20; i++)
	{
		vTail.push_back(new BossTail(pos, i));
	}
	Speed.x = 3;
	Speed.y = 3;

}

Boss1Stage::~Boss1Stage()
{
}

void Boss1Stage::NumDel(int num)
{
	for (auto iter = vTail.begin(); iter != vTail.end();)
	{
		{
			if ((*iter) != nullptr)
			{
				if ((*iter)->Del == true)
				{
					SAFE_DELETE(*iter);

				}
			}
			iter++;
		}
	}
}

void Boss1Stage::Update()
{
	OBJ->player->Coll(Pos.x, Pos.y, (text->info.Width * 0.3) / 2);
	if (OBJ->player->Coll(Pos.x, Pos.y, (text->info.Width * 0.3) / 2))
	{
		if (Pos.x >= 0 && Pos.x <= WINSIZEX && Pos.y >= 0 && Pos.y <= WINSIZEY)
		{
			for (int i = 0; i < (text->info.Width * 0.3); i++)
			{
				for (int j = 0; j < (text->info.Width * 0.3) / 2; j++)
				{
					Vec2 PPPP = Pos - OBJ->player->SEXPos;
					if (abs(PPPP.x)  > abs(PPPP.y))
					{
						if (PPPP.x> 0)
						{
							Speed.x = 2;
							if (timer->GetTime() > 0.1)
							{
								OBJ->AddObject(new SpeedEnemy(Pos, Vec2(-1, -1)), 0);
								timer->Reset();
							}
						}
						else if (PPPP.x <= 0)
						{
							Speed.x = -2;
							if (timer->GetTime() > 0.1)
							{

								OBJ->AddObject(new SpeedEnemy(Pos, Vec2(1, -1)), 0);
								timer->Reset();
							}
						}
					}
					else 
					{
						if (PPPP.y  > 0)
						{
							Speed.y = 2;
							if (timer->GetTime() > 0.1)
							{

								OBJ->AddObject(new SpeedEnemy(Pos, Vec2(-1, 1)), 0);
								timer->Reset();
							}
						}
						else if (PPPP.y  <= 0)
						{
							Speed.y = -2;
							if (timer->GetTime() > 0.1)
							{

								OBJ->AddObject(new SpeedEnemy(Pos, Vec2(-1, -1)), 0);
								timer->Reset();
							}

						}
					}
				}
			}
		}
	}
	if (OBJ->player->LineDrawStart == true)
	{
	ToDir =  OBJ->player->Pos- Pos ;

	D3DXVec2Normalize(&ToDir,&ToDir);
	}
	
	if (ToDir.x == 0 && ToDir.y == 0)
	{
		Pos.x +=  Speed.x;
		Pos.y +=  Speed.y;
	}
	else
	{

	Pos.x += ToDir.x * Speed.x;
	Pos.y += ToDir.y * Speed.y;
	}


	ListPos.push_back(Pos);
	for (auto iter : vTail)
	{
		if (iter != nullptr)
			iter->Update(); 
			if (fd >= 7)
			{
				if (iter == vTail[0])
				{
					iter->UpdatePos(ListPos);
					ListPos.clear();
					timer->Reset();
					fd = 0;
				}
			}
	}
		fd++;
	NumDel(0);
}

void Boss1Stage::Render()
{

	//tail->Render();
	for (auto iter : vTail)
	{
		if (iter != nullptr)
			iter->Render();
	}
	IMAGE->TextDrawn(to_string(Pos.x), Vec2(200, 200), 50, true, D3DCOLOR_XRGB(255, 255, 255));
	IMAGE->TextDrawn(to_string(Pos.y), Vec2(200, 100), 50, true, D3DCOLOR_XRGB(255, 255, 255));

	IMAGE->CenterRender(text, Pos, Vec2(0.3, 0.3));
}

void Boss1Stage::Collion(Object* obj)
{
}
