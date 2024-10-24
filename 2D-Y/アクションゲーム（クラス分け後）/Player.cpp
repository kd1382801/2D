#include "Player.h"
#include "Scene.h"

void C_Player::Init()
{
	m_pos = { 0,0 };
	m_move = { 0,0 };
	m_alive = true;
	m_scaleX = 1.0f;
	m_jump = false;

	C_Map* map = m_pOwner->GetMap();
	m_scrollX = 0.0f;
	m_scrollMin = map->GetPos(0, 0).x + 640;
	m_scrollMax = map->GetPos(0, map->GetWidth() - 1).x - 640;
}

void C_Player::Action()
{
	if (!m_alive)return;
	
	m_move.x = 0;
	m_move.y -= Gravity;

	//左右キーで移動
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		m_move.x -= MovePower;
		m_scaleX = -1.0f;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		m_move.x += MovePower;
		m_scaleX = 1.0f;
	}

	//ジャンプ
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		if (!m_jump) {
			m_jump = true;
			m_move.y = JumpPower;
		}
	}

}

void C_Player::Update()
{
	//座標確定処理
	m_pos += m_move;

	//スクロール
	m_scrollX = m_pos.x;
	if (m_scrollX < m_scrollMin)m_scrollX = m_scrollMin;
	if (m_scrollX > m_scrollMax)m_scrollX = m_scrollMax;

	m_transMat = Math::Matrix::CreateTranslation(m_pos.x - m_scrollX, m_pos.y, 0);
	m_scaleMat = Math::Matrix::CreateScale(m_scaleX, 1.0f, 1.0f);
	m_mat = m_scaleMat * m_transMat;
}

void C_Player::Draw()
{
	if (!m_alive)return;

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_pTex, Math::Rectangle{ 0,0,64,64 },1.0f);
}

void C_Player::MapHitX(float posX, float moveX)
{
	m_pos.x = posX;
	m_move.x = moveX;
}

void C_Player::MapHitY(float posY, float moveY, bool jump)
{
	m_pos.y = posY;
	m_move.y = moveY;
	m_jump = jump;
}
