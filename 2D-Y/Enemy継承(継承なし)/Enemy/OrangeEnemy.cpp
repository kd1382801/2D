#include "OrangeEnemy.h"

void C_OrangeEnemy::Init()
{
	m_pos = { -600,-200 };
	m_move = { MovePow,0 };
	m_scale = { 2,2 };
}

void C_OrangeEnemy::Update()
{
	m_pos += m_move;

	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_OrangeEnemy::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex_Color(m_eTex, Math::Rectangle{ 0,0,64,64 }, Math::Color{ 1,0.5f,0,1 });
}
