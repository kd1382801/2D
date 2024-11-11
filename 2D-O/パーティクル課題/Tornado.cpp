#include "Tornado.h"

Tornado::Tornado()
{
}

Tornado::~Tornado()
{
}

void Tornado::Init()
{
	pos = { 0,-360 };
	move = { 0,0 };
	deg = 0;
	radius = 5;
	color = { 0,0,0,0 };
}

void Tornado::Update()
{
	lifespan--;
	if (lifespan <= 0 || pos.y > 370) {
		if (!repeat)return;
		Emit(
			{ 0,-365 },//pos
			{ 0,2.5f },	//move
			1,		//size
			{ 0.2f,0.2f,1,1 },	//color
			400,	//lifespan
			true		//repeat
		);
		radius = Rnd()*3+5;
		deg = Rnd() * 360;
	}
	

	deg+=10;
	radius+=0.7f;
	pos.x = cos(DirectX::XMConvertToRadians(deg)) * radius;

	pos += move;

	transMat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
	roteMat = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(deg));
	scaleMat = Math::Matrix::CreateScale(size, size, 0);
	mat = scaleMat * roteMat * transMat;
}

void Tornado::Draw()
{
	Math::Rectangle rect = { 0,0,64,64 };

	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(tex, 0, 0, &rect, &color);
}
