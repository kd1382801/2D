#include "EnemyBase.h"

void C_EnemyBase::Init()
{
	return;
}

void C_EnemyBase::Update()
{
	m_pos += m_move;

	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_scaleMat = Math::Matrix::CreateScale(m_scale.x, m_scale.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void C_EnemyBase::Draw()
{
	return;
}
