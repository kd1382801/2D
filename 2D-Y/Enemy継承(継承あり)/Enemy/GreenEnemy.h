#pragma once
#include "EnemyBase.h"

class C_GreenEnemy : public C_EnemyBase{
public:

	C_GreenEnemy() {}
	~C_GreenEnemy() {}

	void Init();
	void Draw();

	void SetTex(KdTexture* eTex) { m_eTex = eTex; }

private:

	const float MovePow = 4.0f;

};