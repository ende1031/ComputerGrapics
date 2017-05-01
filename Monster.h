#pragma once
#include "Object.h"

class MonsterData
{
public:
	float radius;
	float rectRight;
	float rectBottom;
	int rowNum;
	int lastNum;
	int maxHP;
	float attackSpeed;
	float moveSpeed;
};

class Monster : public Object
{
public:
	Monster(Texture texture, Sound* sound, int pattern, MonsterData data);
	~Monster();

	void Start(Texture texture, Sound* sound, int pattern, MonsterData data);
	void Update(float deltaTime);
	int GetHP() { return m_HP; }

	void ColFire(); //����ɰ� �浹
	float m_ColTimer;

private:
	MonsterData m_MonsterData;
	int m_HP;
	int m_Pattern;

	void SpecialPattern(float deltaTime); //Ư������ (Update �ȿ� ��)
};