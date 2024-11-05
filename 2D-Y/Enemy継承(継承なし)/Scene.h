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
