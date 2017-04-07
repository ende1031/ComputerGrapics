#include "Looper.h"

Looper::Looper()
{
}


Looper::~Looper()
{
}

void Looper::Start()
{
	//������ ó�� �����ϸ� ���θ޴� �ʱ�ȭ
	SetScene(sMainMenu);
}

void Looper::Update(float deltaTime)
{
	if (m_pScene->GetChangeScene() == false)
	{
		m_pScene->Update(deltaTime);
	}
	else
	{
		SetScene(m_pScene->GetNextScene());
	}
}

void Looper::Render()
{
	if (NULL == g_pDevice)
		return;

	// ����۸� ����������
	Device::GetDevice()->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	if (SUCCEEDED(Device::GetDevice()->BeginScene())) // ������ ����
	{
		m_pScene->Draw();
		Device::GetDevice()->EndScene(); // ������ ��
	}

	//����۸� ���̴� ȭ������
	Device::GetDevice()->Present(NULL, NULL, NULL, NULL);
}

void Looper::SetScene(int Scene)
{
	//�������� ����
	m_iScene = Scene;

	//�������� �ʱ�ȭ
	switch (m_iScene)
	{
	case sMainMenu:
		m_pScene = new MainMenu;
		break;
	case sTestStage:
		m_pScene = new TestStage;
		
		break;
	case sStage1:
		//
		break;
	case sStage2:
		//
		break;
	}
	m_pScene->Start();
}