#pragma once
#include "particleBase.h"

class Tornado :public ParticleBase {
public:

	Tornado();
	~Tornado();

	void Init();
	void Update();
	void Draw();


private:

	float deg;
	float radius;
	Math::Matrix roteMat;

};