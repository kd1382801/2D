#pragma once

class Scene;//�O���錾

class C_Hit {
public:

	C_Hit():m_hOwner(nullptr){}
	~C_Hit(){}

	void Map_Player();
	void Map_Enemy();
	void Enemy_Player();

	void SetOwner(Scene* hOwner) { m_hOwner = hOwner; }

private:

	Scene* m_hOwner;

};