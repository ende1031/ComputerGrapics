#pragma once

#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Fire.h"
#include "Monster.h"

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

protected:
	Player m_Player;
	Fire m_Fire[15];

	std::list<Monster*> m_MonsterList;
	std::list<Monster*>* GetMonsterList() { return &m_MonsterList; }
};