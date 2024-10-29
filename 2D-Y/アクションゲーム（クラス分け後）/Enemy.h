#pragma once

class C_Enemy {
public:

	C_Enemy() {}
	~C_Enemy() {}

	void Init();
	void Action();
	void Update(float scrollX);
	void Draw();

	void MapHitX(float posX, float moveX);
	void MapHitY(float posY, float moveY);

	void SetTex(KdTexture* tex) { m_eTex = tex; }

	Math::Vector2 GetPos() { return m_pos; }
	Math::Vector2 GetFuturePos() { return m_pos + m_move; }
	float GetRadius() { return 32.0f; }

private:

	const float Gravity = 1.0f;		//�d��
	const float MovePower = 5.0f;	//�ړ���

	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	KdTexture* m_eTex;
	Math::Matrix m_mat;
	Math::Matrix m_transMat;
	Math::Matrix m_scaleMat;

	bool m_alive;	//�����t���O
	float m_scaleX;	//�g�嗦
	int m_moveCount;//���]�̃J�E���g
};