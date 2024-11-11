#include "Bubble.h"

Bubble::Bubble()
{
}

Bubble::~Bubble()
{
}

void Bubble::Init()
{
	color = { 0,0,0,0 };
}

void Bubble::Update()
{
	lifespan--;
	if (lifespan <= 0) {
		if (!repeat)return;
		Emit(
			{ Rnd() * 30 - 15 - 300,-300 },					//pos
			{ 0,3 },								//move
			Rnd() * 0.5f,						//size
			{ Rnd() + 0.5f,Rnd() + 0.5f,Rnd() + 0.5f,0.5f },	//color
			Rnd() * 100 + 15,						//lifespan
			true									//repeat
		);
	}

	size *= 0.98f;//サイズ変更

	pos += move;

	transMat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
	scaleMat = Math::Matrix::CreateScale(size, size, 0);
	mat = scaleMat * transMat;
}

void Bubble::Draw()
{
	Math::Rectangle rect = { 0,0,128,128 };

	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(tex, 0, 0, &rect, &color);
}


