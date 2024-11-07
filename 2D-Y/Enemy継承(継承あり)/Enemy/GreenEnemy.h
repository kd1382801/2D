#pragma once
#include "EnemyBase.h"

class C_GreenEnemy : public C_EnemyBase{
public:

	C_GreenEnemy() {}//デフォルトコンストラクタ
	C_GreenEnemy(float move) { MovePow = move; }//引数ありのコンストラクタ
	~C_GreenEnemy() {}

	void Init();
	void Draw();

	void SetTex(KdTexture* eTex) { m_eTex = eTex; }

private:

	float MovePow = 4.0f;

};