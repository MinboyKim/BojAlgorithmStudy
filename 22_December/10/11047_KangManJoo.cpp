#include <bits/stdc++.h>

using namespace std;

int N,M;
int i;
int arr[11];

void solve() {
	int quote = 0;
	while (i--) {
		if (M == 0) break;
		if (arr[i] <= M) {
			quote += M / arr[i];
			M = M % arr[i];
		}
	}
	cout << quote;
	return;
}

void init() {
	cin >> N>>M;
	while (N--) {
		cin >> arr[i];
		i++;
	}
	solve();
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	return 0;
}