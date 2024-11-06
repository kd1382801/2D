#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{


	//煙用パーティクル
	for (int i = 0; i < smokeNum; i++) {
		smoke[i].DrawSmoke();
	}

	//検証 加算合成
	D3D.SetBlendState(BlendMode::Add);

	//光用パーティクル
	for (int i = 0; i < lightNum; i++) {
		light[i].DrawLight();
	}

	D3D.SetBlendState(BlendMode::Alpha);

	SHADER.m_spriteShader.SetMatrix(matrix);

	Math::Rectangle srcRect{ 0,0,64,64 };			//テクスチャ座標
	Math::Color color = { 1.0f,1.0f,1.0f,1.0f };	//色RGBA
	SHADER.m_spriteShader.DrawTex(&charaTex, 0, 0, &srcRect, &color);

	//加算合成
	D3D.SetBlendState(BlendMode::Add);

	//炎用パーティクル
	for (int i = 0; i < fireNum; i++) {
		fire[i].DrawFire();
	}

	D3D.SetBlendState(BlendMode::Alpha);

	//文字列はテクスチャなどを描画した後に書くこと
	// 文字列表示
	SHADER.m_spriteShader.DrawString(230, 350, "パーティクル３", Math::Vector4(0, 0, 0, 1));
	SHADER.m_spriteShader.DrawString(230+8, 350-5, "パーティクル３", Math::Vector4(1, 1, 0, frame / 180.0f));


}

void Scene::Update()
{
	bPlayerMove = false;

	//座標更新
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		playerX += 8;
		bPlayerMove = true;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		playerX -= 8;
		bPlayerMove = true;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		playerY += 8;
		bPlayerMove = true;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		playerY -= 8;
		bPlayerMove = true;
	}
	
	//行列の作成
	matrix = Math::Matrix::CreateTranslation(playerX, playerY, 0);

	//zキーでパーティクルを発生
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
	
	//xキーでパーティクルをリピート
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

	//cキーで背景にパーティクルを発生
	if (GetAsyncKeyState('C') & 0x8000) {
		for (int i = 0; i < smokeNum; i++) {
			smoke[i].Emit(
				{ Rnd() * 1280 - 640,Rnd() * 720 - 360 },
				{ Rnd() * 10 - 5,Rnd() * 10 - 5 },
				Rnd() * 10 + 5,
				{ Rnd() + 0.5f,Rnd() + 0.5f,Rnd() + 0.5f,0.5f },
				1000,
				false
			);
		}
	}

	//vキーで炎パーティクルをリピート
	if (GetAsyncKeyState('V') & 0x8000) {
		for (int i = 0; i < fireNum; i++) {
			//リピート再生の場合は初回のEmitの値はほとんど0でok
			fire[i].Emit(
				{ 0,0 },
				{ 0,0 },
				0,
				{ 0,0,0,0 },
				0,
				true
			);
		}
	}
	
	//bキーで光パーティクルをリピート
	if (GetAsyncKeyState('B') & 0x8000) {
		for (int i = 0; i < lightNum; i++) {
			//リピート再生の場合は初回のEmitの値はほとんど0でok
			light[i].Emit(
				{ 0,0 },
				{ 0,0 },
				0,
				{ 0,0,0,0 },
				0,
				true
			);
		}
	}

	//煙用パーティクル
	for (int i = 0; i < smokeNum; i++) {
		smoke[i].UpdateSmoke({ playerX,playerY },bPlayerMove);
	}

	//炎用パーティクル
	for (int i = 0; i < fireNum; i++) {
		fire[i].UpdateFire({ playerX,playerY },bPlayerMove);
	}

	//光用パーティクル
	for (int i = 0; i < lightNum; i++) {
		light[i].UpdateLight({ playerX,playerY },bPlayerMove);
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
	circleTex.Load("Texture/circle.png");

	for (int i = 0; i < smokeNum; i++) {
		smoke[i].SetTexture(&particleTex);
	}
	
	for (int i = 0; i < fireNum; i++) {
		fire[i].SetTexture(&particleTex);
	}

	for (int i = 0; i < lightNum; i++) {
		light[i].SetTexture(&circleTex);
	}

	//座標の初期化
	playerX = 0;
	playerY = 0;

	//煙パーティクル
	for (int i = 0; i < smokeNum; i++) {
		smoke[i].InitSmoke();
	}
	
	//炎パーティクル
	for (int i = 0; i < fireNum; i++) {
		fire[i].InitFire();
	}
	
	//光パーティクル
	for (int i = 0; i < lightNum; i++) {
		light[i].InitLight();
	}

	frame = 0;
}

void Scene::Release()
{
	// 画像の解放処理
	charaTex.Release();
	particleTex.Release();
	circleTex.Release();
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
