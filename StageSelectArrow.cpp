#include "StageSelectArrow.h"

StageSelectArrow::StageSelectArrow()
{
}

StageSelectArrow::~StageSelectArrow()
{
}

void StageSelectArrow::Start(Texture texture)
{
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 0;
	m_bAlpaUp = true;
	m_alpaTimer = 0;

	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, (LONG)texture.GetWidth(), (LONG)texture.GetHeight() }; //�ؽ����� ũ�⸦ �ڵ����� �޾ƿ�. ���� ��ġ �Է��� �ʿ� ����.
	m_vPos = D3DXVECTOR3(0, 260, 0);

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;
}

void StageSelectArrow::Update(float deltaTime)
{
	m_alpaTimer += deltaTime;

	if (m_alpaTimer >= 0.02f)
	{
		if (m_bAlpaUp)
		{
			m_alpha += 10;
			m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
			if (m_alpha > 240)
				m_bAlpaUp = false;
		}
		else
		{
			m_alpha -= 10;
			m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
			if (m_alpha < 50)
				m_bAlpaUp = true;
		}
		m_alpaTimer = 0;
	}
}