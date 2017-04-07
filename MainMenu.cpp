#include "MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Start()
{
	m_bChangeScene = false;
	m_SceneTime = 0;

	//�ؽ��� �ʱ�ȭ
	m_tBG.Start(L"Image/Background.png");

	//������Ʈ �ʱ�ȭ
	m_BG.Start(m_tBG);
}

void MainMenu::Update(float deltaTime)
{
	m_BG.Update(deltaTime);

	//���͸� ������ �������� ����
	if (KeyInput(VK_RETURN)) //KeyDown�� �ƴ϶� KeyInput�ΰ� �߿�.
	{
		ChangeScene(sTestStage);
	}
}

void MainMenu::Draw()
{
	m_BG.Draw();
}
