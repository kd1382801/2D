#pragma once
#include "Enemy/EnemyBase.h"
#include "Enemy/OrangeEnemy.h"
#include "Enemy/BlueEnemy.h"
#include "Enemy/GreenEnemy.h"

class Scene
{
private:

	KdTexture m_enemyTex;

	C_OrangeEnemy m_orange;
	C_BlueEnemy	  m_blue;
	//C_GreenEnemy  m_green;	//デフォルトコンストラクタを実行
	C_GreenEnemy  m_green{1};	//引数ありのコンストラクタを実行
	
	C_EnemyBase* m_base;//基底クラスのポインタ
	//C_EnemyBase m_jBase; ←抽象クラスだからインスタンス化ができない

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
