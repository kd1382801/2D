#pragma once

class C_OrangeEnemy {
public:

	C_OrangeEnemy(){}
	~C_OrangeEnemy(){}

	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* eTex) { m_eTex = eTex; }

private:

	const float MovePow = 5.0f;

	KdTexture* m_eTex;
	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Vector2 m_scale;
	Math::Matrix m_scaleMat;
	Math::Matrix m_transMat;
	Math::Matrix m_mat;

};