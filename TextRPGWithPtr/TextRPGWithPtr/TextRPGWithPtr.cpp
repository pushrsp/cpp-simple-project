#include <iostream>

using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void EnterLoby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* statInfo);
bool StartBattle(StatInfo *player, StatInfo *monster);

int main()
{
	EnterLoby();

	return 0;
}

void EnterLoby()
{
	cout << "로비에 입장했습니다." << endl;

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;

	player = CreatePlayer();

	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;

	CreateMonster(&monster);

	bool victory = StartBattle(&player, &monster);
	if (victory)
	{
		cout << "승리!" << endl;
	}
	else
	{
		cout << "패배!" << endl;
	}
}

StatInfo CreatePlayer()
{
	StatInfo ret;
	cout << "플레이어 생성" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* statInfo)
{
	cout << "몬스터 생성" << endl;

	statInfo->hp = 40;
	statInfo->attack = 8;
	statInfo->defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->defence;
		if (damage < 0) damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0) monster->hp = 0;

		cout << "몬스터 HP: " << monster->hp << endl;
		if (monster->hp == 0) return true;

		damage = monster->attack - player->defence;
		if (damage < 0) damage = 0;

		player->hp -= damage;
		if (player->hp < 0) player->hp = 0;

		cout << "플레이어 HP: " << player->hp << endl;
		if (player->hp == 0) return false;
	}
}