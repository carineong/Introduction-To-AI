#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int mapp[9][9];     //存储当前状态
bool isx[9][10], isy[9][10], iss[3][3][10], flag;  //行、列、块判断

void dfs(int y)
{
	if (y >= 9)    //最后一个数是0的情况下若递归到这里，则说明全部填充完毕
	{
		flag = true;
		return;
	}
	for (int i = y; i < 9; i++)  //从第y行开始，遍历剩下的点
		for (int j = 0; j < 9; j++)
		{
			if (mapp[i][j] == 0)   //一个需要判断的点
			{
				bool isc = false;     //这一点是否可以被填充
				int temp1 = i / 3;
				int temp2 = j / 3;
				for (int k = 1; k <= 9; k++) //1-9
				{
					if (isx[j][k] == false && isy[i][k] == false && iss[temp1][temp2][k] == false)   //三种情况都满足
					{
						isc = true;   //假设可以填充
						mapp[i][j] = k;   //填充的数是k
						isx[j][k] = isy[i][k] = iss[temp1][temp2][k] = true;  //标记该位置
						dfs(j != 8 ? y : y + 1);
						if (flag == true)
						{
							return;
						}//找到答案返回，放在这里可以防止在层层结束递归的时候状态被还原
						else
						{
							isc = false;     //下层递归失败，标记该点不能填充
							mapp[i][j] = 0;       //还原状态
							isx[j][k] = isy[i][k] = iss[i / 3][j / 3][k] = false;

						}
					}
				}
				if (isc == false)
				{
					return;
				}
			}
			else if (i == 8 && j == 8)     //最后一个点不是0的情况
			{
				flag = true;
				return;
			}
		}
}

int main()
{
	int n;
	scanf_s("%d", &n);
	for (int ni = 0; ni < n; ni++)
	{
		memset(isx, false, sizeof(isx));
		memset(isy, false, sizeof(isy));
		memset(iss, false, sizeof(iss));
		flag = false;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				scanf_s("%1d", &mapp[i][j]);
				if (mapp[i][j] != 0)
				{
					int temp1 = i / 3;
					int temp2 = j / 3;
					isx[j][mapp[i][j]] = true;
					isy[i][mapp[i][j]] = true;
					iss[temp1][temp2][mapp[i][j]] = true;
				}
			}
		dfs(0);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf(j != 8 ? "%d" : "%d\n", mapp[i][j]);
			}
		}
	}
	return 0;
}
