#include <iostream>

using namespace std;

int Strlen(const char* str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return len;
}

#pragma warning(disable:4996)

char* Strcpy(char* dest, const char* src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	if (i > 0) dest[i] = '\0';

	return dest;
}

char* Strcat(char* dest, const char* src)
{
	int destIndex = 0;
	int srcIndex = 0;

	while (dest[destIndex])
	{
		destIndex++;
	}

	while (src[srcIndex])
	{
		dest[destIndex] = src[srcIndex];
		destIndex++;
		srcIndex++;
	}

	dest[destIndex] = '\0';

	return dest;
}

int Strcmp(char* a, const char* b)
{
	int i = 0;
	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] > b[i])
		{
			return 1;
		}
		else if (a[i] < b[i])
		{
			return -1;
		}
		i++;
	}

	return 0;
}

void ReverseStr(char* a)
{
	int len = Strlen(a);
	if (len == 0) return;

	for (int i = 0; i < len / 2; i++)
	{
		int temp = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = temp;
	}
}

int main()
{
	const int BUF_SIZE = 100;
	char a[BUF_SIZE] = "hello hella";
	//char b[BUF_SIZE] = "hella";

	//cout << Strlen(a) << endl;
	//cout << Strcpy(b, a) << endl;
	//cout << Strcat(a, b) << endl;
	//cout << Strcmp(a, b) << endl;

	ReverseStr(a);
	cout << a << endl;

	return 0;
}
