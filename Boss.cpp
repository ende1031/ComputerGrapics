#include "Boss.h"

Boss::Boss()
{
}

Boss::~Boss()
{
}

void Boss::ColFire()
{
	//if (m_ColTimer > 0.2f)
	{
		cout << "���� Ÿ��" << endl;
		m_HP--;
		m_ColTimer = 0;
	}
}

bool Boss::GetCanCol()
{
	if (m_ColTimer > 0.2f)
	{
		return true;
	}
	else
		return false;
}

bool Boss::GetShoot()
{
	if (m_bShootBullet)
	{
		cout << "���� �Ҹ� �߻�" << endl;
		m_bShootBullet = false;
		return true;
	}
	else
		return false;
}

void Boss::ShootBullet(bool toPlayer)
{
	m_BulletData.angle = 180;
	m_BulletData.toPlayer = toPlayer;
	m_bShootBullet = true;
}

void Boss::ShootBullet(bool toPlayer, float angle)
{
	m_BulletData.angle = angle;
	m_BulletData.toPlayer = toPlayer;
	m_bShootBullet = true;
}