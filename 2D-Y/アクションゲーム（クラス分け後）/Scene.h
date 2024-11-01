#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Map.h"
#include "Hit.h"

class Scene
{
private:

	C_Player m_player;
	KdTexture m_playerTex;

	C_Enemy m_enemy;
	KdTexture m_enemyTex;

	C_Map m_map;
	KdTexture m_mapTex;

	C_Hit m_hit;

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

	C_Player* GetPlayer() { return &m_player; }
	C_Enemy* GetEnemy() { return &m_enemy; }
	C_Map* GetMap() { return &m_map; }

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
