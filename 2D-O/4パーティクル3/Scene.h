#pragma once
#include "Particle.h"

class Scene
{
private:

	//���p�[�e�B�N���p
	static const int smokeNum = 50;
	Particle smoke[smokeNum];
	KdTexture particleTex;

	//���p�[�e�B�N���p
	static const int fireNum = 100;
	Particle fire[fireNum];
	//KdTexture particleTex;	//���Ɠ����摜���g���̂ŕs�v

	//���p�[�e�B�N���p
	static const int lightNum = 80;
	Particle light[lightNum];
	KdTexture circleTex;

	float playerX;
	float playerY;
	bool bPlayerMove;//���@�����������̃t���O

	//�t���[����
	int frame;

	// �e�N�X�`�� �E�E�E �摜�f�[�^
	KdTexture charaTex;

	// �s�� �E�E�E ���W�Ȃǂ̏��
	Math::Matrix matrix;

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

	//0.0~1.0�̗���
	float Rnd();

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
