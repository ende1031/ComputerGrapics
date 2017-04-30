#pragma once
#include "Object.h"

class MonsterData
{
public:
	int pattern;
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
	Monster(Texture texture, Sound* sound, MonsterData data);
	~Monster();

	void Start(Texture texture, Sound* sound, MonsterData data);
	void Update(float deltaTime);
	int GetHP() { return m_HP; }

	void ColFire(); //����ɰ� �浹
	float m_ColTimer;

private:
	MonsterData m_MonsterData;
	int m_HP;

	void SpecialPattern(float deltaTime); //Ư������ (Update �ȿ� ��)
};