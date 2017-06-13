#pragma once
#include "Object.h"

class MonsterData
{
public:
	float radius;
	int rowNum;
	int lastNum;
	int maxHP;
	float attackSpeed;
	float moveSpeed;
};

class Monster : public Object
{
public:
	//Monster() {}
	Monster(Texture texture, Sound* sound, int pattern, MonsterData data);
	~Monster();

	void Start(Texture texture, Sound* sound, int pattern, MonsterData data);
	void Update(float deltaTime);
	int GetHP() { return m_HP; }

	void ColFire(); //����ɰ� �浹
	bool GetCanCol();

	BulletData GetBulletData() { return m_BulletData; }
	bool GetShoot();

private:
	float m_ColTimer;
	
	MonsterData m_MonsterData;
	int m_HP;
	int m_Pattern;

	BulletData m_BulletData;
	bool m_bShootBullet; //true�� Stage���� �Ҹ��� �������
	float m_ShootTimer;
	int m_attackCount;

	float m_ariveTime; //����ִ� �ð�

	bool m_bMoveUp;
	float m_sinAngle;

	void ShootBullet(bool toPlayer);
	void ShootBullet(bool toPlayer, int count, float startAngle, float angle);
};