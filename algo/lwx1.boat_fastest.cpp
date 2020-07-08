#include <iostream>
#include <string>
#include <queue>
using namespace std;
int num = 0;
int boat = 0;
bool done[2500][2500][2] = { 0 };
struct state {
	int lm;//原岸的传教士
	int lc;//原岸的食人魔
	int bb;//1代表船在左边，0代表船在右边
	int step;

	state(int m, int b = 1, int s = 0): lm(m), lc(m), bb(b), step(s) {}

	bool valid(int bm, int bc) 
	{
		if ((bm >= bc || bm == 0)) {
			if (bb == true) 
			{
				if (((lm - bm >= 0) && (lc - bc >= 0) && (lm - bm >= lc - bc) || (lm - bm == 0)) && ((num - lm + bm >= num - lc + bc) || (num - lm + bm == 0)) && (!done[lm - bm][lc - bc][0]))//先判断自己岸的，再判断对岸，在判断有没有在闭集点集出现过
				{
					return true;
				}
				return false;
			}
			else 
			{
				if (((lm + bm >= 0) && (lc + bc >= 0) && (lm + bm >= lc + bc) || (lm + bm == 0)) && ((num - lm - bm >= num - lc - bc) || (num - lm - bm == 0)) && (!done[lm + bm][lc + bc][1]))
				{
					return true;
				}
				return false;
			}
		}
		else
			return false;
	}

	state proceed(int bm, int bc) 
	{
		state result = *this;
		if (bb == 1) 
		{
			result.lm -= bm;
			result.lc -= bc;
		}
		else 
		{
			result.lm += bm;
			result.lc += bc;
		}
		result.bb ^= 1;
		result.step++;
		done[result.lm][result.lc][result.bb] = true;
		return result;
	}
};

queue<state> test;

int main() {
	int ans = -1;


	cin >> num >> boat;

	test.push(state(num));
	done[num][num][1] = true;
	
	while (!test.empty()) {
		state temp = test.front();
		test.pop();
		if (temp.lc == 0 && temp.lm == 0) 
		{
			ans = temp.step;
			break;
		}
		if (temp.bb == 1) //在左边
		{
			for (int a = boat; a >= 1; a--) //传教士
			{
				for (int b = a; b >= 0; b--) //食人魔
				{
					if (temp.valid(a - b, b)) 
					{
						test.push(temp.proceed(a - b, b));
					}
				}
			}
		}
		else //在右边
		{
			for (int a = 1; a <= boat; a++) 
			{
				for (int b = 0; b <= a; b++) 
				{
					if (temp.valid(a - b, b)) 
					{
						test.push(temp.proceed(a - b, b));
					}
				}
			}
		}
	}
	cout << ans << endl;
}