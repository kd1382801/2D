#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	m_map.Draw();
	m_player.Draw();
	m_enemy.Draw();
}

void Scene::Update()
{
	m_player.Action();
	m_enemy.Action();
	m_hit.MapRectHit(&m_player);
	m_hit.MapRectHit(&m_enemy);
	m_hit.Enemy_Player();
	m_player.Update();
	m_enemy.Update(m_player.GetScrollX());
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
	m_enemy.SetTex(&m_enemyTex);
	m_map.SetTex(&m_mapTex);

	m_map.Init();
	m_player.Init();
	m_enemy.Init();

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
