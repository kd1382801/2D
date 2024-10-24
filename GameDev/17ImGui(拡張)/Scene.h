#pragma once

enum ColorGroup {
	GroupA,
	GroupB,
	GroupC,
	GroupD,
	GroupE,
	GroupMax
};

struct Object {
	float x;
	float y;
	float moveX;
	float moveY;
	Math::Matrix mat;
	ColorGroup colorGroup;	//自分が何色(どのグループ)なのか?
};


class Scene
{
private:

	KdTexture backTex;
	KdTexture sunTex;

	//太陽
	static const int SUN_MAX = 700;
	Object sun[SUN_MAX];
	int sunNum;	//現在　更新・描画されている太陽の数

	//背景
	Math::Matrix backMat;

	//ブレンドモード切替
	bool addFlg;

	//色
	Math::Color color[GroupMax];	//5色

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
