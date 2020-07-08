//你需要挑选若干成员组建一个工作团队。现有n（1<=n<=100）名候选人，每个人有一个“凝聚力”和一个“工作能力”（均为-50至50的整数）。要确保团队能够顺利合作，所有成员的“凝聚力”之和必须为正。在这个条件下，团队的总“工作能力”最大是多少？保证至少存在一个满足条件且总“工作能力”为正的团队。
//输入：
//第一行输入一个整数n
//第二行输入n个整数，用空格隔开，依次为各候选人的凝聚力
//第三行输入n个整数，用空格隔开，依次为各候选人的工作能力
//输出：
//一个整数，最大的团队总“工作能力”
//#input
    //n of int in [1,100];
    //a of (int in [-50,50])[1~n];
    //b of (int in [-50,50])[1~n];

//#required
    //test of (int in [1,n]){};
    //summation 
        //[a[i] : forall i (i in test)] >= 0;

//#objective
    //maximize summation
        //[b[i] : forall i (i in test)];

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<set>

int n;
int a[100];
int b[100];
int test[100];
int _result;
int _best__result;

void _input() {
	std::cin >> n;
	for (int _tmp0 = 1; _tmp0 <= n; _tmp0++)
		std::cin >> a[_tmp0 - 1];
	for (int _tmp0 = 1; _tmp0 <= n; _tmp0++)
		std::cin >> b[_tmp0 - 1];
}

void _output() {
	std::cout << _best__result << std::endl;
}

void _update() {
	if (_result <= _best__result)
		return;
	_best__result = _result;
}

int _DP_test[100][10001];

int _find_test(int _step, int _sum1, int _sum2) {
	if (_step == n - 1 + 1) {
		_result = _sum2;
		if (!(_sum1 >= 0))
			return -5001;
		_update();
		return _sum2;
	}
	if (_DP_test[_step][_sum1 + 5000] != -5001) {
		_sum2 += _DP_test[_step][_sum1 + 5000];
		_result = _sum2;
		_update();
		return _sum2;
	}
	int __sum1 = _sum1;
	int __sum2 = _sum2;
	for (test[_step] = 0; test[_step] <= 1; test[_step]++) {
		_sum1 = __sum1;
		_sum2 = __sum2;
		if (test[_step + 1 - 1])
			_sum1 += a[_step + 1 - 1];
		if (test[_step + 1 - 1])
			_sum2 += b[_step + 1 - 1];
		if (!(_sum1 + 50 * (100 - _step) >= 0))
			continue;
		if (!(_sum2 + 50 * (100 - _step) > _best__result))
			continue;
		int _tmp0 = _find_test(_step + 1, _sum1, _sum2) - __sum2;
		if (_tmp0 > _DP_test[_step][__sum1 + 5000])
			_DP_test[_step][__sum1 + 5000] = _tmp0;
	}
	return __sum2 + _DP_test[_step][__sum1 + 5000];
}

void _solve() {
	_best__result = -5001;
	for (int _tmp0 = 0; _tmp0 < 100; _tmp0++)
		for (int _tmp1 = 0; _tmp1 < 10001; _tmp1++)
			_DP_test[_tmp0][_tmp1] = -5001;
	_find_test(0, 0, 0);
}

int main() {
	_input();
	_solve();
	_output();
	return 0;
}