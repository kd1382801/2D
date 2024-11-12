#pragma once
#include "CharaBase.h"

class Scene;//前方宣言

class C_Player : public C_CharaBase {
public:

	C_Player(){}
	~C_Player(){}

	void Init();
	void Action();
	void Update();
	void Draw();

	
	void SetOwner(Scene* pOwner) { m_pOwner = pOwner; }
	void SetAlive(bool alive) { m_alive = alive; }

	Math::Vector2 GetPos() override { return m_pos; }
	Math::Vector2 GetFuturePos() override { return m_pos + m_move; }
	float GetRadius() override { return 32.0f; }
	float GetScrollX() { return m_scrollX; }

private:

	Scene* m_pOwner;
	//スクロール
	float m_scrollX;
	float m_scrollMax;
	float m_scrollMin;

};