#include "GreenEnemy.h"

void C_GreenEnemy::Init()
{
	m_pos = { -600,200 };
	m_move = { MovePow,0 };
	m_scale = { 1,3 };
}

void C_GreenEnemy::Update()
{
	m_pos += m_move;

	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_GreenEnemy::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex_Color(m_eTex, Math::Rectangle{ 0,0,64,64 }, Math::Color{ 0,1,0,1 });
}
