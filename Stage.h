#pragma once

#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Fire.h"
#include "Monster.h"

//Stge���� ������������� ���������� ������ ����ü
class MonsterFileData
{
public:
	float time; //���Ͱ� ������ �ð�
	int type; //���� Ÿ�� (1 ~ 2)
	int pattern; //���� ���� (0 ~ ����)
};

//��� ���������� ���� ���� Ŭ����
class Stage : public Scene
{
public:
	Stage();
	~Stage();

	void Collision();

	void AddMonster(Monster* monster); //���͸� ����Ʈ�� �߰�
	void UpdateMonster(float deltaTime);
	void DrawMonster();

	void LoadMonsters(const char* mobdata); //���� ������ �ҷ�����

protected:
	Player m_Player;
	Fire m_Fire[15];

	std::list<Monster*> m_MonsterList;
	std::list<Monster*>* GetMonsterList() { return &m_MonsterList; }

	MonsterFileData *m_MonsterFileData; //���� �����͸� �����ϴ� ����ü �迭
	int m_MonsterCounter; //�� ��° ���Ͱ� ���� ��������
	int m_MonsterDataLine; //txt������ �� ���� ��

	MonsterData m_MonsterData01;
	MonsterData m_MonsterData02;
	MonsterData m_MonsterData03;
	//BossData m_BossData;
};