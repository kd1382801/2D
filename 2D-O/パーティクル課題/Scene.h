#pragma once
#include "Bubble.h"
#include "Snow.h"
#include "KiraKira.h"
#include "Tornado.h"

class Scene
{
private:
	bool moveFlg;
	Math::Vector2 playerPos;
	Math::Vector2 playerMove;
	Math::Matrix playerMat;
	KdTexture playerTex;

	//星用
	float rad;
	bool starFlg;
	Math::Vector2 starPos;
	Math::Matrix transMat;
	Math::Matrix scaleMat;
	Math::Matrix mat;
	KdTexture starTex;
	

	static const int bubbleNum = 80;
	Bubble bubble[bubbleNum];
	KdTexture bubbleTex;

	static const int snowNum = 150;
	Snow snow[snowNum];
	KdTexture snowTex;

	static const int kiraNum = 150;
	KiraKira kira[kiraNum];

	static const int tornadoNum = 300;
	Tornado tornado[tornadoNum];
	KdTexture tornadoTex;


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

	//星
	void StarInit();
	void StarUpdate();
	void StarDraw();

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
