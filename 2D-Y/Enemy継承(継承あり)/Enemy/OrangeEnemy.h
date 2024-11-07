#pragma once
#include "EnemyBase.h"

class C_OrangeEnemy : public C_EnemyBase{
public:

	C_OrangeEnemy(){}
	~C_OrangeEnemy(){}

	void Init() override;
	void Draw() override;

	void SetTex(KdTexture* eTex) { m_eTex = eTex; }

private:

	const float MovePow = 5.0f;
};