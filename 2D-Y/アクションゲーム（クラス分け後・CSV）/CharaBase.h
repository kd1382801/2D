#pragma once

class C_CharaBase {
public:

	C_CharaBase() {};
	~C_CharaBase() {};

	void MapHitX(float posX, float moveX);
	void MapHitY(float posY, float moveY, bool jump);

	void SetTex(KdTexture* tex) { m_tex = tex; }

	//�������z�֐�(�Q�b�^�[)
	virtual Math::Vector2 GetPos() = 0 { return m_pos; }
	virtual Math::Vector2 GetFuturePos() = 0 { return m_pos + m_move; }
	virtual float GetRadius() = 0 { return 32.0f; }

protected:

	const float Gravity = 1.0f;		//�d��
	const float JumpPower = 20.0f;	//�W�����v��
	const float MovePower = 5.0f;	//�ړ���

	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	KdTexture* m_tex;
	Math::Matrix m_mat;
	Math::Matrix m_transMat;
	Math::Matrix m_scaleMat;

	int m_moveCount;//���]�̃J�E���g
	bool m_alive;	//�����t���O
	bool m_jump;	//�W�����v�t���O
	float m_scaleX;	//�g�嗦
};