#include "main.h"
#include "Scene.h"

//�e�N�X�`��(tmptex)�ւ̕`�揈�� main.cpp 206 Draw2D�̑O�ɏ���
void Scene::DynamicDraw2D()
{
	//�`���̃e�N�X�`���̃N���A(���F)
	tmpTex.ClearRenerTarget(Math::Color(0.0f, 0.0f, 0.0f, 1.0f));

	//�`�����e�N�X�`���֐؂�ւ�
	tmpTex.SetRenderTarget();

	//�u�����h���@�̐؂�ւ� �� �A���t�@
	D3D.SetBlendState(BlendMode::Alpha);

	//�X�e���V���`��
	SHADER.m_spriteShader.SetMatrix(stencil.mat);
	SHADER.m_spriteShader.DrawTex(&stencilTex, Math::Rectangle{ 0,0,512,512 }, 1.0f);
}

//�o�b�N�o�b�t�@(���s���)�ւ̕`�揈��
void Scene::Draw2D()
{
	//�`�����o�b�N�o�b�t�@�֐؂�ւ�(�ȍ~�̕`�揈���̓o�b�N�o�b�t�@��)
	D3D.SetBackBuffer();

	//�w�i
	SHADER.m_spriteShader.SetMatrix(back.mat);
	SHADER.m_spriteShader.DrawTex(&backTex, Math::Rectangle(0, 0, 1280, 720), 1.0f);

	//���@
	SHADER.m_spriteShader.SetMatrix(player.mat);
	SHADER.m_spriteShader.DrawTex(&playerTex, Math::Rectangle(0, 0, 64, 64), 1.0f);

	//�u�����h���@�̐؂�ւ� �� �X�e���V��:���̕���������
	D3D.SetBlendState(BlendMode::Stencil);

	//tmpTex�`��
	SHADER.m_spriteShader.SetMatrix(back.mat);
	SHADER.m_spriteShader.DrawTex(&tmpTex, Math::Rectangle{ 0,0,1280,720 }, 1.0f);


}

void Scene::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		player.x -= 5;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		player.x += 5;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		player.y += 5;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		player.y -= 5;
	}

	//�X�e���V��
	if (GetAsyncKeyState('W') & 0x8000) stencil.y += 5;
	if (GetAsyncKeyState('S') & 0x8000) stencil.y -= 5;
	if (GetAsyncKeyState('A') & 0x8000) stencil.x -= 5;
	if (GetAsyncKeyState('D') & 0x8000) stencil.x += 5;

	if (GetAsyncKeyState('Z') & 0x8000) {
		stencil.scaleX -= 0.1f;
		stencil.scaleY -= 0.1f;
		if (stencil.scaleX < 0)stencil.scaleX = 0;
		if (stencil.scaleY < 0)stencil.scaleY = 0;
	}
	if (GetAsyncKeyState('X') & 0x8000) {
		stencil.scaleX += 0.1f;
		stencil.scaleY += 0.1f;
	}

	player.mat = Math::Matrix::CreateTranslation(player.x, player.y, 0);
	back.mat = Math::Matrix::CreateTranslation(back.x, back.y, 0);
	
	stencil.transMat = Math::Matrix::CreateTranslation(stencil.x, stencil.y, 0);
	stencil.scaleMat = Math::Matrix::CreateScale(stencil.scaleX, stencil.scaleY, 1);
	stencil.mat = stencil.scaleMat * stencil.transMat;
}

void Scene::Init()
{
	playerTex.Load("Texture/player.png");
	backTex.Load("Texture/Back_02.png");
	//stencilTex.Load("Texture/myStencil.png");
	stencilTex.Load("Texture/stencil.png");

	//�����_�[�^�[�Q�b�g�p�e�N�X�`���쐬
	tmpTex.CreateRenderTarget(1280, 720);

	back.x = 0.0f;
	back.y = 0.0f;

	player.x = 0.0f;
	player.y = 0.0f;

	stencil.x = 0.0f;
	stencil.y = 0.0f;
	stencil.scaleX = 1.0f;
	stencil.scaleY = 1.0f;

}

void Scene::Release()
{
	// �摜�̉������
	playerTex.Release();
	backTex.Release();
	tmpTex.Release();
	stencilTex.Release();
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
