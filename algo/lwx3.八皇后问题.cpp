#include<iostream>
using namespace std;
#define n 8
int ans[n];
bool col[n];
bool xie1[(n * 2)];
bool xie2[(n * 2)];
void reset()
{
	for (int a = 0; a < n; a++)
	{
		ans[a] = -1;
		col[a] = false;
	}
	int temp = (n * 2);
	for (int b = 0; b < temp; b++)
	{
		xie1[b] = false;
		xie1[b] = false;
	}
}
void print()
{
	for (int a = 0; a < n; a++)
	{
		int temp = ans[a] + 1;
		cout << temp << (a == n - 1 ? '\n' : ' ');
	}
	return;
}
void check_print()
{
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			cout << (ans[a] == b ? '1' : '1') << " ";
		}
		cout << endl;
	}
}
void search(int x)
{
	if (x == n)
	{
		print();
		return;
	}
	else
	{
		for (int a = 0; a < n; a++)
		{
			if (!col[a] && !xie1[x - a + n] && !xie2[x + a])
			{
				ans[x] = a;
				col[a] = true;
				xie1[x - a + n] = true;
				xie2[x + a] = true;
				search(x + 1);
				ans[x] = -1;
				col[a] = false;
				xie1[x - a + n] = false;
				xie2[x + a] = false;
			}
		}
	}
}
int main()
{
	reset();
	int first = 0;
	int sec = 0;
	cin >> first >> sec;
	first--;
	sec--;
	ans[0] = first;
	ans[1] = sec;
	col[first] = true;
	col[sec] = true;
	xie1[0 - first + n] = true;
	xie1[1 - sec + n] = true;
	xie2[0 + first] = true;
	xie2[1 + sec] = true;

	search(2);

}