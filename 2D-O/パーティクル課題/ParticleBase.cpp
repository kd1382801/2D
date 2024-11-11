#include "ParticleBase.h"

ParticleBase::ParticleBase():
	//メンバ・イニシャライザ
	size(1),
	lifespan(10),
	repeat(false),
	tex(nullptr),
	pos(0, 0),
	move(0, 0),
	color(0, 0, 0, 0),
	transMat(),
	scaleMat(),
	mat()
{
}

ParticleBase::~ParticleBase()
{
}

void ParticleBase::Init()
{
	return;
}

void ParticleBase::Update()
{
	return;
}

void ParticleBase::Draw()
{
	return;
}

void ParticleBase::SetTex(KdTexture* aTex)
{
	tex = aTex;
}

float ParticleBase::Rnd()
{
	return rand() / (float)RAND_MAX;
}

void ParticleBase::Emit(Math::Vector2 aPos, Math::Vector2 aMove, float aSize, Math::Color aColor, int aLifespan, bool aRepeat)
{
	pos = aPos;
	move = aMove;
	size = aSize;
	color = aColor;
	lifespan = aLifespan;
	repeat = aRepeat;
}

void ParticleBase::Stop()
{
	Emit(
		{ 0,0 },		//pos
		{ 0,0 },		//move
		0,				//size
		{ 0,0,0,0 },	//color
		0,				//lifespan
		false			//repeat
	);
}
