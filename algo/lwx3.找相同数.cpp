#include<iostream>
using namespace std;
int main()
{
	int n = 0;
	int test[1000] = { 0 };
	cin >> n;

	for (int a = 0; a < n; a++)
	{
		cin >> test[a];
	}

	for (int b = 0; b < n - 1; b++)
	{
		for (int c = b + 1; c < n; c++)
		{
			if (test[b] == test[c])
			{
				cout << test[b];
				break;
			}
		}
	}
	return 0;
}