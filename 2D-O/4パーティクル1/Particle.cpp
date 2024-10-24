#include "Particle.h"

Particle::Particle() :
	//�����o�E�C�j�V�����C�U
	m_pos(0, 0), 
	m_move(0, 0), 
	m_matrix(), 
	m_color(1, 1, 1, 1), 
	m_pTexture(nullptr),
	m_size(1), 
	m_lifespan(0), 
	m_bRepeat(false)
{
}

Particle::~Particle()
{
}

void Particle::Init()
{

	m_move = { Rnd() * 2 - 1 ,Rnd() * 2 - 1 };
	m_size = 0;
	m_color = { 0, 0, 0, 0 };

}

void Particle::Update()
{
	//�L������
	m_lifespan--;
	if (m_lifespan <= 0) {
		//�J��Ԃ������Ȃ��ꍇ(false)�͖߂�
		if (!m_bRepeat)return;

		//�J��Ԃ�������ꍇ(true)�̏ꍇ
		//�p�[�e�B�N�����ēx����������
		Emit(
			{ 150,50 },
			{ Rnd() * 6 - 3,Rnd() * 6 - 3 },
			Rnd() * 3 + 2,
			{ 1,1,1,0.2f },
			Rnd() * 90 + 10,
			true
		);

	}

	//�T�C�Y�ύX
	m_size *= 0.98f;

	//���ȍX�V
	m_pos += m_move;
	
	//�s��쐬
	Math::Matrix scaleMat = Math::Matrix::CreateScale(m_size, m_size, 0);
	Math::Matrix transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_matrix = scaleMat * transMat;
}

void Particle::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_matrix);

	Math::Rectangle srcRect = { 0,0,32,32 };
	SHADER.m_spriteShader.DrawTex(m_pTexture, 0, 0, &srcRect, &m_color);
}

void Particle::SetTexture(KdTexture* a_pTexture)
{
	m_pTexture = a_pTexture;
}

float Particle::Rnd()
{
	return rand() / (float)RAND_MAX;
}

void Particle::Emit(Math::Vector2 a_pos, Math::Vector2 a_move, float a_size, Math::Color a_color, int a_lifespan, bool a_bRepeat)
{
	m_pos = a_pos;
	m_move = a_move;
	m_size = a_size;
	m_color = a_color;
	m_lifespan = a_lifespan;
	m_bRepeat = a_bRepeat;

}
