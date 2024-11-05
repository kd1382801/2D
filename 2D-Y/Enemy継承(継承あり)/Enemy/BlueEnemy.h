#pragma once
#include "EnemyBase.h"

class C_BlueEnemy : public C_EnemyBase {
public:

	C_BlueEnemy() {}
	~C_BlueEnemy() {}

	void Init();
	void Draw();

	void SetTex(KdTexture* eTex) { m_eTex = eTex; }

private:

	const float MovePow = 3.0f;

};