#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	SAFE_DELETE_ARRAY(m_MonsterFileData);
	SAFE_DELETE(m_pBoss);
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
					if (m_Fire[i].GetCanCol())
					{
						AddEffect(new Effect(m_tEffect, m_pSound, m_Fire[i].GetvCenterPos()));
						m_Player.SetPointUP(1);
						(*it)->ColFire();
						m_Fire[i].ColMonster();
					}
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

	//���� - ����� �浹
	for (int i = 0; i < 15; i++)
	{
		if (m_Fire[i].GetActive() && m_pBoss->GetActive())
		{
			float distance = D3DXVec3Length(&(m_pBoss->GetvCenterPos() - m_Fire[i].GetvCenterPos()));
			if (distance < m_pBoss->GetRadius() + m_Fire[i].GetRadius())
			{
				//�浹
				if (m_Fire[i].GetCanCol())
				{
					m_Player.SetPointUP(1);
					AddEffect(new Effect(m_tEffect, m_pSound, m_Fire[i].GetvCenterPos()));
					m_pBoss->ColFire();
					m_Fire[i].ColMonster();
				}
			}
		}
	}

	//���ͺҸ� - �÷��̾� �浹
	for (auto it = m_BulletList.begin(); it != m_BulletList.end(); ++it)
	{
		float distance = D3DXVec3Length(&((*it)->GetvCenterPos() - m_Player.GetvCenterPos()));
		if (distance < (*it)->GetRadius() + m_Player.GetRadius())
		{
			//�浹
			AddMEffect(new MBulletEffect(m_tMEffect, m_pSound, (*it)->GetvCenterPos()));
			m_Player.ColMonster();
			(*it)->SetActive(false);
		}
	}
}

void Stage::AddMonster(Monster* monster)
{
	m_MonsterList.push_back(monster);
}

void Stage::AddBullet(MonsterBullet* bullet)
{
	m_BulletList.push_back(bullet);
}

void Stage::AddEffect(Effect* effect)
{
	m_EffectList.push_back(effect);
}

void Stage::AddMEffect(MBulletEffect* effect)
{
	m_MEffectList.push_back(effect);
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

void Stage::UpdateBullet(float deltaTime)
{
	for (auto it = m_BulletList.begin(); it != m_BulletList.end();)
	{
		auto obj = *it;
		if (!obj->GetActive())
		{
			it = m_BulletList.erase(it);
			SAFE_DELETE(obj);
		}
		else
		{
			(*it)->Update(deltaTime);
			++it;
		}
	}
}

void Stage::UpdateEffect(float deltaTime)
{
	for (auto it = m_EffectList.begin(); it != m_EffectList.end();)
	{
		auto obj = *it;
		if (!obj->GetActive())
		{
			it = m_EffectList.erase(it);
			SAFE_DELETE(obj);
		}
		else
		{
			(*it)->Update(deltaTime);
			++it;
		}
	}
}

void Stage::UpdateMEffect(float deltaTime)
{
	for (auto it = m_MEffectList.begin(); it != m_MEffectList.end();)
	{
		auto obj = *it;
		if (!obj->GetActive())
		{
			it = m_MEffectList.erase(it);
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

void Stage::DrawBullet()
{
	for (auto it = m_BulletList.begin(); it != m_BulletList.end(); ++it)
	{
		(*it)->Draw();
	}
}

void Stage::DrawEffect()
{
	for (auto it = m_EffectList.begin(); it != m_EffectList.end(); ++it)
	{
		(*it)->Draw();
	}
}

void Stage::DrawMEffect()
{
	for (auto it = m_MEffectList.begin(); it != m_MEffectList.end(); ++it)
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

void Stage::CheckMonsterShoot()
{
	//���� �Ҹ� �߻� üũ
	for (auto it = m_MonsterList.begin(); it != m_MonsterList.end(); ++it)
	{
		if ((*it)->GetShoot())
		{
			if ((*it)->GetBulletData().toPlayer)
			{
				AddBullet(new MonsterBullet(m_tMonsterBullet, m_pSound, (*it)->GetvCenterPos(), m_Player.GetvCenterPos()));
			}
			else
			{
				for (int i = 0; i < (*it)->GetBulletData().count; i++)
				{
					AddBullet(new MonsterBullet(m_tMonsterBullet, m_pSound, (*it)->GetvCenterPos(), (*it)->GetBulletData().startAngle + (*it)->GetBulletData().angle * i));
				}
			}
		}
	}

	//���� �Ҹ� �߻� üũ
	if (m_pBoss->GetShoot())
	{
		if (m_pBoss->GetBulletData().toPlayer)
		{
			AddBullet(new MonsterBullet(m_tMonsterBullet, m_pSound, m_pBoss->GetvCenterPos(), m_Player.GetvCenterPos()));
		}
		else
		{
			for (int i = 0; i < m_pBoss->GetBulletData().count; i++)
			{
			AddBullet(new MonsterBullet(m_tMonsterBullet, m_pSound, m_pBoss->GetvCenterPos(), m_pBoss->GetBulletData().startAngle + m_pBoss->GetBulletData().angle * i));
			}
		}
	}
}