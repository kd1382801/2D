#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	m_map.Draw();
	m_player.Draw();
	for (int i = 0; i < m_enemyNum; i++) {
		m_enemy[i].Draw();
	};
}

void Scene::Update()
{
	m_player.Action();
	for (int i = 0; i < m_enemyNum; i++) {
		m_enemy[i].Action();
	}
	m_hit.MapRectHit(&m_player);
	for (int i = 0; i < m_enemyNum; i++) {
		m_hit.MapRectHit(&m_enemy[i]);
		m_hit.Enemy_Player(i);
	}
	m_player.Update();
	for (int i = 0; i < m_enemyNum; i++) {
		m_enemy[i].Update(m_player.GetScrollX());
	}
	m_map.Update(m_player.GetScrollX());
}

void Scene::Init()
{
	m_hit.SetOwner(this);
	m_player.SetOwner(this);

	m_map.LoadMap();

	// 画像の読み込み処理
	m_playerTex.Load("Texture/Player/Chara.png");
	m_enemyTex.Load("Texture/Player/Chara.png");
	m_mapTex.Load("Texture/Map/MapChip.png");

	m_player.SetTex(&m_playerTex);
	for (int i = 0; i < m_enemyNum; i++) {
		m_enemy[i].SetTex(&m_enemyTex);
	}
	m_map.SetTex(&m_mapTex);

	m_map.Init();
	m_player.Init();
	for (int i = 0; i < m_enemyNum; i++) {
		m_enemy[i].Init();
	}
	LoadCSV();
}

void Scene::Release()
{
	// 画像の解放処理
	m_playerTex.Release();
	m_enemyTex.Release();
	m_mapTex.Release();
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

void Scene::LoadCSV()
{
	FILE* fp;

	if (fopen_s(&fp, "Data/Enemy.csv", "r") == 0) {
		char dummy[255];
		for (int i = 0; i < m_enemyNum; i++) {
			if (fgets(dummy, 255, fp) != nullptr) {//一行読み込み
				Math::Vector2 pos;
				fscanf_s(fp, ",%f,%f", &pos.x, &pos.y);//頭に,で読み飛ばし
				m_enemy[i].SetPos(pos);
			}
		}
		fclose(fp);
	}
}
