#include <iostream>
#include <vector>
#include <set>

using namespace std;

int T, N, lampA, lampB;
set<int> countY;
set<int> countX;

bool is_pair() {
	if (countX.size() * countY.size() == N) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> lampA >> lampB;
			countX.insert(lampA);
			countY.insert(lampB);
		}
		if (is_pair()) cout << "BALANCED" << '\n';
		else cout << "NOT BALANCED" << '\n';
		countY.clear();
		countX.clear();

	}

	return 0;
}