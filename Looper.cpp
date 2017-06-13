#include "Looper.h"

Looper::Looper()
{
}


Looper::~Looper()
{
}

void Looper::Start()
{
	m_Sound.Start(); //���忣�� �ʱ�ȭ

	SetScene(sMainMenu);//������ ó�� �����ϸ� ���θ޴��� �� ����
}

void Looper::Update(float deltaTime)
{
	if (m_pScene->GetChangeScene() == false) //�� ������ ���� ���
	{
		m_pScene->Update(deltaTime); //�� ������Ʈ
	}
	else //�� ����
	{
		SetScene(m_pScene->GetNextScene());
	}
	Render();
}

void Looper::Render()
{
	if (NULL == g_pDevice)
		return;

	// ����۸� ����������
	Device::GetDevice()->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	if (SUCCEEDED(Device::GetDevice()->BeginScene())) // ������ ����
	{
		//�� �׸���
		m_pScene->Draw();
		Device::GetDevice()->EndScene(); // ������ ��
	}

	//����۸� ���̴� ȭ������
	Device::GetDevice()->Present(NULL, NULL, NULL, NULL);
}

void Looper::SetScene(int Scene)
{
	//�� ����
	m_iScene = Scene;

	switch (m_iScene)
	{
	case sMainMenu:
		m_pScene = new MainMenu;
		break;
	case sHowToPlay:
		m_pScene = new HowToPlay;
		break;
	case sStage1:
		m_pScene = new Stage01;
		break;
	case sStage2:
		m_pScene = new Stage02;
		break;
	case sStage3:
		m_pScene = new Stage03;
		break;
	case sStage4:
		m_pScene = new Stage04;
		break;
	case sStage5:
		m_pScene = new Stage05;
		break;
	}

	//�� �ʱ�ȭ
	m_pScene->Start(&m_Sound);
}