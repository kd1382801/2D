#include "KiraKira.h"

KiraKira::KiraKira()
{
}

KiraKira::~KiraKira()
{
}

void KiraKira::Init()
{
	color = { 0,0,0,0 };
}

void KiraKira::Update(Math::Vector2 aPos)
{
	lifespan--;
	if (lifespan <= 0) {
		if (!repeat)return;
		Emit(
			{ aPos.x,aPos.y },//pos
			{ Rnd() * 3 - 1.5f,Rnd() * 3 - 1.5f },	//move
			Rnd() * 0.3f,		//size
			{ 1,1,Rnd(),1 },	//color
			Rnd() * 100,		//lifespan
			true				//repeat
		);
		rote = Rnd() * 360;
	}

	size *= 0.95f;//サイズ変更
	rote += 2.0f;

	pos += move;

	transMat = Math::Matrix::CreateTranslation(pos.x, pos.y, 0);
	scaleMat = Math::Matrix::CreateScale(size, size, 0);
	roteMat = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(rote));
	mat = roteMat * scaleMat * transMat;
}

void KiraKira::Draw()
{
	Math::Rectangle rect = { 0,0,128,128 };

	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(tex, 0, 0, &rect, &color);
}
