#include "main.h"
#include "Scene.h"

void Scene::Draw2D()
{
	//���Z����
	D3D.SetBlendState(BlendMode::Add);

	for (int i = 0; i < bubbleNum; i++) {
		bubble[i].Draw();
	}
	
	for (int i = 0; i < snowNum; i++) {
		snow[i].Draw();
	}
	
	StarDraw();

	D3D.SetBlendState(BlendMode::Alpha);

	for (int i = 0; i < tornadoNum; i++) {
		tornado[i].Draw();
	}

	//�v���C���[�`��
	SHADER.m_spriteShader.SetMatrix(playerMat);
	SHADER.m_spriteShader.DrawTex(&playerTex, Math::Rectangle{ 0,0,64,64 }, 1.0f);

	//������̓e�N�X�`���Ȃǂ�`�悵����ɏ�������
	// ������\��
	SHADER.m_spriteShader.DrawString(-630, 350, "R:�p�[�e�B�N�����Z�b�g", Math::Vector4(1, 1, 1, 1));
	SHADER.m_spriteShader.DrawString(-630, 320, "Z:�A", Math::Vector4(1, 1, 1, 1));
	SHADER.m_spriteShader.DrawString(-630, 290, "X:��", Math::Vector4(1, 1, 1, 1));
	SHADER.m_spriteShader.DrawString(-630, 260, "C:���ꐯ", Math::Vector4(1, 1, 1, 1));
	SHADER.m_spriteShader.DrawString(-630, 230, "V:����", Math::Vector4(1, 1, 1, 1));
	
}

void Scene::Update()
{
	//�v���C���[�ړ�
	moveFlg = false;
	playerMove = { 0.0 };
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		playerMove.y -= 5;
		moveFlg = true;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000){
		playerMove.y += 5;
		moveFlg = true;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000){
		playerMove.x -= 5;
		moveFlg = true;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000){
		playerMove.x += 5;
		moveFlg = true;
	}

	//R�L�[�ŃX�g�b�v
	if (GetAsyncKeyState('R') & 0x8000) {
		for (int i = 0; i < bubbleNum; i++) {
			bubble[i].Stop();
		}
		for (int i = 0; i < snowNum; i++) {
			snow[i].Stop();
		}
		starFlg = false;
		for (int i = 0; i < kiraNum; i++) {
			kira[i].Stop();
		}
		for (int i = 0; i < tornadoNum; i++) {
			tornado[i].Stop();
		}
	}
	//z�L�[�ŖA
	if (GetAsyncKeyState('Z') & 0x8000) {
		for (int i = 0; i < bubbleNum; i++) {
			bubble[i].Emit(
				{ 0,0 },		//pos
				{ 0,0 },		//move
				0,				//size
				{ 0,0,0,0 },	//color
				Rnd()*30,		//lifespan
				true		//repeat
			);
		}
	}
	//x�L�[�Ő�
	if (GetAsyncKeyState('X') & 0x8000) {
		for (int i = 0; i < snowNum; i++) {
			snow[i].Emit(
				{ 0,0 },		//pos
				{ 0,0 },		//move
				0,				//size
				{ 0,0,0,0 },	//color
				Rnd() * 200,		//lifespan
				true		//repeat
			);
		}
	}
	//c�L�[�ł��炫��
	if (GetAsyncKeyState('C') & 0x8000) {
		starFlg = true;
		for (int i = 0; i < kiraNum; i++) {
			kira[i].Emit(
				{ 0,0 },		//pos
				{ 0,0 },		//move
				0,				//size
				{ 0,0,0,0 },	//color
				Rnd() * 20,		//lifespan
				true		//repeat
			);
		}
	}
	//v�L�[�ŗ���
	if (GetAsyncKeyState('V') & 0x8000) {
		for (int i = 0; i < tornadoNum; i++) {
			tornado[i].Emit(
				{ 0,-370 },		//pos
				{ 0,0 },		//move
				0,				//size
				{ 0,0,0,0 },	//color
				Rnd()*500,		//lifespan
				true		//repeat
			);
		}
	}

	for (int i = 0; i < bubbleNum; i++) {
		bubble[i].Update();
	}

	for (int i = 0; i < snowNum; i++) {
		snow[i].Update();
	}

	for (int i = 0; i < tornadoNum; i++) {
		tornado[i].Update();
	}
	
	

	StarUpdate();

	playerPos += playerMove;
	playerMat = Math::Matrix::CreateTranslation(playerPos.x, playerPos.y, 0);
}

void Scene::Init()
{
	//�����̏�����
	srand(timeGetTime());

	playerTex.Load("Texture/smile.png");
	bubbleTex.Load("Texture/Bubble.png");
	snowTex.Load("Texture/en.png");
	starTex.Load("Texture/Star.png");
	tornadoTex.Load("Texture/Tornado.png");

	for (int i = 0; i < bubbleNum; i++) {
		bubble[i].SetTex(&bubbleTex);
		bubble[i].Init();
	}

	for (int i = 0; i < snowNum; i++) {
		snow[i].SetTex(&snowTex);
		snow[i].Init();
	}

	for (int i = 0; i < kiraNum; i++) {
		kira[i].SetTex(&starTex);
		kira[i].Init();
	}

	for (int i = 0; i < tornadoNum; i++) {
		tornado[i].SetTex(&tornadoTex);
		tornado[i].Init();
	}

	StarInit();

	playerPos = { 0,0 };
}

void Scene::Release()
{
	playerTex.Release();
	bubbleTex.Release();
	snowTex.Release();
	starTex.Release();
	tornadoTex.Release();
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

void Scene::StarInit()
{
	rad = 90;
	starPos.x = cos(DirectX::XMConvertToRadians(rad)) * 1350 - 600;
	starPos.y = sin(DirectX::XMConvertToRadians(rad)) * 400 + 0;
}

void Scene::StarUpdate()
{
	if (!starFlg)return;

	rad -= 0.7f;
	if (rad < 0) { rad = 90; }
	starPos.x = cos(DirectX::XMConvertToRadians(rad))*1350 - 600;
	starPos.y = sin(DirectX::XMConvertToRadians(rad))*400 + 0;

	for (int i = 0; i < kiraNum; i++) {
		kira[i].Update(starPos);
	}

	transMat = Math::Matrix::CreateTranslation(starPos.x, starPos.y, 0);
	scaleMat = Math::Matrix::CreateScale(0.7f, 0.7f, 0);
	mat = scaleMat * transMat;
}

void Scene::StarDraw()
{
	if (!starFlg)return;

	Math::Rectangle rect = { 0,0,128,128 };
	Math::Color color{ 1,1,0,1 };

	SHADER.m_spriteShader.SetMatrix(mat);
	SHADER.m_spriteShader.DrawTex(&starTex, 0, 0, &rect, &color);


	for (int i = 0; i < kiraNum; i++) {
		kira[i].Draw();
	}
}
