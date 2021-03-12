#pragma once
#include <iostream>
#include <random>
#include <math.h>
#include <map>
#include <list>
#include <string>

using namespace std;

const static int WINSIZEX = 1920;
const static int WINSIZEY = 1080;

#define Device DXUTGetD3D9Device()
#define Vec2 D3DXVECTOR2
#define Vec3 D3DXVECTOR3
#include "ImageManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"