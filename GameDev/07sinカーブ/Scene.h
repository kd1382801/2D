#pragma once

struct Object
{
	float x;
	float y;
	float angle;	//sin‚É“n‚·Šp“x
	float alpha;	//“§–¾“x
	float size;		//Šg‘å—¦
	Math::Matrix mat;
};

class Scene
{
private:
	KdTexture playerTex;	//‰æ‘œ‚Í\‘¢‘Ì‚ÉŠÜ‚ß‚È‚¢
	KdTexture enemyTex;
	KdTexture charaTex;

	Object player;
	Object enemy;
	Object chara;


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
