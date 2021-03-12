#include "DXUT.h"
#include "ImageManager.h"

ImageManager::ImageManager()
{
	D3DXCreateSprite(Device,&sprite);
}

ImageManager::~ImageManager()
{
	sprite->Release();
	for (auto iter : mTexture)
	{
		iter.second->texturePtr->Release();
	}
	mTexture.clear();
}

void ImageManager::Begin()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void ImageManager::End()
{
	sprite->End();
}

void ImageManager::LostDevice()
{
	sprite->OnLostDevice();
}

void ImageManager::ResetDevice()
{
	sprite->OnResetDevice();
}

Texture * ImageManager::AddImage(const string Key, const string &path)
{
	auto find = mTexture.find(Key);
	if (find == mTexture.end())
	{
	
		if (D3DXCreateTextureFromFileExA(Device, path.c_str(), -2, -2, 0, 0, D3DFMT_A8B8G8R8, D3DPOOL_MANAGED, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			Texture * text = new Texture(texturePtr,info);
			mTexture[Key] = text;
			return text;
		}
		return nullptr;
	}
	return find->second;
}

Texture * ImageManager::FindImage(const string key)
{
	auto find = mTexture.find(key);
	if (find != mTexture.end())
	{
		return find->second;
	}
	return nullptr;
}

void ImageManager::Render(Texture * text, Vec2 pos, Vec2 Size, float rot)
{
	if (text != nullptr)
	{
		D3DXMATRIXA16 mat;
		D3DXMatrixTransformation2D(&mat,nullptr,0,&Size,nullptr,rot,&pos);
		sprite->SetTransform(&mat);
		sprite->Draw(text->texturePtr, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255,255,255));
	}
}

void ImageManager::CenterRender(Texture * text, Vec2 pos, Vec2 Size, float rot)
{
	Render(text,Vec2(pos.x-(text->info.Width*Size.x)/2,pos.y-(text->info.Height*Size.y)/2),Size,rot);
}

void ImageManager::TextDrawn(string str, Vec2 pos, float size, bool Center, D3DCOLOR color)
{
	D3DXMATRIXA16 mat;
	if (!Center)
	{
		D3DXCreateFontA(Device, size, 0, 10, 1, FALSE, DEFAULT_CHARSET, 0, 0, 0, "Comic Sans Ms", &font);
		D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);
	}
	else
	{
		D3DXCreateFontA(Device, size, 0, 0, 1, FALSE, DEFAULT_CHARSET, 0, 0, 0, "Comic Sans Ms", &font);
		D3DXMatrixTranslation(&mat, pos.x - size * (str.size() * 0.25), pos.y - size / 2.f, 0);
	}
	sprite->SetTransform(&mat);
	font->DrawTextA(sprite, str.c_str(), str.size(), nullptr, DT_NOCLIP, color);
	SAFE_RELEASE(font);
}