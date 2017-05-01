#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	SAFE_DELETE_ARRAY(m_MonsterFileData);
}

void Stage::Collision()
{
	for (auto it = m_MonsterList.begin(); it != m_MonsterList.end(); ++it)
	{
		//���� - ����� �浹
		for (int i = 0; i < 15; i++)
		{
			if (m_Fire[i].GetActive())
			{
				float distance = D3DXVec3Length(&((*it)->GetvCenterPos() - m_Fire[i].GetvCenterPos()));
				if (distance < (*it)->GetRadius() + m_Fire[i].GetRadius())
				{
					//�浹
					(*it)->ColFire();
				}
			}
		}

		//���� - �÷��̾� �浹
		float distance = D3DXVec3Length(&((*it)->GetvCenterPos() - m_Player.GetvCenterPos()));
		if (distance < (*it)->GetRadius() + m_Player.GetRadius())
		{
			//�浹
			m_Player.ColMonster();
		}
	}
}

void Stage::AddMonster(Monster* monster)
{
	m_MonsterList.push_back(monster);
}

void Stage::UpdateMonster(float deltaTime)
{
	for (auto it = m_MonsterList.begin(); it != m_MonsterList.end();)
	{
		auto obj = *it;
		if (!obj->GetActive()) //������ Active�� false�� ����
		{
			it = m_MonsterList.erase(it);
			SAFE_DELETE(obj);
		}
		else
		{
			(*it)->Update(deltaTime);
			++it;
		}
	}
}

void Stage::DrawMonster()
{
	for (auto it = m_MonsterList.begin(); it != m_MonsterList.end(); ++it)
	{
		(*it)->Draw();
	}
}

void Stage::LoadMonsters(const char* mobdata)
{
	ifstream Data;
	m_MonsterDataLine = 1;

	//line �� ���ϱ�
	Data.open(mobdata, ios::in);
	char c;
	while (Data.get(c))
	{
		if (c == '\n') ++m_MonsterDataLine;
	}
	Data.close();

	m_MonsterFileData = new MonsterFileData[m_MonsterDataLine];

	//������ �ҷ�����
	Data.open(mobdata, ios::in);
	for (int i = 0; i < m_MonsterDataLine; i++)
	{
		Data >> m_MonsterFileData[i].time >> m_MonsterFileData[i].type >> m_MonsterFileData[i].pattern;
	}
	Data.close();

	cout << mobdata << "���� ���� �����Ͱ� �ε�Ǿ����ϴ�." << endl << "===========================================" << endl;
	for (int i = 0; i < m_MonsterDataLine; i++)
	{
		cout << "�ð� : " << m_MonsterFileData[i].time << "\tŸ�� : " << m_MonsterFileData[i].type << "\t���� : " << m_MonsterFileData[i].pattern << endl;
	}
	cout << "===========================================" << endl;
}