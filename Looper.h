#pragma once
#include "Define.h"

//�� ���������� ������� ���⿡ �߰�
#include "MainMenu.h"
#include "Stage01.h"

class Looper
{
public:
	Looper();
	~Looper();

	void Start();
	void Update(float deltaTime);
	void Render();

	//Setter
	void SetScene(int Scene);

	//Getter
	int GetScene() { return m_iScene; };

private:
	/*
	MainMenu m_MainMenu;
	TestStage m_TestStage;
	*/

	Scene* m_pScene;

	int m_iScene;

};

