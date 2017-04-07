#pragma once

#include "Device.h"
#include "Texture.h"
#include <fstream> //�����

struct MobData
{
	float time;
	int type;
	int pattern;
};

class Scene
{
protected:
	float m_SceneTime;
	bool m_bChangeScene;
	int m_NextScene;

	MobData *m_Mobdata; //���� �����͸� �����ϴ� ����ü �迭
	int m_MobCounter; //�� ��° ���Ͱ� ���� ��������
	int m_MobdataLine; //txt������ �� ���� ��

public:
	Scene();
	~Scene();

	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void ChangeScene(int next);

	void LoadMonsters(const char* mobdata); //���� ������ �ҷ�����

	//Getter
	bool GetChangeScene() { return m_bChangeScene; }
	int GetNextScene() { return m_NextScene; }
};