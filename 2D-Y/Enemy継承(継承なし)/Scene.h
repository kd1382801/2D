#pragma once
#include "Enemy/OrangeEnemy.h"
#include "Enemy/BlueEnemy.h"
#include "Enemy/GreenEnemy.h"

class Scene
{
private:

	KdTexture m_enemyTex;

	C_OrangeEnemy m_orange;
	C_BlueEnemy m_blue;
	C_GreenEnemy m_green;
	

public:

	// ‰Šúİ’è
	void Init();

	// ‰ğ•ú
	void Release();

	// XVˆ—
	void Update();

	// •`‰æˆ—
	void Draw2D();

	// GUIˆ—
	void ImGuiUpdate();

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
