#pragma once
#include "Object.h"

class Boss : public Object
{
public:
	Boss();
	~Boss();

	int GetPhase() { return m_Phase; };

	bool GetCanCol();
	void ColFire(); //����ɰ� �浹

	BulletData GetBulletData() { return m_BulletData; }
	bool GetShoot();

	D3DXVECTOR3	GetvCenterPos() { return m_vCenterPos; };

protected:
	D3DXVECTOR3 m_vCenterPos;

	int m_Phase;
	int m_MaxHP;
	int m_HP;

	float m_AttackSpeed;
	float m_MoveSpeed;

	float m_ColTimer;

	BulletData m_BulletData;
	bool m_bShootBullet; //true�� Stage���� �Ҹ��� �������
	float m_ShootTimer;

	float m_ariveTime; //����ִ� �ð�

	void ShootBullet(bool toPlayer);
	void ShootBullet(bool toPlayer, float angle);
};