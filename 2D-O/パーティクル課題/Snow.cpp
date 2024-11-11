#include "Snow.h"

Snow::Snow()
{
}

Snow::~Snow()
{
}

void Snow::Init()
{
	color = { 0,0,0,0 };
}

void Snow::Update()
{
	lifespan--;
	if (lifespan <= 0) {
		if (!repeat)return;
		Emit(
			{ Rnd() * 1280 - 640,360 + 32 },//pos
			{ Rnd(),-2},			//move
			Rnd() * 0.25f,					//size
			{ 1,1,1,0.5f },					//color
			Rnd() * 180 + 200,		//lifespan
			true					//repeat
		);
	}

	size *= 0.996f;//サイズ変更
	

	pos += move;

	transMat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
	scaleMat = Math::Matrix::CreateScale(size, size, 0);
	mat = scaleMat * transMat;
}

void Snow::Draw()
{
	Math::Rectangle rect = { 0,0,64,64 };

	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(tex, 0, 0, &rect, &color);
}
