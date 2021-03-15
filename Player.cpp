#include "DXUT.h"
#include "Player.h"

Player::Player(Vec2 Pos)
	:Pos(Pos)
{
	Line = IMAGE->FindImage("Line");

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
	D3DLOCKED_RECT rtrt;
	Line->texturePtr->LockRect(0, &rtrt, 0, D3DLOCK_DISCARD);
	DWORD* TextureColor = (DWORD*)rtrt.pBits;
	for (int i = 0; i < WINSIZEY; i++)
	{
		for (int j = 0; j < WINSIZEX; j++)
		{
			int nIdx = i * Back->info.Width + j;
			D3DXCOLOR TargetPixel = TextureColor[nIdx];
			TargetPixel.a = 0;
			TextureColor[nIdx] = TargetPixel;

		}
	}
	Line->texturePtr->UnlockRect(0);
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
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					int s = 0;
					int f = 0;
					if (Map[i][j] == 2)
					{
						if (i == 0 || i == WINSIZEY || j == 0 || j == WINSIZEX)
						{
							s++;
						}
						else
						{
							if (Map[i - 1][j] == 2 && Map[i][j + 1] == 2)
							{
								s = 3;
							}
							if (Map[i + 1][j] == 2 && Map[i][j + 1] == 2)
							{
								s = 3;

							}
							if (Map[i - 1][j] == 2 && Map[i][j - 1] == 2)
							{
								s = 3;

							}
							if (Map[i + 1][j] == 2 && Map[i][j - 1] == 2)
							{
								s = 3;

							}
						}
						if (i != WINSIZEY)
						{
							if (Map[i + 1][j] == 1)
							{
								s++;
							}
						}
						if (j != WINSIZEX)
						{
							if (Map[i][j + 1] == 1)
							{
								s++;
							}
						}
						if (i != 0)
						{
							if (Map[i - 1][j] == 1)
							{
								s++;
							}
						}
						if (j != 0)
						{
							if (Map[i][j - 1] == 1)
							{
								s++;
							}
						}
						if (s == 2)
						{
							Map[i][j] = 5;
						}
					}
				}
			}
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					if (Map[i][j] == 5)
					{
						Map[i][j] = 1;

						DelLine(i, j);
					}
				}
			}
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
			D3DLOCKED_RECT rtrt9;
			Line->texturePtr->LockRect(0, &rtrt9, 0, D3DLOCK_DISCARD);

			DWORD* TextureColor9 = (DWORD*)rtrt9.pBits;
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					int nIdx = i * Line->info.Width + j;

					if (Map[i][j] == 1)
					{
						D3DXCOLOR TargetPixel9 = TextureColor9[nIdx];
						TargetPixel9.a = 1;
						TextureColor9[nIdx] = TargetPixel9;
					}

				}
			}
			Line->texturePtr->UnlockRect(0);
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
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					int s = 0;
					if (Map[i][j] == 2)
					{
						if (i == 0 || i == WINSIZEY || j == 0 || j == WINSIZEX)
						{
							s++;
						}
						else
						{
							if (Map[i - 1][j] == 2 && Map[i][j + 1] == 2)
							{
								s = 3;
							}
							if (Map[i + 1][j] == 2 && Map[i][j + 1] == 2)
							{
								s = 3;

							}
							if (Map[i - 1][j] == 2 && Map[i][j - 1] == 2)
							{
								s = 3;

							}
							if (Map[i + 1][j] == 2 && Map[i][j - 1] == 2)
							{
								s = 3;

							}
						}
						if (i != WINSIZEY)
						{
							if (Map[i + 1][j] == 1)
							{
								s++;
							}
						}
						if (j != WINSIZEX)
						{
							if (Map[i][j + 1] == 1)
							{
								s++;

							}
						}
						if (i != 0)
						{
							if (Map[i - 1][j] == 1)
							{
								s++;

							}
						}
						if (j != 0)
						{
							if (Map[i][j - 1] == 1)
							{
								s++;

							}
						}
						if (s == 2)
						{
							Map[i][j] = 3;
						}
					}
				}
			}
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{

					if (Map[i][j] == 3)
					{
						Map[i][j] = 1;
					}
				}
			}
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
			D3DLOCKED_RECT rtrt3;
			Line->texturePtr->LockRect(0, &rtrt3, 0, D3DLOCK_DISCARD);

			DWORD* TextureColor2 = (DWORD*)rtrt3.pBits;
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					int nIdx = i * Line->info.Width + j;

					if (Map[i][j] == 1)
					{
						D3DXCOLOR TargetPixel1 = TextureColor2[nIdx];
						TargetPixel1.a = 1;
						TextureColor2[nIdx] = TargetPixel1;
					}

				}
			}
			Line->texturePtr->UnlockRect(0);
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
			D3DLOCKED_RECT rt; for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					int s = 0;
					if (Map[i][j] == 2)
					{
						if (i == 0 || i == WINSIZEY || j == 0 || j == WINSIZEX)
						{
							s++;
						}
						else
						{
							if (Map[i - 1][j] == 2 && Map[i][j + 1] == 2)
							{
								s = 3;
							}
							if (Map[i + 1][j] == 2 && Map[i][j + 1] == 2)
							{
								s = 3;

							}
							if (Map[i - 1][j] == 2 && Map[i][j - 1] == 2)
							{
								s = 3;

							}
							if (Map[i + 1][j] == 2 && Map[i][j - 1] == 2)
							{
								s = 3;

							}
						}
						if (i != WINSIZEY)
						{
							if (Map[i + 1][j] == 1)
							{
								s++;
							}
						}
						if (j != WINSIZEX)
						{
							if (Map[i][j + 1] == 1)
							{
								s++;

							}
						}
						if (i != 0)
						{
							if (Map[i - 1][j] == 1)
							{
								s++;

							}
						}
						if (j != 0)
						{
							if (Map[i][j - 1] == 1)
							{
								s++;

							}
						}
						if (s == 2)
						{
							Map[i][j] = 3;
						}
					}
				}
			}
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{

					if (Map[i][j] == 3)
					{
						Map[i][j] = 1;
					}
				}
			}
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
					int a = 0;

				}
			}
			Back->texturePtr->UnlockRect(0);
			D3DLOCKED_RECT rtrt5;
			Line->texturePtr->LockRect(0, &rtrt5, 0, D3DLOCK_DISCARD);

			DWORD* TextureColor5 = (DWORD*)rtrt5.pBits;
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					int nIdx = i * Line->info.Width + j;

					if (Map[i][j] == 1)
					{
						D3DXCOLOR TargetPixel5 = TextureColor5[nIdx];
						TargetPixel5.a = 1;
						TextureColor5[nIdx] = TargetPixel5;
					}

				}
			}
			Line->texturePtr->UnlockRect(0);
			D3DLOCKED_RECT rtrt8;
			Line->texturePtr->LockRect(0, &rtrt8, 0, D3DLOCK_DISCARD);

			DWORD* TextureColor8 = (DWORD*)rtrt8.pBits;
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					int nIdx = i * Line->info.Width + j;

					if (Map[i][j] == 1)
					{
						D3DXCOLOR TargetPixel8 = TextureColor8[nIdx];
						TargetPixel8.a = 1;
						TextureColor8[nIdx] = TargetPixel8;
					}

				}
			}
			Line->texturePtr->UnlockRect(0);
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
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					int s = 0;
					if (Map[i][j] == 2)
					{
						if (i == 0 || i == WINSIZEY || j == 0 || j == WINSIZEX)
						{
							s++;
						}
						else
						{
							if (Map[i - 1][j] == 2 && Map[i][j + 1] == 2)
							{
								s = 3;
							}
							if (Map[i + 1][j] == 2 && Map[i][j + 1] == 2)
							{
								s = 3;

							}
							if (Map[i - 1][j] == 2 && Map[i][j - 1] == 2)
							{
								s = 3;

							}
							if (Map[i + 1][j] == 2 && Map[i][j - 1] == 2)
							{
								s = 3;

							}
						}
						if (i != WINSIZEY)
						{
							if (Map[i + 1][j] == 1)
							{
								s++;
							}
						}
						if (j != WINSIZEX)
						{
							if (Map[i][j + 1] == 1)
							{
								s++;

							}
						}
						if (i != 0)
						{
							if (Map[i - 1][j] == 1)
							{
								s++;

							}
						}
						if (j != 0)
						{
							if (Map[i][j - 1] == 1)
							{
								s++;

							}
						}
						if (s == 2)
						{
							Map[i][j] = 3;
						}
					}
				}
			}
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{

					if (Map[i][j] == 3)
					{
						Map[i][j] = 1;
					}
				}
			}
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
			D3DLOCKED_RECT rtrt6;
			Line->texturePtr->LockRect(0, &rtrt6, 0, D3DLOCK_DISCARD);

			DWORD* TextureColor6 = (DWORD*)rtrt6.pBits;
			for (int i = 0; i < WINSIZEY; i++)
			{
				for (int j = 0; j < WINSIZEX; j++)
				{
					int nIdx = i * Line->info.Width + j;

					if (Map[i][j] == 1)
					{
						D3DXCOLOR TargetPixel6 = TextureColor6[nIdx];
						TargetPixel6.a = 1;
						TextureColor6[nIdx] = TargetPixel6;
					}

				}
			}
			Line->texturePtr->UnlockRect(0);

			return;
		}
		break;
	}
	D3DLOCKED_RECT rt;
	Back->texturePtr->LockRect(0, &rt, 0, D3DLOCK_DISCARD);
	DWORD* TextureColor = (DWORD*)rt.pBits;
	int nIdx = Pos.y * Back->info.Width + Pos.x;
	D3DXCOLOR TargetPixel = TextureColor[nIdx];
	TargetPixel.a = 0;
	TextureColor[nIdx] = TargetPixel;
	Back->texturePtr->UnlockRect(0);
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
	IMAGE->Render(Line, Vec2(0, 0));
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

