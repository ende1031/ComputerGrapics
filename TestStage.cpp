#include "TestStage.h"

TestStage::TestStage()
{
}

TestStage::~TestStage()
{
}

void TestStage::Start()
{
	m_bChangeScene = false;
	m_SceneTime = 0;

	//�ؽ��� �ʱ�ȭ
	m_tBG.Start(L"Image/Background2.png");

	//������Ʈ �ʱ�ȭ
	m_BG.Start(m_tBG);
}

void TestStage::Update(float deltaTime)
{
	m_BG.Update(deltaTime);


	if (KeyInput(VK_ESCAPE))
	{
	ChangeScene(sMainMenu);
	}
}

void TestStage::Draw()
{
	m_BG.Draw();
}

void TestStage::CreateMonster()
{
	
}