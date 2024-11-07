#pragma once

class C_EnemyBase {
public:

	C_EnemyBase(){}
	~C_EnemyBase(){}

	virtual void Init() = 0;//�������z�֐�(�I�[�o�[���C�h�����O��̊֐�)
	void Update();
	virtual void Draw();//���z�֐�

protected:

	KdTexture* m_eTex;
	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	Math::Vector2 m_scale;
	Math::Matrix m_scaleMat;
	Math::Matrix m_transMat;
	Math::Matrix m_mat;

};