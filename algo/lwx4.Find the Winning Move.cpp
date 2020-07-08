#include<iostream>
using namespace std;
char data1[4][4];
int count1 = 0;
int best_x = 0;
int best_y = 0;
int min_search();
int max_search();
bool settle();
bool check_win(char temp)
{
	if (data1[0][0] == temp && data1[1][1] == temp && data1[2][2] == temp && data1[3][3] == temp)
	{
		return true;
	}
	if (data1[0][3] == temp && data1[1][2] == temp && data1[2][1] == temp && data1[3][0] == temp)
	{
		return true;
	}
	for (int a = 0; a < 4; a++)
	{
		if (data1[a][0] == temp && data1[a][1] == temp && data1[a][2] == temp && data1[a][3] == temp)
		{
			return true;
		}
		if (data1[0][a] == temp && data1[1][a] == temp && data1[2][a] == temp && data1[3][a] == temp)
		{
			return true;
		}
	}
	return false;
}
int min_search()
{
	char temp = 'x';
	if (check_win(temp) == true)//自己是否已经赢
	{
		return 1;
	}
	else if (count1 >= 16)
	{
		return 0;
	}
	for (int a = 0; a < 4; a++)
		for (int b = 0; b < 4; b++)
			if (data1[a][b] == '.')//可以放置
			{
				data1[a][b] = 'o';
				count1++;
				int temp = max_search();
				data1[a][b] = '.';
				count1--;
				if (temp == -1 || temp == 0)//如若对方已经赢
				{
					return -1;
				}
			}
	return 1;
}
int max_search()
{
	char temp = 'o';
	if (check_win(temp) == true)//对方是否已经赢
	{
		return -1;
	}
	else if (count1 >= 16)
	{
		return 0;
	}
	for (int a = 0; a < 4; a++)
		for (int b = 0; b < 4; b++)
			if (data1[a][b] == '.')//可以放置
			{
				data1[a][b] = 'x';
				count1++;
				int temp = min_search();
				data1[a][b] = '.';
				count1--;
				if (temp == 1)//如若我已经赢
				{
					return 1;
				}
			}
	return -1;
}
bool settle()
{
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			if (data1[a][b] == '.')//可以放置
			{
				data1[a][b] = 'x';
				count1++;
				int temp = min_search();
				data1[a][b] = '.';
				count1--;
				if (temp == 1)//如若我已经赢
				{
					best_x = a;
					best_y = b;
					return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	char alph = '\0';
	while (cin >> alph)
	{
		if (alph == '$')
		{
			break;
		}
		count1 = 0;

		for (int a = 0; a < 4; a++)
		{
			for (int b = 0; b < 4; b++)
			{
				cin >> data1[a][b];

				if (data1[a][b] != '.')
				{
					count1++;
				}
			}
		}
		if (count1 <= 4)
		{
			cout << "#####" << endl;
		}
		else
		{
			if (settle() == true)
			{
				cout << '(' << best_x << ',' << best_y << ')' << endl;
			}
			else
			{
				cout << "#####" << endl;
			}
		}

	}

}