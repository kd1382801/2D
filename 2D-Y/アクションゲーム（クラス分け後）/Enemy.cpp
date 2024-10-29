#include "Enemy.h"

void C_Enemy::Init()
{
	m_pos = { 200,300 };
	m_move = { MovePower,0 };
	m_scaleX = 1.0f;
	m_alive = true;
	m_moveCount = 60;
}

void C_Enemy::Action()
{
	if (!m_alive)return;

	m_move.y -= Gravity;

	m_moveCount--;
	if (m_moveCount <= 0) {
		m_moveCount = 60;
		m_move.x *= -1;
		m_scaleX *= -1;
	}
}
void C_Enemy::Update(float scrollX)
{
	//À•WŠm’èˆ—
	m_pos += m_move;

	m_transMat = Math::Matrix::CreateTranslation(m_pos.x - scrollX, m_pos.y, 0);
	m_scaleMat = Math::Matrix::CreateScale(m_scaleX, 1.0f, 1.0f);
	m_mat = m_scaleMat * m_transMat;
}

void C_Enemy::Draw()
{
	if (!m_alive)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex_Color(m_eTex, Math::Rectangle{ 0,0,64,64 }, Math::Color{ 1,0,0,1.0f });
}

void C_Enemy::MapHitX(float posX, float moveX)
{
	m_pos.x = posX;
	m_move.x = moveX;
}

void C_Enemy::MapHitY(float posY, float moveY)
{
	m_pos.y = posY;
	m_move.y = moveY;
}
