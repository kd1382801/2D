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

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// GUI処理
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