int Player::C(int i, int j)
{
	int a = 0;
	if (i != 0 && j != 0)
	{
		if (Map[i - 1][j] == 2)
		{
			a++;
		}
		if (Map[i + 1][j] == 2)
		{
			a++;
		}
		if (Map[i][j - 1] == 2)
		{
			a++;
		}
		if (Map[i][j + 1] == 2)
		{
			a++;
		}
	}
	return a;
}

void Player::DelLine(int i, int j)
{
	int c = 0;
	if (i != 0 && j != 0 && i != WINSIZEY && j != WINSIZEX)
	{
		if (Map[i][j - 1] == 1)
		{
			c++;
		}
		if (Map[i][j + 1] == 1)
		{
			c++;
		}
		if (Map[i - 1][j] == 1)
		{
			c++;
		}
		if (Map[i + 1][j] == 1)
		{
			c++;
		}
		if (c == 4)
		{
			Map[i][j] = 1;
		}
	}
}

bool Player::Coll(int i , int j ,int Size)
{
	float s;

	for (int jj = 0; jj < WINSIZEY; jj++)
	{
		for (int ii = 0; ii < WINSIZEX; ii++)
		{
			if (Map[jj][ii] == 2)
			{
				s = sqrt((ii - i) * (ii - i) + (jj - j) * (jj - j));

				if (s <Size)
				{
					return true;
				}
			}
		}
	}
	cout << s <<"\n";

	return false;
}
