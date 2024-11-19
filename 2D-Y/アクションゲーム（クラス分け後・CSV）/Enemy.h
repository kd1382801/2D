#pragma once
#include "CharaBase.h"

class C_Enemy : public C_CharaBase{
public:

	C_Enemy() {}
	~C_Enemy() {}

	void Init();
	void Action();
	void Update(float scrollX);
	void Draw();

	void SetPos(Math::Vector2 pos) { m_pos = pos; }

	Math::Vector2 GetPos() override { return m_pos; }
	Math::Vector2 GetFuturePos() override { return m_pos + m_move; }
	float GetRadius() override { return 32.0f; }

private:
	

};