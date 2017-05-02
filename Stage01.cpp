#include "Stage01.h"

Stage01::Stage01()
{
	cout << "��������1�� �ε�Ǿ����ϴ�." << endl;
}

Stage01::~Stage01()
{
}

void Stage01::Start(Sound* sound)
{
	m_bChangeScene = false;
	m_SceneTime = 0;
	m_MonsterCounter = 0;
	m_bAppearBoss = false;

	m_pSound = sound;
	m_pSound->Stop();
	m_pSound->PlayBGM("Sound/Stage01.mp3");

	m_tBackGround01.Start(L"Image/Stage01/BackGround01.png");
	m_tBackGround02.Start(L"Image/Stage01/BackGround02.png");
	m_tBackGround03.Start(L"Image/Stage01/BackGround03.png");

	m_BackGround01.Start(m_tBackGround01, 250.f);
	m_BackGround02.Start(m_tBackGround02, 200.f);
	m_BackGround03.Start(m_tBackGround03, 150.f);

	m_tPlayer.Start(L"Image/Player.png");
	m_Player.Start(m_tPlayer, m_pSound);

	m_tFire_Small.Start(L"Image/FireSmall.png");
	m_tFire_Big.Start(L"Image/FireBig.png");
	for (int i = 1; i <= 15; i++)
		m_Fire[i - 1].Start(m_tFire_Small, m_tFire_Big, m_pSound, &m_Player, i);

	m_tMonster01.Start(L"Image/Stage01/Monster01.png");
	m_tMonster02.Start(L"Image/Stage01/Monster02.png");
	m_tMonster03.Start(L"Image/Stage01/Monster03.png");
	m_tBoss.Start(L"Image/Stage01/Boss.png");
	m_tMonsterBullet.Start(L"Image/MonsterBullet.png");

	m_tEffect.Start(L"Image/FireEffect.png");


	//pattern, radius, rectRight, rectBottom, rowNum, lastNum, maxHP, attackSpeed, moveSpeed
	m_MonsterData01 = { 35.0f, 65.0f, 97.0f, 2, 2, 5, 0.5f, 10.0f };
	m_MonsterData02 = { 35.0f, 65.0f, 97.0f, 2, 2, 5, 0.5f, 10.0f };
	m_MonsterData03 = { 40.0f, 97.0f, 93.0f, 6, 6, 5, 0.5f, 10.0f };

	LoadMonsters("Data/Stage01Monsters.txt");

	m_pBoss = new Boss01;
}

void Stage01::Update(float deltaTime)
{
	m_SceneTime += deltaTime;

	m_BackGround01.Update(deltaTime);
	m_BackGround02.Update(deltaTime);
	m_BackGround03.Update(deltaTime);

	m_Player.Update(deltaTime);

	for (int i = 0; i < 15; i++)
		m_Fire[i].Update(deltaTime);

	if (m_bAppearBoss)
		dynamic_cast<Boss01*>(m_pBoss)->Update(deltaTime);

	UpdateMonster(deltaTime); //���� ��ü Update
	UpdateBullet(deltaTime);
	UpdateEffect(deltaTime);
	Collision();

	if (m_SceneTime > m_MonsterFileData[m_MonsterCounter].time && m_MonsterDataLine > m_MonsterCounter)
	{
		D3DXVECTOR3 temppos = {800,250,0};
		//AddBullet(new MonsterBullet(m_tMonsterBullet, m_pSound, temppos, m_Player.GetvCenterPos()));
		//AddBullet(new MonsterBullet(m_tMonsterBullet, m_pSound, temppos, 180));
		switch (m_MonsterFileData[m_MonsterCounter].type)
		{
		case 0: //����
			//AddMonster(new Boss01(m_tBoss, m_pSound, 0, m_MonsterData01, 1));
			dynamic_cast<Boss01*>(m_pBoss)->Start(m_tBoss, m_pSound);
			m_bAppearBoss = true;
			break;
		case 1:
			AddMonster(new Monster(m_tMonster01, m_pSound, m_MonsterFileData[m_MonsterCounter].pattern, m_MonsterData01));
			break;
		case 2:
			AddMonster(new Monster(m_tMonster02, m_pSound, m_MonsterFileData[m_MonsterCounter].pattern, m_MonsterData02));
			break;
		case 3:
			AddMonster(new Monster(m_tMonster03, m_pSound, m_MonsterFileData[m_MonsterCounter].pattern, m_MonsterData03));
			break;
		}
		m_MonsterCounter++;
	}

	if (KeyInput(VK_ESCAPE))
	{
		ChangeScene(sMainMenu);
	}
}

void Stage01::Draw()
{
	m_BackGround03.Draw(); //������� �׸���
	m_BackGround02.Draw();
	m_BackGround01.Draw();

	DrawMonster(); //���� ��ü Draw

	if (m_bAppearBoss)
		dynamic_cast<Boss01*>(m_pBoss)->Draw();

	m_Player.Draw();

	DrawBullet();

	for (int i = 14; i >= 0; i--)
		m_Fire[i].Draw();

	DrawEffect();
}