#pragma once

#include "Scene.h"
#include "Background.h"

class TestStage : public Scene
{
public:
	TestStage();
	~TestStage();

	void Start();
	void Update(float deltaTime);
	void Draw();

	void CreateMonster(); //���� ����

private:
	BackGround m_BG;
	Texture m_tBG;
};