#include <iostream>

using namespace std;

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct ObjectInfo
{
	int type;
	int hp;
	int attack;
	int defence;
};

ObjectInfo plyerInfo;
ObjectInfo monsterInfo;

void EnterLoby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
	srand(time(0));
	EnterLoby();

	return 0;
}

void EnterLoby()
{
	while (true)
	{
		cout << "-------------------" << endl;
		cout << "로비에 입장했습니다." << endl;
		cout << "-------------------" << endl;

		// 플레이어 직업 선택
		SelectPlayer();

		cout << "-------------------------" << endl;
		cout << "(1) 필드 입장 (2) 게임종료" << endl;
		cout << "-------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}
	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "-------------------" << endl;
		cout << "직업을 골라주세요." << endl;
		cout << "(1) 기사 (2) 궁수 (3) 법사" << endl;
		cout << "> ";
		cin >> plyerInfo.type;

		switch (plyerInfo.type)
		{
		case PT_Knight:
			cout << "기사 생성중..." << endl;

			plyerInfo.hp = 150;
			plyerInfo.attack = 10;
			plyerInfo.defence = 5;
			return;
		case PT_Archer:
			cout << "궁수 생성중..." << endl;

			plyerInfo.hp = 150;
			plyerInfo.attack = 15;
			plyerInfo.defence = 3;
			return;
		case PT_Mage:
			cout << "궁수 생성중..." << endl;

			plyerInfo.hp = 150;
			plyerInfo.attack = 15;
			plyerInfo.defence = 3;
			return;
		default:
			break;
		}
	}
}

void EnterField()
{
	while (true)
	{
		cout << "-------------------" << endl;
		cout << "필드에 입장했습니다." << endl;
		cout << "-------------------" << endl;

		cout << "[PLAYER] HP: " << plyerInfo.hp << " / ATT: " << plyerInfo.attack << " / DEF: " << plyerInfo.defence << endl;

		CreateRandomMonster();

		cout << "-----------------" << endl;
		cout << "(1) 전투 (2) 도주" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (plyerInfo.hp == 0) return;
		}
		else
		{
			return;
		}
	}
}

void CreateRandomMonster()
{
	// 1~3 monsterType
	monsterInfo.type = 1 + (rand() % 3);
	switch (monsterInfo.type)
	{
	case MT_Slime:
		cout << "슬라임 생성중... (HP: 15 / ATT: 5 / DEF:0)" << endl;

		monsterInfo.hp = 15;
		monsterInfo.attack = 5;
		monsterInfo.defence = 0;
		break;
	case MT_Orc:
		cout << "오크 생성중... (HP: 40 / ATT: 10 / DEF:3)" << endl;

		monsterInfo.hp = 40;
		monsterInfo.attack = 10;
		monsterInfo.defence = 3;
		break;
	case MT_Skeleton:
		cout << "스켈레톤 생성중... (HP: 80 / ATT: 15 / DEF:5)" << endl;

		monsterInfo.hp = 80;
		monsterInfo.attack = 15;
		monsterInfo.defence = 5;
		break;
	default:
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = plyerInfo.attack - monsterInfo.defence;
		if (damage < 0) damage = 0;

		monsterInfo.hp -= damage;
		if (monsterInfo.hp < 0) monsterInfo.hp = 0;

		cout << "몬스터 남은 체력: " << monsterInfo.hp << endl;
		if (monsterInfo.hp == 0)
		{
			cout << "몬스터를 처치했습니다." << monsterInfo.hp << endl;
			return;
		}

		damage = monsterInfo.attack - plyerInfo.defence;
		if (damage < 0) damage = 0;

		//반격
		plyerInfo.hp -= damage;
		if (plyerInfo.hp < 0) plyerInfo.hp = 0;

		cout << "플레이어 남은 체력: " << plyerInfo.hp << endl;
		if (plyerInfo.hp == 0)
		{
			cout << "당신은 죽었습니다." << monsterInfo.hp << endl;
			return;
		}
	}
}