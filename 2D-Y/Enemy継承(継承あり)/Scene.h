#pragma once
#include "Enemy/EnemyBase.h"
#include "Enemy/OrangeEnemy.h"
#include "Enemy/BlueEnemy.h"
#include "Enemy/GreenEnemy.h"

class Scene
{
private:

	KdTexture m_enemyTex;

	C_OrangeEnemy m_orange;
	C_BlueEnemy	  m_blue;
	//C_GreenEnemy  m_green;	//�f�t�H���g�R���X�g���N�^�����s
	C_GreenEnemy  m_green{1};	//��������̃R���X�g���N�^�����s
	
	C_EnemyBase* m_base;//���N���X�̃|�C���^
	//C_EnemyBase m_jBase; �����ۃN���X������C���X�^���X�����ł��Ȃ�

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
