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

	// �����ݒ�
	void Init();

	// ���
	void Release();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw2D();

	// GUI����
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
