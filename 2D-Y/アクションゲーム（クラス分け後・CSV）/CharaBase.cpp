#include "CharaBase.h"

void C_CharaBase::MapHitX(float posX, float moveX)
{
	m_pos.x = posX;
	m_move.x = moveX;
}

void C_CharaBase::MapHitY(float posY, float moveY, bool jump)
{
	m_pos.y = posY;
	m_move.y = moveY;
	m_jump = jump;
}
