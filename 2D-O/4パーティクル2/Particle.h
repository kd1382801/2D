#pragma once

class Particle
{
public:
	Particle();
	~Particle();

	//煙用
	void InitSmoke();
	void UpdateSmoke(Math::Vector2 a_playerPos,bool a_bPlayerMove);
	void DrawSmoke();
	
	//炎用
	void InitFire();
	void UpdateFire(Math::Vector2 a_playerPos,bool a_bPlayerMove);
	void DrawFire();

	void SetTexture(KdTexture* a_pTexture);

	float Rnd();//0.0~1.0fの乱数を求める

	//パーティクル発生・放出処理
	void Emit(Math::Vector2 a_pos, Math::Vector2 a_move, float a_size, Math::Color a_color, int a_lifespan, bool a_bRepeat);

private:
	Math::Vector2	m_pos;
	Math::Vector2	m_move;
	Math::Matrix	m_matrix;
	Math::Color		m_color;
	KdTexture*		m_pTexture;
	float	m_size;
	int		m_lifespan;
	bool	m_bRepeat;
};
