#pragma once
#include "ParticleBase.h"

class KiraKira : public ParticleBase {
public:

	KiraKira();
	~KiraKira();

	void Init();
	void Update(Math::Vector2 aPos);
	void Draw();



private:

	float rote;//‰ñ“]Šp“x
	Math::Matrix roteMat;

};