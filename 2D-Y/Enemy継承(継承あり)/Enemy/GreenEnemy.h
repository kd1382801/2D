#pragma once
#include "EnemyBase.h"

class C_GreenEnemy : public C_EnemyBase{
public:

	C_GreenEnemy() {}//�f�t�H���g�R���X�g���N�^
	C_GreenEnemy(float move) { MovePow = move; }//��������̃R���X�g���N�^
	~C_GreenEnemy() {}

	void Init();
	void Draw();

	void SetTex(KdTexture* eTex) { m_eTex = eTex; }

private:

	float MovePow = 4.0f;

};