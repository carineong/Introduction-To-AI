#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n = 0;
struct point {
	int x;
	int y;
};
point data1[101];
double dis(double xx, double yy, point temp)
{
	return sqrt((xx - temp.x)*(xx - temp.x)+(yy - temp.y)*(yy - temp.y));

}
double calculate(double xx, double yy)
{
	double temp = 0.0;
	for (int a = 0; a < n; a++)
	{
		temp += dis(xx, yy, data1[a]);
	}
	return temp;
}
int main()
{

	double xx = 0;
	double yy = 0;
	cin >> n;
	for (int a = 0; a < n; a++)
	{
		cin >> data1[a].x >> data1[a].y;
		xx += data1[a].x;
		yy += data1[a].y;
	}
	xx /= n;
	yy /= n;
	double ans = calculate(xx, yy);
	double t = 1e5;
	while (t > 0.5)
	{
		double x1 = 0;
		double y1 = 0;

		for (int a = 0; a < n; a++)
		{
			x1 += ((data1[a].x) - xx) / dis(xx, yy, data1[a]);
			y1 += ((data1[a].y) - yy) / dis(xx, yy, data1[a]);
		}
		double temp = calculate(xx + (x1 * t), yy + (y1 * t));
		if (temp < ans)
		{
			ans = temp;
			xx += x1 * t;
			yy += y1 * t;
		}
		else if (t > (double)(rand() % 100000))
		{
			ans = temp;
			xx += x1 * t;
			yy += y1 * t;
			t *= 0.5;
		}
	}
	int hehe = ans;
	if (ans - hehe < 0.5)
	{
		cout << hehe;
	}
	else
	{
		cout << hehe + 1;
	}
	return 0;

}