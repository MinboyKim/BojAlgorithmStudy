#include <bits/stdc++.h>

using namespace std;

long long n;
long long is_one;

void solve(long long n) {
	if (n == 1) {
		cout << 1 << '\n';
		return;
	}
	int cnt = 2;
	is_one = 1;
	while (true) {
		is_one = (is_one * (10%n))%n + 1;
		is_one %= n;
		if (is_one==0) {
			cout << cnt << '\n';
			break;
		}
		cnt++;
	}
	return;
	
}

int main() {
	while (cin >> n) {       //if tc isn't given
		solve(n);
	}
	return 0;
}