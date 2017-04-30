#pragma once
#include "Player.h"

class Fire : public Object
{
public:
	Fire();
	~Fire();

	void Start(Texture texture1, Texture texture2, Sound* sound, Player* player, int fireNum);
	void Update(float deltaTime);

private:
	Player* m_pPlayer;
	int m_FireNum;
	D3DXVECTOR3 m_vPlayerPos;

	void SetInCirclePos();
	void RotateCircle();
	float m_CircleRadius;
	float m_RotateAngle;
	D3DXVECTOR3 m_vInCirclePos; //�� ȸ�����϶� ��ġ

	D3DXVECTOR3 m_vTargetPos;
	bool m_bHaveTarget; //m_vTargetPos�� �޾Ҵ���
	float m_DistanceToTaget; //m_vTargetPos������ �Ÿ�;
	float m_AttackRange;
	bool m_TurnBack;

	D3DXVECTOR3 m_vMoveVector;
	float m_MoveSpeed;
};