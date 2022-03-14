#include <iostream>

using namespace std;

void Swap(int*, int*);
void Sort(int[], int);
void ChooseLotto(int[]);

int main()
{
	int numbers[6] = { 1,42,3,15,6,5 };
	Sort(numbers, sizeof(numbers) / sizeof(int));
	ChooseLotto(numbers);

	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	{
		cout << numbers[i] << endl;
	}
}

void Swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

void Sort(int numbers[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			if (numbers[j] <= numbers[i])
			{
				Swap(&numbers[j], &numbers[i]);
			}
		}
	}
}

void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));

	int count = 0;
	while (count != 6)
	{
		int randVal = 1 + (rand() % 45);

		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randVal)
			{
				found = true;
				break;
			}
		}

		if (found == false)
		{
			numbers[0] = randVal;
			count++;
		}
	}

	Sort(numbers, 6);
}