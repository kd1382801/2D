#pragma once
#include "Particle.h"

class Scene
{
private:

	//パーティクル用
	static const int smokeNum = 50;
	Particle smoke[smokeNum];
	KdTexture particleTex;

	float playerX;
	float playerY;
	bool bPlayerMove;//自機が動いたかのフラグ

	//フレーム数
	int frame;

	// テクスチャ ・・・ 画像データ
	KdTexture charaTex;

	// 行列 ・・・ 座標などの情報
	Math::Matrix matrix;

public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// GUI処理
	void ImGuiUpdate();

	//0.0~1.0の乱数
	float Rnd();

private:

	Scene() {}

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
