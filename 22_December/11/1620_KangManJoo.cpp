#include <bits/stdc++.h>

using namespace std;

int M, N;
map<string, int> dogam;
map<int, string> dogam2;

void solve() {
	string q;
	while (N--) {
		cin >> q;
		if (dogam[q]) {
			cout << dogam[q] << '\n';
		}
		else {
			cout << dogam2[stoi(q)] << '\n';
		}
	}
}
void init() {
	cin >> M >> N;
	string name;
	int idx=1;
	while (M--) {
		cin >> name;
		dogam.insert({ name, idx });
		dogam2.insert({ idx, name });
		idx++;
	}
	solve();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	return 0;
}