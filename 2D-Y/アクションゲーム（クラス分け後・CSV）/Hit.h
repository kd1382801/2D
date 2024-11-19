#pragma once
#include "CharaBase.h"

class Scene;//前方宣言

class C_Hit {
public:

	C_Hit():m_hOwner(nullptr){}
	~C_Hit(){}

	void Enemy_Player(int num);

	//マップとの矩形当たり判定用
	void MapRectHit(C_CharaBase* base);

	void SetOwner(Scene* hOwner) { m_hOwner = hOwner; }

private:

	Scene* m_hOwner;

};