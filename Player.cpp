#include "DXUT.h"
#include "Player.h"

Player::Player(Vec2 Pos)
	:Pos(Pos)
{
	OBJ->player = this;
	Back = IMAGE->FindImage("BackG");
	text = IMAGE->FindImage("Player");
	for (int i = 0; i <= WINSIZEY; i++)
	{
		for (int j = 0; j <= WINSIZEX; j++)
		{
			if (i == 0 || i == WINSIZEY || j == 0 || j == WINSIZEX)
			{
				Map[i][j] = 2;
			}
		}
	}
}

Player::~Player()
{
}

void Player::PlayerLineMove()
{
	if (DXUTIsKeyDown(VK_LEFT))
	{
		if (Pos.x != 0 && Map[int(Pos.y)][int(Pos.x) == 2])
		{
			if (Map[int(Pos.y)][int(Pos.x - 1)] == 2)
			{
				Pos.x -= 1;
			}
		}
		else if (Map[int(Pos.y)][int(Pos.x - 1)] == 0)
		{
			if (DXUTWasKeyPressed(VK_SPACE))
			{
				Pos.x -= 1;

				LineDrawStart = true;
				Dir = ELeft;
			}
		}
	}
	else if (DXUTIsKeyDown(VK_UP))
	{
		if (Pos.y != 0 && Map[int(Pos.y)][int(Pos.x) == 2])
		{
			if (Map[int(Pos.y - 1)][int(Pos.x)] == 2)
			{
				Pos.y--;
			}
			else if (Map[int(Pos.y - 1)][int(Pos.x)] == 0)
			{
				if (DXUTWasKeyPressed(VK_SPACE))
				{
					Pos.y--;
					LineDrawStart = true;
					Dir = EUp;
				}
			}
		}
	}
	else if (DXUTIsKeyDown(VK_DOWN))
	{
		if (Pos.y != WINSIZEY && Map[int(Pos.y)][int(Pos.x) == 2])
		{
			if (Map[int(Pos.y + 1)][int(Pos.x)] == 2)
			{
				Pos.y++;
			}
			else if (Map[int(Pos.y + 1)][int(Pos.x)] == 0)
			{
				if (DXUTWasKeyPressed(VK_SPACE))
				{
					Pos.y++;
					LineDrawStart = true;
					Dir = EDown;
				}
			}
		}
	}
	else if (DXUTIsKeyDown(VK_RIGHT))
	{
		if (Pos.x != WINSIZEX && Map[int(Pos.y)][int(Pos.x) == 2])
		{
			if (Map[int(Pos.y)][int(Pos.x + 1)] == 2)
			{
				Pos.x++;
			}
			else if (Map[int(Pos.y)][int(Pos.x + 1)] == 0)
			{
				if (DXUTWasKeyPressed(VK_SPACE))
				{
					Pos.x++;
					LineDrawStart = true;
					Dir = ERight;
				}
			}
		}
	}
}
void Player::PlayerDrawLine()
{
	switch (Dir)
	{
	case ELeft:
		if (Map[int(Pos.y)][int(Pos.x)] == 0)
		{
			Map[int(Pos.y)][int(Pos.x)] = 2;

			Pos.x--;
			if (DXUTWasKeyPressed(VK_UP))
			{
				Dir = EUp;
			}
			else if (DXUTWasKeyPressed(VK_DOWN))
			{
				Dir = EDown;
			}
		}
		else if (Map[int(Pos.y)][int(Pos.x)] == 2)
		{
			LineDrawStart = false;
			FloodFill(OBJ->Boss1->Pos);
			ChangeTile();

			D3DLOCKED_RECT rt;

			Back->texturePtr->LockRect(0, &rt, 0, D3DLOCK_DISCARD);
			DWORD* TextureColor = (DWORD*)rt.pBits;
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					if (Map[i][j] != 0)
					{
						int nIdx = i * Back->info.Width + j;
						D3DXCOLOR TargetPixel = TextureColor[nIdx];
						TargetPixel.a = 0;
						TextureColor[nIdx] = TargetPixel;
					}

				}
			}
			Back->texturePtr->UnlockRect(0);
			return;
		}
		break;
	case ERight:
		if (Map[int(Pos.y)][int(Pos.x)] == 0)
		{
			Map[int(Pos.y)][int(Pos.x)] = 2;
			Pos.x++;
			if (DXUTWasKeyPressed(VK_UP))
			{
				Dir = EUp;
			}
			else if (DXUTWasKeyPressed(VK_DOWN))
			{
				Dir = EDown;
			}
		}
		else if (Map[int(Pos.y)][int(Pos.x)] == 2)
		{
			LineDrawStart = false;
			FloodFill(OBJ->Boss1->Pos);
			ChangeTile();

			D3DLOCKED_RECT rt;
			Back->texturePtr->LockRect(0, &rt, 0, D3DLOCK_DISCARD);
			DWORD* TextureColor = (DWORD*)rt.pBits;
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					if (Map[i][j] != 0)
					{
						int nIdx = i * Back->info.Width + j;
						D3DXCOLOR TargetPixel = TextureColor[nIdx];
						TargetPixel.a = 0;
						TextureColor[nIdx] = TargetPixel;
					}

				}
			}
			Back->texturePtr->UnlockRect(0);
			return;
		}
		break;
	case EUp:
		if (Map[int(Pos.y)][int(Pos.x)] == 0)
		{
			Map[int(Pos.y)][int(Pos.x)] = 2;

			Pos.y--;
			if (DXUTWasKeyPressed(VK_LEFT))
			{
				Dir = ELeft;
			}
			else if (DXUTWasKeyPressed(VK_RIGHT))
			{
				Dir = ERight;
			}

		}
		else if (Map[int(Pos.y)][int(Pos.x)] == 2)
		{
			LineDrawStart = false;
			FloodFill(OBJ->Boss1->Pos);
			ChangeTile();
			D3DLOCKED_RECT rt;
			Back->texturePtr->LockRect(0, &rt, 0, D3DLOCK_DISCARD);
			DWORD* TextureColor = (DWORD*)rt.pBits;
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					if (Map[i][j] != 0)
					{
						int nIdx = i * Back->info.Width + j;
						D3DXCOLOR TargetPixel = TextureColor[nIdx];
						TargetPixel.a = 0;
						TextureColor[nIdx] = TargetPixel;
					}

				}
			}
			Back->texturePtr->UnlockRect(0);
			return;
		}
		break;
	case EDown:
		if (Map[int(Pos.y)][int(Pos.x)] == 0)
		{
			Map[int(Pos.y)][int(Pos.x)] = 2;

			Pos.y++;
			if (DXUTWasKeyPressed(VK_LEFT))
			{
				Dir = ELeft;
			}
			else if (DXUTWasKeyPressed(VK_RIGHT))
			{
				Dir = ERight;
			}
		}
		else if (Map[int(Pos.y)][int(Pos.x)] == 2)
		{
			LineDrawStart = false;
			FloodFill(OBJ->Boss1->Pos);
			ChangeTile();

			D3DLOCKED_RECT rt;
			Back->texturePtr->LockRect(0, &rt, 0, D3DLOCK_DISCARD);
			DWORD* TextureColor = (DWORD*)rt.pBits;
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					if (Map[i][j] != 0)
					{
						int nIdx = i * Back->info.Width + j;
						D3DXCOLOR TargetPixel = TextureColor[nIdx];
						TargetPixel.a = 0;
						TextureColor[nIdx] = TargetPixel;
					}

				}
			}
			Back->texturePtr->UnlockRect(0);
			return;
		}
		break;
	}
	/*D3DLOCKED_RECT rt;
	Back->texturePtr->LockRect(0, &rt, 0, D3DLOCK_DISCARD);
	DWORD* TextureColor = (DWORD*)rt.pBits;
	int nIdx = Pos.y * Back->info.Width + Pos.x;
	D3DXCOLOR TargetPixel = TextureColor[nIdx];
	TargetPixel.a = 0;
	TextureColor[nIdx] = TargetPixel;
	Back->texturePtr->UnlockRect(0);*/
}

