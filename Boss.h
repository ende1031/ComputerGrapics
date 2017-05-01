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

	D3DXVECTOR3	GetvCenterPos() { return m_vCenterPos; };

protected:
	D3DXVECTOR3 m_vCenterPos;

	int m_Phase;
	int m_MaxHP;
	int m_HP;

	float m_AttackSpeed;
	float m_MoveSpeed;

	float m_ColTimer;
};