#include "DXUT.h"
#include "BossTail.h"

BossTail::BossTail(Vec2 Pos, int Num)
	:Pos(Pos), Num(Num)
{
	text = IMAGE->FindImage("AssaultboatC");
	Del = false;
	timer = new CDXUTTimer;
	timer->Start();


	Speed.y = -3;

	Speed.x = 3+Num;
}

BossTail::~BossTail()
{
}

void BossTail::UpdatePos(vector<Vec2> pos)
{
	if (Num < 19 )
	{
		if(OBJ->Boss1->vTail[Num + 1] != nullptr)
		OBJ->Boss1->vTail[Num + 1]->UpdatePos(vpos);
	}
	vpos = pos;
	i = 0;
}

void BossTail::Render()
{
	if (Pos < 0)

	{
		exit(0);
	}
	if (head == nullptr)
	{
		if (vpos.size() != 0)
		{
				Pos = vpos[i];
				i++;
		}
		else
		{
		}
	}
	else
	{
		ListPos.push_back(Pos);

		if (fd >= 10)
		{
			if (head != nullptr )
			{
				if (Num < 18)
				{
					if (OBJ->Boss1->vTail[Num+1] != nullptr)
					{
						OBJ->Boss1->vTail[Num+1 ]->UpdatePos(ListPos);

						ListPos.clear();
						timer->Reset();
						fd = 0;
					}
				
				}
			}
		}
		fd++;
	}

	IMAGE->CenterRender(text, Pos, Vec2(1, 1));

}

void BossTail::Update()
{
	if (Num != 0)
	{
		if (OBJ->Boss1->vTail[Num - 1] == nullptr)
		{
			head = this;
		}
	}
	if (head != nullptr)
	{
		if (OBJ->player->Coll(Pos.x, Pos.y, (text->info.Width * 0.3) / 2))
		{
			if (Pos.x >= 0 && Pos.x <= WINSIZEX && Pos.y >= 0 && Pos.y <= WINSIZEY)
			{
				for (int i = 0; i < (text->info.Width * 0.3); i++)
				{
					for (int j = 0; j < (text->info.Width * 0.3) / 2; j++)
					{
						Vec2 PPPP = Pos - OBJ->player->SEXPos;
						if (abs(PPPP.x) > abs(PPPP.y))
						{
							if (PPPP.x > 0)
							{
								Dir.x = 3;
								if (timer->GetTime() > 0.1)
								{
									timer->Reset();
								}
							}
							else if (PPPP.x <= 0)
							{
								Dir.x = -3;
								if (timer->GetTime() > 0.1)
								{

									timer->Reset();
								}
							}
						}
						else
						{
							if (PPPP.y > 0)
							{
								Dir.y = 3;
								if (timer->GetTime() > 0.1)
								{

									timer->Reset();
								}
							}
							else if (PPPP.y <= 0)
							{
								Dir.y = -3;
								if (timer->GetTime() > 0.1)
								{

									timer->Reset();
								}

							}
						}
					}
				}
			}
		}

		Pos.x += Dir.x;
		Pos.y += Dir.y;
	}
	else
	{

	}

}