void Player::Update()
{
	if (LineDrawStart == false)
	{
		PlayerLineMove();
	}
	else if (LineDrawStart == true)
	{
		PlayerDrawLine();
	}
}

void Player::Render()
{
	IMAGE->Render(Back, Vec2(0, 0), Vec2(1, 1));

	IMAGE->CenterRender(text, Vec2(Pos), Vec2(1, 1));
}

void Player::Collion(Object* obj)
{
}

void Player::FloodFill(Vec2 Pos)
{
	if (Map[int(Pos.y)][int(Pos.x)] == 0)
	{
		Map[int(Pos.y)][int(Pos.x)] = 3;
		FloodFill(Vec2(Pos.x - 1, Pos.y));
		FloodFill(Vec2(Pos.x + 1, Pos.y));
		FloodFill(Vec2(Pos.x, Pos.y - 1));
		FloodFill(Vec2(Pos.x, Pos.y + 1));
	}
}

void Player::ChangeTile()
{
	for (int i = 0; i < WINSIZEY; i++)
	{
		for (int j = 0; j < WINSIZEX; j++)
		{
			if (Map[i][j] == 0)
			{
				Map[i][j] = 1;
			}
			if (Map[i][j] == 3)
			{
				Map[i][j] = 0;
			}
		}
	}
}
