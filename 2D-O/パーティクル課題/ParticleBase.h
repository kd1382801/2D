#pragma once

class ParticleBase {
public:

	ParticleBase();
	~ParticleBase();

	void Init();
	void Update();
	void Draw();

	void SetTex(KdTexture* aTex);

	float Rnd();

	//パーティクル発生・放出処理
	void Emit(Math::Vector2 aPos, Math::Vector2 aMove, float aSize, Math::Color aColor, int aLifespan, bool aRepeat);
	void Stop();

protected:

	float size;
	int lifespan;
	bool repeat;
	KdTexture* tex;
	Math::Vector2 pos;
	Math::Vector2 move;
	Math::Color color;
	Math::Matrix transMat;
	Math::Matrix scaleMat;
	Math::Matrix mat;

};