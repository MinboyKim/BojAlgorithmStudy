#include <bits/stdc++.h>

using namespace std;


int main() {
	int N;
	cin >> N;
	if (N == 1 || N == 2) cout << N<<'\n';
	else cout << 2*N - 2<<'\n';
	for (int i = 1; i <= N; i++) {
		cout << i << " " << i << '\n';
		if (i != 1 && i != N) {
			cout << i << " " << N << '\n';
		}
	}
}