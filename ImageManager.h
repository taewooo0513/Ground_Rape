#pragma once
#include "singleton.h"
class Texture
{
public:
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;
public:
	Texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
	:texturePtr(texturePtr),info(info)
	{
	}
	~Texture() 
	{
		SAFE_DELETE(texturePtr);
	}
};
class ImageManager : public singleton<ImageManager>
{
private:
	map<string, Texture *> mTexture;
	LPD3DXSPRITE sprite;
	LPD3DXFONT font;
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;
public:
	ImageManager();
	~ImageManager();
public:
	void Begin();
	void End();
	void LostDevice();
	void ResetDevice();
	Texture * AddImage(const string Key, const string &path);
	Texture * FindImage(const string key);
	void Render(Texture * text, Vec2 pos, Vec2 Size = Vec2{1,1},float rot=0);
	void CenterRender(Texture * text, Vec2 pos, Vec2 Size = Vec2{1,1},float rot= 0);
	void TextDrawn(string str, Vec2 pos, float size, bool Center, D3DCOLOR color);
};

#define IMAGE ImageManager::Getinstance()