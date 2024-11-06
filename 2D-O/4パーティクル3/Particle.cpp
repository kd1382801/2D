#include "Particle.h"

Particle::Particle() :
	//メンバ・イニシャライザ
	m_pos(0, 0), 
	m_move(0, 0), 
	m_matrix(), 
	m_color(1, 1, 1, 1), 
	m_pTexture(nullptr),
	m_size(1), 
	m_lifespan(0), 
	m_bRepeat(false)
{
}

Particle::~Particle()
{
}

void Particle::InitSmoke()
{

	m_move = { Rnd() * 2 - 1 ,Rnd() * 2 - 1 };
	m_size = 0;
	m_color = { 0, 0, 0, 0 };

}

void Particle::UpdateSmoke(Math::Vector2 a_playerPos,bool a_bPlayerMove)
{
	//有効期間
	m_lifespan--;
	if (m_lifespan <= 0) {
		//繰り返しをしない場合(false)は戻る
		if (!m_bRepeat)return;

		//繰り返しをする場合(true)の場合
		//自機が動いたとき
		if (a_bPlayerMove) {
			//パーティクルを再度発生させる
			Emit(
				{ a_playerPos.x,a_playerPos.y - 32 },
				{ Rnd() * 3 - 1.5f,Rnd() * 0.5f },
				Rnd() * 0.7f + 0.7f,
				{ 1,1,1,0.2f },
				Rnd() * 35 + 10,
				true
			);
		}
	}

	//サイズ変更
	m_size *= 0.98f;

	//座席更新
	m_pos += m_move;
	
	//行列作成
	Math::Matrix scaleMat = Math::Matrix::CreateScale(m_size, m_size, 0);
	Math::Matrix transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_matrix = scaleMat * transMat;
}

void Particle::DrawSmoke()
{
	SHADER.m_spriteShader.SetMatrix(m_matrix);

	Math::Rectangle srcRect = { 0,0,32,32 };
	SHADER.m_spriteShader.DrawTex(m_pTexture, 0, 0, &srcRect, &m_color);
}

void Particle::InitFire()
{
	m_color = { 0,0,0,0 };
}

void Particle::UpdateFire(Math::Vector2 a_playerPos, bool a_bPlayerMove)
{
	//有効期間
	m_lifespan--;
	if (m_lifespan <= 0) {
		//繰り返しをしない場合(false)は戻る
		if (!m_bRepeat)return;

		//繰り返しをする場合(true)の場合
		////自機が動いたとき
		//if (a_bPlayerMove) {
			//パーティクルを再度発生させる
			Emit(
				{ a_playerPos.x,a_playerPos.y - 32 },
				{ Rnd() * 2 - 1,4 },
				Rnd() * 4 - 2,
				{ 1,Rnd(),0.2f,0.3f },
				Rnd() * 35 + 10,
				true
			);
		//}
	}

	//サイズ変更
	m_size *= 0.98f;//減らす
	//m_size *= 1.10f;//増やす

	//座席更新
	m_pos += m_move;

	//行列作成
	Math::Matrix scaleMat = Math::Matrix::CreateScale(m_size, m_size, 0);
	Math::Matrix transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_matrix = scaleMat * transMat;
}

void Particle::DrawFire()
{
	SHADER.m_spriteShader.SetMatrix(m_matrix);

	Math::Rectangle srcRect = { 0,0,32,32 };
	SHADER.m_spriteShader.DrawTex(m_pTexture, 0, 0, &srcRect, &m_color);
}

void Particle::InitLight()
{
	m_color = { 0,0,0,0 };
}

void Particle::UpdateLight(Math::Vector2 a_playerPos, bool a_bPlayerMove)
{
	//有効期間
	m_lifespan--;
	if (m_lifespan <= 0) {
		//繰り返しをしない場合(false)は戻る
		if (!m_bRepeat)return;

		//繰り返しをする場合(true)の場合
		////自機が動いたとき
		//if (a_bPlayerMove) {
			//パーティクルを再度発生させる
		Emit(
			{ a_playerPos.x,a_playerPos.y},
			{ Rnd() * 4 - 2,Rnd() * 4 - 2 },
			5,
			{ Rnd()+0.3f,1,Rnd() + 0.3f,0.3f },
			Rnd() * 45 + 10,
			true
		);
		//}
	}

	//サイズ変更
	m_size *= 0.8f;//減らす
	//m_size *= 1.10f;//増やす

	//座席更新
	m_pos += m_move;

	//行列作成
	Math::Matrix scaleMat = Math::Matrix::CreateScale(m_size, m_size, 0);
	Math::Matrix transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_matrix = scaleMat * transMat;
}

void Particle::DrawLight()
{
	SHADER.m_spriteShader.SetMatrix(m_matrix);

	Math::Rectangle srcRect = { 0,0,32,32 };
	SHADER.m_spriteShader.DrawTex(m_pTexture, 0, 0, &srcRect, &m_color);
}

void Particle::SetTexture(KdTexture* a_pTexture)
{
	m_pTexture = a_pTexture;
}

float Particle::Rnd()
{
	return rand() / (float)RAND_MAX;
}

void Particle::Emit(Math::Vector2 a_pos, Math::Vector2 a_move, float a_size, Math::Color a_color, int a_lifespan, bool a_bRepeat)
{
	m_pos = a_pos;
	m_move = a_move;
	m_size = a_size;
	m_color = a_color;
	m_lifespan = a_lifespan;
	m_bRepeat = a_bRepeat;
}
