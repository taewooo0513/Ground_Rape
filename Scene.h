#pragma once
class Scene abstract
{
public:
	Scene();
	~Scene();
	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};

