#pragma once

#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Fire.h"
#include "Monster.h"
#include "Effect.h"
#include "Boss.h"
#include "MonsterBullet.h"
#include "MBulletEffect.h"
#include "Bar.h"
#include "StageClear.h"

//Stge에서 파일입출력으로 몬스터파일을 저장할 구조체
class MonsterFileData
{
public:
	float time; //몬스터가 나오는 시간
	int type; //몬스터 타입 (1 ~ 2) 타입 0은 보스
	int pattern; //몬스터 패턴 (0 ~ 미정)
};

//모든 스테이지용 씬의 상위 클래스
class Stage : public Scene
{
public:
	Stage();
	~Stage();

protected:
	Player m_Player;
	Fire m_Fire[15];
	Boss* m_pBoss;

	Object m_GameOver;
	Texture m_tGameOver;
	bool m_bGameOverSE;

	StageClear m_StageClear;
	Texture m_tStageClear;
	Texture m_tStageClearLight;
	bool m_bClear;
	bool m_bStageClearSE;

	Bar m_Bar;
	Texture m_tBarBG;
	Texture m_tBar;

	Texture m_tEffect; //이펙트 텍스쳐. 반드시 Start()에서 초기화 해주기.
	Texture m_tMonsterBullet; //이거도
	Texture m_tMEffect; //이거도

	bool m_bAppearBoss;

	//몬스터, 이펙트, 불릿 리스트
	std::list<Monster*> m_MonsterList;
	//std::list<Monster*>* GetMonsterList() { return &m_MonsterList; }
	std::list<MonsterBullet*> m_BulletList; //몬스터 불릿
	std::list<Effect*> m_EffectList;
	std::list<MBulletEffect*> m_MEffectList;

	//파일입출력 관련
	MonsterFileData *m_MonsterFileData; //몬스터 데이터를 저장하는 구조체 배열
	int m_MonsterCounter; //몇 번째 몬스터가 나올 차례인지
	int m_MonsterDataLine; //txt파일의 총 라인 수

	//스테이지별로 미리 설정해놓을 몬스터 데이터
	MonsterData m_MonsterData01;
	MonsterData m_MonsterData02;
	MonsterData m_MonsterData03;
	//BossData m_BossData;
	
	void Collision();

	void AddMonster(Monster* monster); //몬스터를 리스트에 추가
	void UpdateMonster(float deltaTime);
	void DrawMonster();

	void AddBullet(MonsterBullet* bullet);
	void UpdateBullet(float deltaTime);
	void DrawBullet();
	void CheckMonsterShoot();

	void AddEffect(Effect* effect);
	void UpdateEffect(float deltaTime); //몬스터와 별도로 사용할 수 있게 따로 만듬
	void DrawEffect();

	void AddMEffect(MBulletEffect* effect);
	void UpdateMEffect(float deltaTime);
	void DrawMEffect();

	void LoadMonsters(const char* mobdata); //몬스터 데이터 불러오기
};