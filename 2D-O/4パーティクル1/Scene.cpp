#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	//�s����Z�b�g
	SHADER.m_spriteShader.SetMatrix(matrix);

	//�`��
	//SHADER.m_spriteShader.DrawTex(&charaTex, Math::Rectangle{ 0,0,64,64 }, 1.0f);

	Math::Rectangle srcRect{ 0,0,64,64 };			//�e�N�X�`�����W
	Math::Color color = { 1.0f,1.0f,1.0f,1.0f };	//�FRGBA
	SHADER.m_spriteShader.DrawTex(&charaTex, 0, 0, &srcRect, &color);

	//�p�[�e�B�N��
	for (int i = 0; i < smokeNum; i++) {
		smoke[i].Draw();
	}




	//������̓e�N�X�`���Ȃǂ�`�悵����ɏ�������
	// ������\��
	SHADER.m_spriteShader.DrawString(230, 350, "�p�[�e�B�N���P", Math::Vector4(0, 0, 0, 1));
	SHADER.m_spriteShader.DrawString(230+8, 350-5, "�p�[�e�B�N���P", Math::Vector4(1, 1, 0, frame / 180.0f));


}

void Scene::Update()
{
	//���W�X�V
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
	
	//�s��̍쐬
	matrix = Math::Matrix::CreateTranslation(playerX, playerY, 0);

	//z�L�[�ŗ΂̃p�[�e�B�N���𔭐�
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
	
	//x�L�[�ŗ΂̃p�[�e�B�N�������s�[�g
	if (GetAsyncKeyState('X') & 0x8000) {
		for (int i = 0; i < smokeNum; i++) {
			//���s�[�g�Đ��̏ꍇ�͏����Emit�̒l�͂قƂ��0��ok
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


	//�p�[�e�B�N��
	for (int i = 0; i < smokeNum; i++) {
		smoke[i].Update();
	}

	//�t���[�����𑝂₷
	frame++;

}

void Scene::Init()
{
	//�����̏�����
	srand(timeGetTime());

	// �摜�̓ǂݍ��ݏ���
	charaTex.Load("Texture/smile_transparent.png");
	particleTex.Load("Texture/smoke_transparent.png");

	for (int i = 0; i < smokeNum; i++) {
		smoke[i].SetTexture(&particleTex);
	}

	//���W�̏�����
	playerX = 0;
	playerY = 0;

	//�p�[�e�B�N��
	for (int i = 0; i < smokeNum; i++) {
		smoke[i].Init();
	}

	frame = 0;
}

void Scene::Release()
{
	// �摜�̉������
	charaTex.Release();
	particleTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// �f�o�b�O�E�B���h�E
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
