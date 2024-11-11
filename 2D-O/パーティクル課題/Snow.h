#pragma once
#include "ParticleBase.h"

class Snow : public ParticleBase {
public:
	Snow();
	~Snow();

	void Init();
	void Update();
	void Draw();

private:

};
