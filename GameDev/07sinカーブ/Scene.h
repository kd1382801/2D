#pragma once

struct Object
{
	float x;
	float y;
	float angle;	//sin�ɓn���p�x
	float alpha;	//�����x
	float size;		//�g�嗦
	Math::Matrix mat;
};

class Scene
{
private:
	KdTexture playerTex;	//�摜�͍\���̂Ɋ܂߂Ȃ�
	KdTexture enemyTex;
	KdTexture charaTex;

	Object player;
	Object enemy;
	Object chara;


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
