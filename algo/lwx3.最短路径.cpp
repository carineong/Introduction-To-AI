#include <iostream>
#include <algorithm>
using namespace std;
int dis[101][101] = { 0 };
int city[101] = { 0 };
int cost = 100000;
int tcost = 0;
int n = 0;
void reset()
{
	for (int a = 0; a < 101; a++)
	{
		for (int b = 0; b < 101; b++)
		{
			dis[a][b] = 0;
		}
		city[a] = 0;
	}
}
void search()
{
	for (int a = 1; a <= n; a++)
	{
		for (int b = 1; b <= n; b++)
		{
			for (int c = 1; c <= n; c++)
			{
				if (a != b && b != c && c != a)
				{
					dis[a][b] = (min(dis[a][b], (dis[a][c] + dis[c][b])));
				}
			}
		}
	}
}
int main()
{
	cin >> n;
	reset()
	for (int a = 1; a <= n; a++)
	{
		for (int b = 1; b <= n; b++)
		{
			cin >> dis[a][b];
		}
	}
	search();
	cout << dis[1][n];


}