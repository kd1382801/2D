#pragma once

struct Object {
	float x;
	float y;
	float scaleX;	//�g�嗦
	float scaleY;	//�g�嗦
	Math::Matrix mat;
	Math::Matrix transMat;	//�ړ��s��
	Math::Matrix scaleMat;	//�g�k�s��
};



class Scene
{
private:

	// �e�N�X�`�� �E�E�E �摜�f�[�^
	KdTexture playerTex;
	KdTexture backTex;
	KdTexture tmpTex;	//�`���(�����_�[�^�[�Q�b�g)�؂芷���p
	KdTexture stencilTex;//�^�����摜

	Object player;
	Object back;
	Object stencil;

public:

	// �����ݒ�
	void Init();

	// ���
	void Release();

	// �X�V����
	void Update();

	//�e�N�X�`���ւ̕`�揈��
	void DynamicDraw2D();

	// �o�b�N�o�b�t�@�ւ̕`�揈��
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
