#include <bits/stdc++.h>

using namespace std;

long long sum;
void init() {
	int n=5;
	long long a;
	while (n--) {
		cin >> a;
		sum += a;
	}
	cout << sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	return 0;
}