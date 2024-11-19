#pragma once

class C_CharaBase {
public:

	C_CharaBase() {};
	~C_CharaBase() {};

	void MapHitX(float posX, float moveX);
	void MapHitY(float posY, float moveY, bool jump);

	void SetTex(KdTexture* tex) { m_tex = tex; }

	//純粋仮想関数(ゲッター)
	virtual Math::Vector2 GetPos() = 0 { return m_pos; }
	virtual Math::Vector2 GetFuturePos() = 0 { return m_pos + m_move; }
	virtual float GetRadius() = 0 { return 32.0f; }

protected:

	const float Gravity = 1.0f;		//重力
	const float JumpPower = 20.0f;	//ジャンプ力
	const float MovePower = 5.0f;	//移動力

	Math::Vector2 m_pos;
	Math::Vector2 m_move;
	KdTexture* m_tex;
	Math::Matrix m_mat;
	Math::Matrix m_transMat;
	Math::Matrix m_scaleMat;

	int m_moveCount;//反転のカウント
	bool m_alive;	//生存フラグ
	bool m_jump;	//ジャンプフラグ
	float m_scaleX;	//拡大率
};