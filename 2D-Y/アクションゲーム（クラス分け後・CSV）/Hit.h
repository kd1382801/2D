#pragma once
#include "CharaBase.h"

class Scene;//�O���錾

class C_Hit {
public:

	C_Hit():m_hOwner(nullptr){}
	~C_Hit(){}

	void Enemy_Player(int num);

	//�}�b�v�Ƃ̋�`�����蔻��p
	void MapRectHit(C_CharaBase* base);

	void SetOwner(Scene* hOwner) { m_hOwner = hOwner; }

private:

	Scene* m_hOwner;

};