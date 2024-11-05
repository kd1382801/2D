#include "BlueEnemy.h"

void C_BlueEnemy::Init()
{
	m_pos = { -600,0 };
	m_move = { MovePow,0 };
	m_scale = { 3,1 };
}

void C_BlueEnemy::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex_Color(m_eTex, Math::Rectangle{ 0,0,64,64 }, Math::Color{ 0.5f,0.5f,1,1 });
}
