#include "HowToPlay.h"

HowToPlay::HowToPlay()
{
	cout << "���۹�� ȭ��" << endl;
}

HowToPlay::~HowToPlay()
{
}

void HowToPlay::Start(Sound* sound)
{
	m_bChangeScene = false;
	m_SceneTime = 0;

	m_pSound = sound;
	m_pSound->Stop();

	//�ؽ��� �ʱ�ȭ
	m_tBackground.Start(L"Image/HowToPlay.png");
	m_tLight.Start(L"Image/Title/Light.png");

	//������Ʈ �ʱ�ȭ
	m_Background.Start(m_tBackground);
	m_Light.Start(m_tLight);

	m_pSound->PlayBGM("Sound/HowToPlay.mp3");
}

void HowToPlay::Update(float deltaTime)
{
	m_Background.Update(deltaTime);
	m_Light.Update(deltaTime);

	//���͸� ������ �������� ����
	if (KeyInput(VK_RETURN) || KeyInput(VK_SPACE) || KeyInput(VK_ESCAPE))
	{
		ChangeScene(sMainMenu);
	}
}

void HowToPlay::Draw()
{
	m_Background.Draw();
	m_Light.Draw();
}
