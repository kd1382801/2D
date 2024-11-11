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

	//¯—p
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

	// ‰Šúİ’è
	void Init();

	// ‰ğ•ú
	void Release();

	// XVˆ—
	void Update();

	// •`‰æˆ—
	void Draw2D();

	// GUIˆ—
	void ImGuiUpdate();

	//¯
	void StarInit();
	void StarUpdate();
	void StarDraw();

	//0.0~1.0‚Ì—”
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
