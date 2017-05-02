#include "Boss01.h"

Boss01::Boss01()
{
}

Boss01::~Boss01()
{
}

void Boss01::Start(Texture texture, Sound* sound)
{
	cout << "���� ����!" << endl;
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();
	m_pSound = sound;
	m_pSound->Stop();
	m_pSound->PlayBGM("Sound/Boss01.mp3");

	m_AniTimer = 0;
	m_AniNum = 0;
	m_ColTimer = 1.0f;
	m_ariveTime = 0;
	m_bShootBullet = false;
	m_ShootTimer = 0;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, 187, 202 };

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;
	m_radius = 60.0f;
	
	m_vPos = D3DXVECTOR3(900 - m_width / 2, 270 - m_height / 2, 0);
	m_vCenterPos = D3DXVECTOR3(m_vPos.x + 62.f, m_vPos.y + 90.f, 0);

	m_MaxHP = 500;
	m_HP = m_MaxHP;
	m_Phase = 0;
}

void Boss01::Update(float deltaTime)
{
	m_vCenterPos = D3DXVECTOR3(m_vPos.x + 62.f, m_vPos.y + 90.f, 0);

	if (m_bActive)
	{
		m_ariveTime += deltaTime;
		m_ColTimer += deltaTime;
		m_ShootTimer += deltaTime;
		FadeIn(&m_alpha, deltaTime);
		Animation(4, 8, 0.1f, deltaTime);

		if (m_HP <= 0)
			m_bActive = false;

		switch (m_Phase)
		{
		case 0:
			Phase01(deltaTime);
			break;
		}
	}
}

void Boss01::Phase01(float deltaTime)
{
	if (m_vPos.x + m_width / 2 > 700)
		Move(-200, 0, deltaTime);

	if (m_ariveTime > 1.0f && m_ShootTimer > 0.2f)
	{
		ShootBullet(true);
		m_ShootTimer = 0;
	}
}