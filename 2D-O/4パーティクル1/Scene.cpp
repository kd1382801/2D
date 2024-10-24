#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	//行列をセット
	SHADER.m_spriteShader.SetMatrix(matrix);

	//描画
	//SHADER.m_spriteShader.DrawTex(&charaTex, Math::Rectangle{ 0,0,64,64 }, 1.0f);

	Math::Rectangle srcRect{ 0,0,64,64 };			//テクスチャ座標
	Math::Color color = { 1.0f,1.0f,1.0f,1.0f };	//色RGBA
	SHADER.m_spriteShader.DrawTex(&charaTex, 0, 0, &srcRect, &color);

	//パーティクル
	for (int i = 0; i < smokeNum; i++) {
		smoke[i].Draw();
	}




	//文字列はテクスチャなどを描画した後に書くこと
	// 文字列表示
	SHADER.m_spriteShader.DrawString(230, 350, "パーティクル１", Math::Vector4(0, 0, 0, 1));
	SHADER.m_spriteShader.DrawString(230+8, 350-5, "パーティクル１", Math::Vector4(1, 1, 0, frame / 180.0f));


}

void Scene::Update()
{
	//座標更新
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		playerX += 8;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		playerX -= 8;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		playerY += 8;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		playerY -= 8;
	}
	
	//行列の作成
	matrix = Math::Matrix::CreateTranslation(playerX, playerY, 0);

	//zキーで緑のパーティクルを発生
	if (GetAsyncKeyState('Z') & 0x8000) {
		for (int i = 0; i < smokeNum; i++) {
			smoke[i].Emit(
				{ playerX,playerY },
				{ Rnd() * 6 - 3,Rnd() * 6 - 3 },
				Rnd() * 3 + 2,
				{ 0,1,0,0.2f },
				1000,
				false
			);
		}
	}
	
	//xキーで緑のパーティクルをリピート
	if (GetAsyncKeyState('X') & 0x8000) {
		for (int i = 0; i < smokeNum; i++) {
			//リピート再生の場合は初回のEmitの値はほとんど0でok
			smoke[i].Emit(
				{ 0,0 },
				{ 0,0 },
				0,
				{ 0,0,0,0 },
				0,
				true
			);
		}
	}


	//パーティクル
	for (int i = 0; i < smokeNum; i++) {
		smoke[i].Update();
	}

	//フレーム数を増やす
	frame++;

}

void Scene::Init()
{
	//乱数の初期化
	srand(timeGetTime());

	// 画像の読み込み処理
	charaTex.Load("Texture/smile_transparent.png");
	particleTex.Load("Texture/smoke_transparent.png");

	for (int i = 0; i < smokeNum; i++) {
		smoke[i].SetTexture(&particleTex);
	}

	//座標の初期化
	playerX = 0;
	playerY = 0;

	//パーティクル
	for (int i = 0; i < smokeNum; i++) {
		smoke[i].Init();
	}

	frame = 0;
}

void Scene::Release()
{
	// 画像の解放処理
	charaTex.Release();
	particleTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}

float Scene::Rnd()
{
	return rand() / (float)RAND_MAX;
}
