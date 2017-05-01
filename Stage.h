#pragma once

#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Fire.h"
#include "Monster.h"
#include "Effect.h"
#include "Boss.h"

//Stge���� ������������� ���������� ������ ����ü
class MonsterFileData
{
public:
	float time; //���Ͱ� ������ �ð�
	int type; //���� Ÿ�� (1 ~ 2) Ÿ�� 0�� ����
	int pattern; //���� ���� (0 ~ ����)
};

//��� ���������� ���� ���� Ŭ����
class Stage : public Scene
{
public:
	Stage();
	~Stage();

protected:
	Player m_Player;
	Fire m_Fire[15];
	Boss* m_pBoss;

	bool m_bAppearBoss;

	//����, ����Ʈ, �Ҹ� ����Ʈ
	std::list<Monster*> m_MonsterList;
	//std::list<Monster*>* GetMonsterList() { return &m_MonsterList; }
	std::list<Effect*> m_EffectList;

	//��������� ����
	MonsterFileData *m_MonsterFileData; //���� �����͸� �����ϴ� ����ü �迭
	int m_MonsterCounter; //�� ��° ���Ͱ� ���� ��������
	int m_MonsterDataLine; //txt������ �� ���� ��

	//������������ �̸� �����س��� ���� ������
	MonsterData m_MonsterData01;
	MonsterData m_MonsterData02;
	MonsterData m_MonsterData03;
	//BossData m_BossData;

	Texture m_tEffect; //����Ʈ �ؽ���. �ݵ�� Start()���� �ʱ�ȭ ���ֱ�.
	
	void Collision();

	void AddMonster(Monster* monster); //���͸� ����Ʈ�� �߰�
	void UpdateMonster(float deltaTime);
	void DrawMonster();

	void AddEffect(Effect* effect);
	void UpdateEffect(float deltaTime); //���Ϳ� ������ ����� �� �ְ� ���� ����
	void DrawEffect();

	void LoadMonsters(const char* mobdata); //���� ������ �ҷ�����
};