#include <iostream>
#include<iomanip>

using namespace std;

const int MAX = 100;
int BOARD[MAX][MAX] = {};
int N;

void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << BOARD[y][x] << " ";
		}
		cout << endl;
	}
}

enum DIR
{
	LEFT = 0,
	UP = 1,
	RIGHT = 2,
	DOWN = 3
};

bool CanGo(int y, int x)
{
	if (y < 0 || y >= N) return false;
	if (x < 0 || x >= N) return false;
	if (BOARD[y][x] != 0) return false;
	return true;
}

void SetBoard()
{
	int y = 0;
	int x = 0;
	int num = 1;
	int dir = RIGHT;

	while (true)
	{
		BOARD[y][x] = num;

		if (num == N * N) break;

		int nextY;
		int nextX;

		switch (dir)
		{
		case RIGHT:
			nextY = y;
			nextX = x + 1;
			break;
		case DOWN:
			nextY = y + 1;
			nextX = x;
			break;
		case LEFT:
			nextY = y;
			nextX = x - 1;
			break;
		case UP:
			nextY = y - 1;
			nextX = x;
			break;
		}

		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			switch (dir)
			{
			case RIGHT:
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			}
		}
	}
}

int main()
{
	cin >> N;

	SetBoard();
	PrintBoard();
	return 0;
}
