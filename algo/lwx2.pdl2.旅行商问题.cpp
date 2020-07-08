//#input
   //n of int in [1,10];
   //dis of (int in [0, 1000])[1~n][1~n];

//#required
   //city of (int in [1,n])[1~n];
   //alldiff [city[b] : forall b ((b>=1) and (b < n))];

//#objective
   //minimize summation
       //[dis[city[a]][city[a+1]] : forall a (a of int in [1,n-1])];

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<set>

int n;
int dis[10][10];
int city[10];
int _result;
int _best__result;

void _input() {
	std::cin >> n;
	for (int _tmp0 = 1; _tmp0 <= n; _tmp0++)
		for (int _tmp1 = 1; _tmp1 <= n; _tmp1++)
			std::cin >> dis[_tmp0 - 1][_tmp1 - 1];
}

void _output() {
	std::cout << _best__result << std::endl;
}

std::set<int> _set0;

void _update() {
	if (_result >= _best__result)
		return;
	_best__result = _result;
}

void _find_city(int _step, int _sum1) {
	if (_step == n - 1 + 1) {
		_result = _sum1;
		_update();
		return;
	}
	int __sum1 = _sum1;
	for (city[_step] = 1; city[_step] <= 10; city[_step]++) {
		int _tmp0 = city[_step + 1 - 1];
		if (_set0.find(_tmp0) != _set0.end())
			continue;
		_sum1 = __sum1;
		if (_step - 1 >= 0) {
			int _tmp1 = city[_step - 1];
			if (_tmp1 > n)
				continue;
			int _tmp2 = city[_step + 1 - 1];
			if (_tmp2 > n)
				continue;
			_sum1 += dis[_tmp1 - 1][_tmp2 - 1];
		}
		if (!(_sum1 < _best__result))
			continue;
		_set0.insert(_tmp0);
		_find_city(_step + 1, _sum1);
		_set0.erase(_tmp0);
	}
}

void _solve() {
	_best__result = 9001;
	_find_city(0, 0);
}

int main() {
	_input();
	_solve();
	_output();
	return 0;
}