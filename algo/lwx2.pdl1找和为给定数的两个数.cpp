//#input
       //n of int in [1,1000];
       //k of int in [0,20000];
       //sample of (int in [0,10000])[1~n];

//#required
       //a of int in [1,n-1];
       //b of int in [a+1,n];
       //sample[a] + sample [b] = k;

//#output
       //sample[a]*sample[b];
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<set>

int n;
int k;
int sample[1000];
int a;
int b;
int _out0;

void _input() {
	std::cin >> n;
	std::cin >> k;
	for (int _tmp0 = 1; _tmp0 <= n; _tmp0++)
		std::cin >> sample[_tmp0 - 1];
}

void _output() {
	std::cout << _out0 << std::endl;
	exit(0);
}

void _solve() {
	for (a = 1; a <= 999; a++) {
		for (b = 2; b <= 1000; b++) {
			_out0 = sample[a - 1] * sample[b - 1];
			if (!(sample[a - 1] + sample[b - 1] == k))
				continue;
			_output();
		}
	}
}

int main() {
	_input();
	_solve();
	std::cout << "No Solution!" << std::endl;
	return 0;
}