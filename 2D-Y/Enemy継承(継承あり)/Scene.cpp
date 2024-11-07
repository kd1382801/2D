#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	m_orange.Draw();
	m_blue.Draw();
	m_green.Draw();
}

void Scene::Update()
{
	m_orange.Update();
	m_blue.Update();
	m_green.Update();
}

void Scene::Init()
{
	m_enemyTex.Load("Texture/Player/Chara.png");

	m_base = &m_orange;//インスタンスのアドレスをセット
	m_base->Init();

	//m_orange.Init();
	m_blue.Init();
	m_green.Init();

	m_orange.SetTex(&m_enemyTex);
	m_blue.SetTex(&m_enemyTex);
	m_green.SetTex(&m_enemyTex);
}

void Scene::Release()
{
	m_enemyTex.Release();
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
